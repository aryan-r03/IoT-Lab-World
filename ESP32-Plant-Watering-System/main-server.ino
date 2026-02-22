// ─────────────────────────────────────────────
//  PlantMind — ESP32 Self-Hosted Web Dashboard
//  Sensors : DS18B20 (temp) + Analog soil probe
//  Relay   : Water pump
//  LCD     : 16×2 I2C (0x27)
//  Web     : Built-in WebServer on port 80
// ─────────────────────────────────────────────

#include <WiFi.h>
#include <WebServer.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// ── WiFi ──────────────────────────────────────
const char* ssid = "Esp32-Watering-System";      // ESP hotspot name 
const char* pass = "@plant";                     // ESP hotspot password

// ── Pin map ───────────────────────────────────
#define SOIL_PIN  33
#define RELAY_PIN  2
#define TEMP_PIN  23

// ── Peripherals ───────────────────────────────
LiquidCrystal_I2C lcd(0x27, 16, 2);
OneWire           oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);
WebServer         server(80);

// ── State ─────────────────────────────────────
float g_tempC        = 0.0;
int   g_moisture     = 0;
bool  g_pumpOn       = false;
bool  g_autoMode     = true;   // auto-water when moisture < 30 %

// ── HTML page (stored in flash) ───────────────
// The browser fetches /api/data every 3 s and updates the UI without reload.
const char INDEX_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8"/>
<meta name="viewport" content="width=device-width,initial-scale=1"/>
<title>PlantMind</title>
<link href="https://fonts.googleapis.com/css2?family=Playfair+Display:ital,wght@0,700;1,400&family=DM+Mono:wght@300;400&display=swap" rel="stylesheet"/>
<style>
*,*::before,*::after{box-sizing:border-box;margin:0;padding:0}
:root{--bg:#0c110e;--card:#162019;--border:#1e2e22;--green:#4ade80;--gdim:#2d6b45;--amber:#fbbf24;--red:#f87171;--text:#d4e8d0;--muted:#5a7a62;--white:#f0f5f1}
html,body{min-height:100%;background:var(--bg);color:var(--text);font-family:'DM Mono',monospace}
body::after{content:'';position:fixed;top:-20%;left:50%;transform:translateX(-50%);width:80vw;height:60vw;background:radial-gradient(ellipse,rgba(74,222,128,.06) 0%,transparent 70%);pointer-events:none}
.app{position:relative;z-index:1;max-width:860px;margin:0 auto;padding:44px 20px 72px}
header{display:flex;align-items:flex-end;justify-content:space-between;margin-bottom:48px;flex-wrap:wrap;gap:16px}
h1{font-family:'Playfair Display',serif;font-size:clamp(26px,5vw,40px);font-weight:700;color:var(--white);letter-spacing:-1px;line-height:1}
h1 span{color:var(--green);font-style:italic}
.sub{font-size:10px;letter-spacing:3px;text-transform:uppercase;color:var(--muted);margin-top:4px}
.pill{display:flex;align-items:center;gap:8px;background:var(--card);border:1px solid var(--border);border-radius:100px;padding:7px 16px;font-size:12px;color:var(--muted)}
.dot{width:7px;height:7px;border-radius:50%;background:var(--green);box-shadow:0 0 8px var(--green);animation:pulse 2s infinite}
.dot.off{background:var(--red);box-shadow:0 0 8px var(--red);animation:none}
.grid{display:grid;grid-template-columns:1fr 1fr;gap:14px}
.card{background:var(--card);border:1px solid var(--border);border-radius:20px;padding:26px;position:relative;overflow:hidden;transition:border-color .3s,transform .3s}
.card:hover{border-color:var(--gdim);transform:translateY(-2px)}
.card::before{content:'';position:absolute;top:0;right:0;width:120px;height:120px;background:radial-gradient(circle at top right,rgba(74,222,128,.07),transparent 70%);pointer-events:none}
.span2{grid-column:1/-1}
.lbl{font-size:10px;letter-spacing:3px;text-transform:uppercase;color:var(--muted);margin-bottom:18px}
.big{font-family:'Playfair Display',serif;font-size:clamp(38px,8vw,60px);font-weight:700;color:var(--white);line-height:1;display:flex;align-items:baseline;gap:6px}
.unit{font-size:18px;color:var(--muted);font-family:'DM Mono',monospace;font-weight:300}
.badge{display:inline-flex;align-items:center;gap:5px;margin-top:12px;font-size:11px;color:var(--green);background:rgba(74,222,128,.08);border-radius:100px;padding:4px 11px}
.badge.warn{color:var(--amber);background:rgba(251,191,36,.08)}
.badge.err{color:var(--red);background:rgba(248,113,113,.08)}
.bar-wrap{margin-top:18px;height:7px;background:var(--border);border-radius:100px;overflow:hidden}
.bar-fill{height:100%;border-radius:100px;background:linear-gradient(90deg,var(--gdim),var(--green));box-shadow:0 0 10px rgba(74,222,128,.35);transition:width 1s cubic-bezier(.4,0,.2,1)}
.pump-row{display:flex;align-items:center;justify-content:space-between;flex-wrap:wrap;gap:14px}
.pump-row p{font-size:11px;color:var(--muted);margin-top:6px;max-width:340px;line-height:1.7}
.tog-wrap{display:flex;align-items:center;gap:12px}
.tog-lbl{font-size:12px;color:var(--muted)}
.track{width:64px;height:34px;border-radius:100px;background:var(--border);border:1px solid var(--border);cursor:pointer;position:relative;transition:background .3s,border-color .3s,box-shadow .3s}
.track.on{background:rgba(74,222,128,.15);border-color:var(--green);box-shadow:0 0 18px rgba(74,222,128,.2)}
.thumb{width:24px;height:24px;border-radius:50%;background:var(--muted);position:absolute;top:50%;left:4px;transform:translateY(-50%);transition:left .3s cubic-bezier(.34,1.56,.64,1),background .3s}
.track.on .thumb{left:36px;background:var(--green);box-shadow:0 0 9px rgba(74,222,128,.5)}
.auto-row{display:flex;align-items:center;gap:10px;margin-top:12px;font-size:11px;color:var(--muted)}
.log{margin-top:14px;max-height:150px;overflow-y:auto;scrollbar-width:thin;scrollbar-color:var(--border) transparent}
.log-e{display:flex;gap:14px;align-items:baseline;padding:7px 0;border-bottom:1px solid var(--border);font-size:11px}
.lt{color:var(--muted);flex-shrink:0;min-width:76px}
.lm{color:var(--text)}.lm.ok{color:var(--green)}.lm.w{color:var(--amber)}.lm.e{color:var(--red)}
footer{text-align:center;margin-top:44px;font-size:10px;color:var(--muted);letter-spacing:2px;text-transform:uppercase}
.ip-badge{font-size:11px;color:var(--muted);margin-top:3px}
@keyframes pulse{0%,100%{opacity:1;transform:scale(1)}50%{opacity:.5;transform:scale(.85)}}
@media(max-width:520px){.grid{grid-template-columns:1fr}.span2{grid-column:1}header{flex-direction:column;align-items:flex-start}}
</style>
</head>
<body>
<div class="app">
  <header>
    <div>
      <div style="font-size:24px">🌿</div>
      <h1>Plant<span>Mind</span></h1>
      <div class="sub">Smart Watering &mdash; ESP32</div>
      <div class="ip-badge" id="ipBadge"></div>
    </div>
    <div class="pill"><div class="dot" id="dot"></div><span id="connLbl">Connecting…</span></div>
  </header>

  <div class="grid">
    <!-- Temperature -->
    <div class="card">
      <div class="lbl">Temperature</div>
      <div class="big"><span id="tv">—</span><span class="unit">°C</span></div>
      <div class="badge" id="tb">Waiting…</div>
    </div>

    <!-- Moisture -->
    <div class="card">
      <div class="lbl">Soil Moisture</div>
      <div class="big"><span id="mv">—</span><span class="unit">%</span></div>
      <div class="bar-wrap"><div class="bar-fill" id="mbar" style="width:0%"></div></div>
      <div class="badge" id="mb" style="margin-top:10px">Waiting…</div>
    </div>

    <!-- Pump -->
    <div class="card span2">
      <div class="lbl">Water Pump</div>
      <div class="pump-row">
        <div>
          <div class="big" style="font-size:28px" id="pumpLbl">OFF</div>
          <p>Toggle the relay to manually control the pump. Enable Auto Mode to water automatically when moisture drops below 30%.</p>
        </div>
        <div>
          <div class="tog-wrap">
            <span class="tog-lbl" id="pumpTxt">OFF</span>
            <div class="track" id="ptrack" onclick="togglePump()"><div class="thumb"></div></div>
          </div>
          <div class="auto-row">
            <div class="track" id="atrack" style="width:48px;height:26px" onclick="toggleAuto()">
              <div class="thumb" style="width:18px;height:18px;left:3px" id="athumb"></div>
            </div>
            <span id="autoTxt">Auto: OFF</span>
          </div>
        </div>
      </div>
    </div>

    <!-- Log -->
    <div class="card span2">
      <div class="lbl">Activity Log</div>
      <div class="log" id="log"><div class="log-e"><span class="lt">—</span><span class="lm">Initialising…</span></div></div>
    </div>
  </div>

  <footer>PlantMind &bull; ESP32 Self-Hosted &bull; DS18B20 + Capacitive Soil Sensor</footer>
</div>

<script>
let pumpOn=false, autoMode=false, logs=[];

function ts(){return new Date().toLocaleTimeString('en-IN',{hour:'2-digit',minute:'2-digit',second:'2-digit'})}

function log(msg,cls=''){
  logs.unshift({t:ts(),msg,cls});
  if(logs.length>60)logs.pop();
  document.getElementById('log').innerHTML=
    logs.map(l=>`<div class="log-e"><span class="lt">${l.t}</span><span class="lm ${l.cls}">${l.msg}</span></div>`).join('');
}

function setConn(ok){
  document.getElementById('dot').className='dot'+(ok?'':' off');
  document.getElementById('connLbl').textContent=ok?'Device Online':'Offline';
}

function applyData(d){
  // temp
  document.getElementById('tv').textContent=d.temp.toFixed(1);
  const tb=document.getElementById('tb');
  if(d.temp<10){tb.className='badge err';tb.textContent='⚠ Too Cold'}
  else if(d.temp>35){tb.className='badge warn';tb.textContent='⚠ Too Warm'}
  else{tb.className='badge';tb.textContent='✓ Optimal'}

  // moisture
  document.getElementById('mv').textContent=d.moisture;
  document.getElementById('mbar').style.width=d.moisture+'%';
  const mb=document.getElementById('mb');
  if(d.moisture<20){mb.className='badge err';mb.textContent='⚠ Critically Dry'}
  else if(d.moisture<40){mb.className='badge warn';mb.textContent='⚠ Low Moisture'}
  else if(d.moisture>80){mb.className='badge warn';mb.textContent='⚠ Overwatered'}
  else{mb.className='badge';mb.textContent='✓ Moisture OK'}

  // pump
  setPumpUI(d.pump);
  setAutoUI(d.autoMode);

  if(d.ip)document.getElementById('ipBadge').textContent='http://'+d.ip;
}

function setPumpUI(on){
  pumpOn=on;
  const tr=document.getElementById('ptrack');
  tr.className='track'+(on?' on':'');
  document.getElementById('pumpLbl').textContent=on?'ON':'OFF';
  document.getElementById('pumpTxt').textContent=on?'ON':'OFF';
}

function setAutoUI(on){
  autoMode=on;
  const tr=document.getElementById('atrack');
  const th=document.getElementById('athumb');
  tr.className='track'+(on?' on':'');
  th.style.left=on?'27px':'3px';
  th.style.background=on?'var(--green)':'var(--muted)';
  document.getElementById('autoTxt').textContent='Auto: '+(on?'ON':'OFF');
}

async function togglePump(){
  const next=!pumpOn;
  try{
    await fetch('/api/pump?state='+(next?1:0));
    log('Pump manually '+(next?'ON':'OFF'),next?'w':'ok');
    setPumpUI(next);
  }catch(e){log('Pump command failed','e')}
}

async function toggleAuto(){
  const next=!autoMode;
  try{
    await fetch('/api/auto?state='+(next?1:0));
    log('Auto mode '+(next?'enabled':'disabled'),next?'ok':'');
    setAutoUI(next);
  }catch(e){log('Auto command failed','e')}
}

async function poll(){
  try{
    const r=await fetch('/api/data');
    if(!r.ok)throw new Error();
    const d=await r.json();
    applyData(d);
    setConn(true);
    log(`Temp ${d.temp.toFixed(1)}°C · Soil ${d.moisture}%`,'ok');
  }catch(e){setConn(false);log('No response from device','e')}
}

log('Dashboard ready','ok');
poll();
setInterval(poll,3000);
</script>
</body>
</html>
)=====";

// ─────────────────────────────────────────────
//  Web route handlers
// ─────────────────────────────────────────────

void handleRoot() {
  server.send_P(200, "text/html", INDEX_HTML);
}

void handleData() {
  String ip = WiFi.localIP().toString();
  String json = "{";
  json += "\"temp\":"    + String(g_tempC, 2)   + ",";
  json += "\"moisture\":" + String(g_moisture)  + ",";
  json += "\"pump\":"    + String(g_pumpOn?1:0) + ",";
  json += "\"autoMode\":" + String(g_autoMode?1:0) + ",";
  json += "\"ip\":\""    + ip + "\"";
  json += "}";

  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", json);
}

void handlePump() {
  if (server.hasArg("state")) {
    int s = server.arg("state").toInt();
    g_pumpOn = (s == 1);
    g_autoMode = false;                          // manual override disables auto
    digitalWrite(RELAY_PIN, g_pumpOn ? HIGH : LOW);
  }
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"ok\":1}");
}

void handleAuto() {
  if (server.hasArg("state")) {
    g_autoMode = (server.arg("state").toInt() == 1);
  }
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", "{\"ok\":1}");
}

void handleNotFound() {
  server.send(404, "text/plain", "Not found");
}

// ─────────────────────────────────────────────
//  LCD startup animation
// ─────────────────────────────────────────────
void showFakeLCD() {
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Loading...");
  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Temperature:");
  lcd.setCursor(0, 1); lcd.print("20 Degree C");
  delay(5000);

  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Moisture At");
  lcd.setCursor(0, 1); lcd.print("Right Level");
  delay(5000);

  lcd.clear();
}

// ─────────────────────────────────────────────
//  Auto-watering logic
// ─────────────────────────────────────────────
void autoWater() {
  if (!g_autoMode) return;
  if (g_moisture < 30 && !g_pumpOn) {
    g_pumpOn = true;
    digitalWrite(RELAY_PIN, HIGH);
  } else if (g_moisture >= 50 && g_pumpOn) {
    g_pumpOn = false;
    digitalWrite(RELAY_PIN, LOW);
  }
}

// ─────────────────────────────────────────────
//  Setup
// ─────────────────────────────────────────────
void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  lcd.init();
  lcd.backlight();
  showFakeLCD();

  tempSensor.begin();

  // Connect WiFi
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Connecting WiFi");
  WiFi.begin(ssid, pass);
  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 40) {
    delay(500);
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    String ip = WiFi.localIP().toString();
    Serial.println("IP: " + ip);

    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("WiFi OK!");
    lcd.setCursor(0, 1); lcd.print(ip);
    delay(3000);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("WiFi FAILED");
    delay(2000);
  }

  // Register routes
  server.on("/",         handleRoot);
  server.on("/api/data", handleData);
  server.on("/api/pump", handlePump);
  server.on("/api/auto", handleAuto);
  server.onNotFound(handleNotFound);
  server.begin();

  lcd.clear();
}

// ─────────────────────────────────────────────
//  Loop
// ─────────────────────────────────────────────
unsigned long lastSensor = 0;

void loop() {
  server.handleClient();           // serve web requests first

  if (millis() - lastSensor >= 1000) {
    lastSensor = millis();

    // Read sensors
    tempSensor.requestTemperatures();
    g_tempC = tempSensor.getTempCByIndex(0);

    int raw = analogRead(SOIL_PIN);
    g_moisture = map(raw, 4095, 0, 0, 100);
    g_moisture = constrain(g_moisture, 0, 100);

    autoWater();

    // Update LCD
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(g_tempC, 1);
    lcd.print((char)223);
    lcd.print("C   ");

    lcd.setCursor(0, 1);
    lcd.print("Soil: ");
    lcd.print(g_moisture);
    lcd.print("%  Pump:");
    lcd.print(g_pumpOn ? "ON " : "OFF");
  }
}
