#include <U8g2lib.h>
#include <WiFi.h>
#include <WebServer.h>
#include <LittleFS.h>

U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI u8g2(
  U8G2_R2, /* cs=*/ 5, /* dc=*/ 4, /* reset=*/ 2
);

const char* WIFI_NAME = "ESP32-OLED";      // 4G-connectivity WiFi - Choose the WiFI name and pasword accordingly
const char* WIFI_PASS = "12345678";        // ESP is hosting the Hot-Spot, with these credentials 

WebServer server(80);

#define FRAME_SIZE  1024   
        // 128x64 {screen size} / 8 bytes {packet size}

#define FRAME_DELAY 100    
        // 90ms = 9-fps  {frame delay}

uint8_t  frameBuf[FRAME_SIZE];
uint32_t totalFrames  = 0;
uint32_t currentFrame = 0;
bool     isPlaying    = false;
bool     uploadDone   = false;   // flag for upload response
unsigned long lastFrameTime = 0;
File     videoFile;

//  Web-server on phone
const char uploadPage[] PROGMEM = R"(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body  { font-family:Arial; text-align:center; padding:30px; background:#111; color:#fff; }
    h2    { color:#0f0; }
    .box  { background:#222; padding:20px; border-radius:12px; margin:20px auto; max-width:400px; }
    input[type=file]   { width:90%; padding:10px; margin:10px 0; }
    input[type=submit] { width:90%; padding:14px; background:#0a0; color:#fff;
                         border:none; border-radius:8px; font-size:16px; cursor:pointer; }
    .info { font-size:12px; color:#aaa; margin-top:10px; }
  </style>
</head>
<body>
  <h2>~ OLED Video Player</h2>
  <div class="box">
    <p>Upload your converted <b>video.bin</b> file</p>
    <form method="POST" action="/upload" enctype="multipart/form-data">
      <input type="file" name="video" accept=".bin"><br>
      <input type="submit" value=" --> Upload ">
    </form>
    <p class="info">Max size depends on ESP32 flash (~1.5MB = ~1500 frames)</p>
  </div>
</body>
</html>
)";

// Handling uploaded video , on the web-server 
void handleRoot() {
  server.send(200, "text/html", uploadPage);
}
// File callback — only writes file, no server.send() here
void handleUploadCallback() {
  HTTPUpload& upload = server.upload();

  if (upload.status == UPLOAD_FILE_START) {
    isPlaying  = false;
    uploadDone = false;
    if (videoFile) videoFile.close();
    LittleFS.remove("/video.bin");
    videoFile = LittleFS.open("/video.bin", "w");

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(10, 35, "Uploading...");
    u8g2.sendBuffer();

  } else if (upload.status == UPLOAD_FILE_WRITE) {
    if (videoFile) videoFile.write(upload.buf, upload.currentSize);

  } else if (upload.status == UPLOAD_FILE_END) {
    if (videoFile) {
      videoFile.close();
      totalFrames  = upload.totalSize / FRAME_SIZE;
      currentFrame = 0;
      videoFile    = LittleFS.open("/video.bin", "r");
      isPlaying    = true;
    }
    uploadDone = true;
  }
}

// Main handler — sends response after upload finishes
void handleUploadResponse() {
  if (uploadDone) {
    server.send(200, "text/html",
      "<html><body style='background:#111;color:#0f0;text-align:center;padding:40px'>"
      "<h2> Upload Done!</h2><p>Playing on OLED...</p>"
      "<a href='/' style='color:#fff'>⬅ Back</a></body></html>");
    uploadDone = false;
  } else {
    server.send(500, "text/plain", "Upload failed, try again.");
  }
}

//  WiFi info on OLED { prefer to avoid this }
void showWifiInfo() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB06_tr);
  u8g2.drawStr(0, 8, "    OLED-MONO-TV   ");
  u8g2.drawStr(0, 16, "--------------------");
  u8g2.drawStr(0, 26, "Connect to WiFi:");
  u8g2.drawStr(0, 34, WIFI_NAME);
  u8g2.drawStr(0, 42, "Then open browser:");
  u8g2.drawStr(0, 50, "192.168.4.1");
  u8g2.sendBuffer();
}

void setup() {
  Serial.begin(115200);
  u8g2.begin();
  u8g2.setFlipMode(1);

  // FIX 1: WiFi starts FIRST — hotspot always comes up even if LittleFS fails
  WiFi.softAP(WIFI_NAME, WIFI_PASS);
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());

  // FIX 2: Correct upload handler — response and file callback separated
  server.on("/", handleRoot);
  server.on("/upload", HTTP_POST, handleUploadResponse, handleUploadCallback);
  server.begin();

  //  filesystem
  if (!LittleFS.begin(true)) {
    u8g2.clearBuffer();
    u8g2.drawStr(0, 32, "FS Error!");
    u8g2.sendBuffer();
    return;
  }

  // If a video already exists from last time, play it
  if (LittleFS.exists("/video.bin")) {
    videoFile   = LittleFS.open("/video.bin", "r");
    totalFrames = LittleFS.open("/video.bin", "r").size() / FRAME_SIZE;
    isPlaying   = true;
  } else {
    showWifiInfo();
  }
}

void loop() {
  server.handleClient();       // Handle phone connections

  if (isPlaying && totalFrames > 0 && videoFile) {
    if (millis() - lastFrameTime >= FRAME_DELAY) {
      lastFrameTime = millis();

      videoFile.read(frameBuf, FRAME_SIZE);

      u8g2.clearBuffer();
      u8g2.drawXBMP(0, 0, 128, 64, frameBuf);
      u8g2.sendBuffer();

      currentFrame++;
      if (currentFrame >= totalFrames) {
        currentFrame = 0;
        videoFile.seek(0);      // Loop back to start
      }
    }
  }
}
