
<h1 align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=32&pause=1000&color=00D4FF&center=true&vCenter=true&width=700&lines=ESP32+OLED+Video+Player;128%C3%9764+Binary+Playback;WiFi+Upload+%2B+LittleFS;10+fps+on+Tiny+Screen" alt="Typing SVG" />
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge&logo=espressif&logoColor=white" alt="ESP32"/>
  <img src="https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white" alt="Python"/>
  <img src="https://img.shields.io/badge/Arduino_IDE-00878F?style=for-the-badge&logo=arduino&logoColor=white" alt="Arduino IDE"/>
  <img src="https://img.shields.io/badge/OpenCV-5C3EE8?style=for-the-badge&logo=opencv&logoColor=white" alt="OpenCV"/>
  <img src="https://img.shields.io/badge/License-MIT-success?style=for-the-badge" alt="License"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Display-128×64_OLED-blue?style=flat-square" alt="Display"/>
  <img src="https://img.shields.io/badge/Playback-10_fps-orange?style=flat-square" alt="FPS"/>
  <img src="https://img.shields.io/badge/Upload-WiFi_Hotspot-brightgreen?style=flat-square" alt="WiFi"/>
  <img src="https://img.shields.io/badge/Storage-LittleFS_Flash-yellow?style=flat-square" alt="Storage"/>
</p>

---

<div align="center">

### 🎬 Play Videos on a 128×64 OLED — Wirelessly

> **Convert any video on your PC to a compact binary format, upload it wirelessly to an ESP32 via browser, and watch it loop on a 128×64 SH1106 OLED at 10 fps. No SD card. No cable re-flash. Just WiFi.**

**🔧 A deep-dive into binary video formats, LittleFS, SPI OLED rendering, and embedded web servers**

[How It Works](#-how-it-works) • [Hardware](#-hardware) • [Wiring](#-wiring) • [Usage](#-usage) • [File Format](#-file-format)

</div>

---

## 📋 Table of Contents

- [🌟 Project Overview](#-project-overview)
- [✨ Features](#-features)
- [🎬 How It Works](#-how-it-works)
- [🧰 Hardware](#-hardware)
- [🔌 Wiring](#-wiring)
- [📦 Dependencies](#-dependencies)
- [🚀 Usage](#-usage)
- [⚙️ Configuration](#%EF%B8%8F-configuration)
- [📁 File Format](#-file-format)
- [📂 Project Structure](#-project-structure)
- [💾 Flash Storage & Limits](#-flash-storage--limits)
- [🐛 Troubleshooting](#-troubleshooting)
- [🔮 Future Improvements](#-future-improvements)
- [📜 License](#-license)

---

## 🌟 Project Overview

<div align="center">
  <table>
    <tr>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/video-file.png" width="80" height="80" alt="Video"/>
        <br><b>Video Converter</b>
        <br>Python + OpenCV
        <br>Any MP4 → .bin
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/wifi.png" width="80" height="80" alt="WiFi"/>
        <br><b>WiFi Upload</b>
        <br>ESP32 AP hotspot
        <br>Browser drag & drop
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/database.png" width="80" height="80" alt="Storage"/>
        <br><b>LittleFS Flash</b>
        <br>Persistent storage
        <br>No SD card needed
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/monitor.png" width="80" height="80" alt="OLED"/>
        <br><b>OLED Playback</b>
        <br>128×64 SH1106
        <br>10 fps looping
      </td>
    </tr>
  </table>
</div>

This project pushes an ESP32 to do something unusual — **play back video** on a 128×64 monochrome OLED, entirely from onboard flash storage, with a wireless upload workflow. No computer connection needed after initial firmware flash. No SD card. Just connect to the ESP32's hotspot, upload your converted video from any browser, and it plays immediately.

### 🎯 What Makes This Project Interesting

<table>
<tr>
<td width="50%">

**Novel Concepts:**
- 📦 Custom binary video format (no header, raw 1-bit frames)
- 📡 ESP32 as a WiFi Access Point + web server simultaneously
- 💾 LittleFS for persistent flash file storage
- 🖥️ SPI OLED driven at near-max frame rate
- 🐍 Python + OpenCV video-to-binary pipeline

</td>
<td width="50%">

**Engineering Constraints:**
- 1.5 MB usable flash → ~1500 frames max
- 1024 bytes per frame (128×64 ÷ 8)
- 10 fps playback = 100ms frame delay
- 1-bit monochrome (no greyscale, no color)
- SPI throughput limits display update speed

</td>
</tr>
</table>

---

## ✨ Features

<table>
  <tr>
    <th>Category</th>
    <th>Features</th>
  </tr>
  <tr>
    <td><b>🐍 Python Converter</b></td>
    <td>
      ✅ Reads any MP4 (or video format OpenCV supports)<br>
      ✅ Resizes every frame to exactly 128×64<br>
      ✅ Converts to 1-bit monochrome (grayscale → threshold)<br>
      ✅ Packs 8 pixels per byte, LSB-first<br>
      ✅ Outputs flat binary <code>video.bin</code> — no header overhead<br>
      ✅ Configurable fps parameter
    </td>
  </tr>
  <tr>
    <td><b>📡 WiFi Upload Interface</b></td>
    <td>
      ✅ ESP32 creates its own WiFi hotspot (AP mode)<br>
      ✅ Default SSID: <code>ESP32-OLED</code> / Password: <code>12345678</code><br>
      ✅ Web upload page at <code>http://192.168.4.1</code><br>
      ✅ Works from phone or laptop browser<br>
      ✅ OLED shows "Uploading..." during transfer<br>
      ✅ Playback begins immediately on upload complete
    </td>
  </tr>
  <tr>
    <td><b>💾 Storage</b></td>
    <td>
      ✅ LittleFS filesystem on ESP32 flash<br>
      ✅ Video persists across power cycles<br>
      ✅ No SD card required<br>
      ✅ Auto-resumes last video on power-on<br>
      ✅ Overwritten cleanly on new upload<br>
      ✅ ~1.5 MB usable space
    </td>
  </tr>
  <tr>
    <td><b>🎬 Playback</b></td>
    <td>
      ✅ SH1106 128×64 OLED via SPI (U8g2 library)<br>
      ✅ 10 fps default (configurable)<br>
      ✅ Continuous loop playback<br>
      ✅ Frame-accurate binary read from flash<br>
      ✅ 1024 bytes per frame read sequentially<br>
      ✅ No buffering lag — direct flash-to-display
    </td>
  </tr>
</table>

---

## 🎬 How It Works

<div align="center">

### End-to-End Pipeline

```
┌──────────────────────────────────────────────────────┐
│                STEP 1 — PC CONVERSION                │
│                                                      │
│  video.mp4  ──►  image-convertor.py  ──►  video.bin  │
│                                                      │
│  For each frame:                                     │
│    1. Read frame with OpenCV (cv2.VideoCapture)      │
│    2. Resize → 128 × 64 pixels                       │
│    3. Convert to grayscale (cv2.cvtColor GRAY)       │
│    4. Threshold → pure black/white (cv2.threshold)   │
│    5. Pack 8 pixels per byte, LSB-first              │
│    6. Write 1024 bytes to video.bin                  │
│                                                      │
│  Output: flat binary,no header,frames back-to-back   │
└──────────────────────────────────────────────────────┘
│
(video.bin)
▼
┌────────────────────────────────────────────────────────────┐
│                  STEP 2 — WIRELESS UPLOAD                  │
│                                                            │
│  Phone/Laptop                    ESP32 (AP Mode)           │
│  ┌──────────────┐                ┌──────────────────────┐  │
│  │ Connect WiFi │◄──────────────►│ SSID: ESP32-OLED     │  │
│  │ ESP32-OLED   │                │ Pass: 12345678       │  │
│  └──────┬───────┘                │ IP:   192.168.4.1    │  │
│         │                        └──────────┬───────────┘  │
│         │ http://192.168.4.1                │              │
│         ▼                                   │              │
│  ┌──────────────┐   POST /upload            │              │
│  │  Upload Page │─────────────────────────► │              │
│  │  Select .bin │   multipart/form-data     │              │
│  └──────────────┘                           │              │
│                                             ▼              │
│                                  ┌─────────────────────┐   │
│                                  │  WebServer handler  │   │
│                                  │  Write to LittleFS  │   │
│                                  │  /video.bin         │   │
│                                  └─────────────────────┘   │
└────────────────────────────────────────────────────────────┘
│
(stored in flash)
▼
┌──────────────────────────────────────────────────────┐
│                    STEP 3 — OLED PLAYBACK            │
│                                                      │
│     loop():                                          │
│    ┌────────────────────────────────────────────┐    │
│    │  Open /video.bin from LittleFS             │    │
│    │         │                                  │    │
│    │         ▼                                  │    │
│    │  Read 1024 bytes (1 frame)                 │    │
│    │         │                                  │    │
│    │         ▼                                  │    │
│    │  Unpack bits → 128×64 pixel bitmap         │    │
│    │         │                                  │    │
│    │         ▼                                  │    │
│    │  u8g2.drawXBM() → push to SH1106 via SPI   │    │
│    │         │                                  │    │
│    │         ▼                                  │    │
│    │  delay(FRAME_DELAY)  ← 100ms = 10fps       │    │
│    │         │                                  │    │
│    │         └──── repeat until EOF ────────────┘    │
│    │                       │                         │
│    └───────── seek(0) ─────┘ ← loop back to frame-1  │
└──────────────────────────────────────────────────────┘
```

### Pixel Packing — How 1024 Bytes Holds a 128×64 Frame

```
128 pixels wide × 64 pixels tall = 8,192 pixels total

Each pixel = 1 bit (0 = black, 1 = white)

8,192 bits ÷ 8 bits/byte = 1,024 bytes per frame ✓

Byte layout (LSB-first, row by row):

Row 0:   [px7 px6 px5 px4 px3 px2 px1 px0] [px15 ... px8] ... × 16 bytes
Row 1:   [px7 px6 px5 px4 px3 px2 px1 px0] ...
...
Row 63:  ...                                               = 1024 bytes total
```

</div>

---

## 🧰 Hardware

<table>
  <tr>
    <th>#</th>
    <th>Component</th>
    <th>Detail</th>
    <th>Qty</th>
    <th>Notes</th>
  </tr>
  <tr>
    <td>1</td>
    <td><b>ESP32 Dev Board</b></td>
    <td>ESP32-WROOM-32 / DevKit v1</td>
    <td>1</td>
    <td>Any standard ESP32 devkit works</td>
  </tr>
  <tr>
    <td>2</td>
    <td><b>OLED Display</b></td>
    <td>SH1106 128×64, SPI interface</td>
    <td>1</td>
    <td>Must be SH1106, not SSD1306 (different driver)</td>
  </tr>
  <tr>
    <td>3</td>
    <td><b>Jumper Wires</b></td>
    <td>Male-to-Female</td>
    <td>~7</td>
    <td>For SPI connections</td>
  </tr>
  <tr>
    <td>4</td>
    <td><b>USB Cable</b></td>
    <td>Micro-USB, data capable</td>
    <td>1</td>
    <td>For initial firmware upload only</td>
  </tr>
</table>

> 💡 **SH1106 vs SSD1306:** Both look identical physically but use different internal addressing. The SH1106 has a 132-column internal buffer (only 128 visible). U8g2 handles this automatically if you select the correct constructor.

---

## 🔌 Wiring

<div align="center">

### SPI Connection — ESP32 ↔ SH1106 OLED

```
        ESP32                    SH1106 OLED
   ┌─────────────┐           ┌───────────────┐
   │             │           │               │
   │   GPIO 5 ───┼──── CS ───┤ CS  (Chip Sel)│
   │   GPIO 4 ───┼──── DC ───┤ DC  (Data/Cmd)│
   │   GPIO 2 ───┼──── RST ──┤ RST (Reset)   │
   │   GPIO 18 ──┼──── SCK ──┤ CLK (SPI Clk) │
   │   GPIO 23 ──┼──── SDA ──┤ SDA (MOSI)    │
   │   3.3V ─────┼──── VCC ──┤ VCC           │
   │   GND ──────┼──── GND ──┤ GND           │
   └─────────────┘           └───────────────┘
```

</div>

### Pin Reference Table

<table>
  <tr>
    <th>OLED Pin</th>
    <th>ESP32 GPIO</th>
    <th>SPI Role</th>
    <th>Notes</th>
  </tr>
  <tr>
    <td><b>CS</b></td>
    <td>GPIO 5</td>
    <td>Chip Select (SS)</td>
    <td>Active LOW — selects this SPI device</td>
  </tr>
  <tr>
    <td><b>DC</b></td>
    <td>GPIO 4</td>
    <td>Data / Command</td>
    <td>HIGH = data, LOW = command byte</td>
  </tr>
  <tr>
    <td><b>RST</b></td>
    <td>GPIO 2</td>
    <td>Reset</td>
    <td>Pulled LOW briefly on init to reset display</td>
  </tr>
  <tr>
    <td><b>CLK / SCK</b></td>
    <td>GPIO 18</td>
    <td>SPI Clock</td>
    <td>Hardware SPI clock pin on ESP32</td>
  </tr>
  <tr>
    <td><b>SDA / MOSI</b></td>
    <td>GPIO 23</td>
    <td>Master Out Slave In</td>
    <td>Hardware SPI MOSI pin on ESP32</td>
  </tr>
  <tr>
    <td><b>VCC</b></td>
    <td>3.3V</td>
    <td>Power</td>
    <td>SH1106 runs on 3.3V — do not use 5V</td>
  </tr>
  <tr>
    <td><b>GND</b></td>
    <td>GND</td>
    <td>Ground</td>
    <td>Common ground with ESP32</td>
  </tr>
</table>

> ⚠️ **SH1106 is a 3.3V device.** Do not connect VCC to the ESP32's 5V/VIN pin — it may damage the display module.

---

## 📦 Dependencies

<div align="center">

### Arduino (ESP32 Core)

</div>

| Library | Source | Purpose |
|---------|--------|---------|
| **U8g2** | Arduino Library Manager | SH1106 OLED driver — supports SPI hardware mode |
| **WiFi.h** | Built-in (ESP32 core) | WiFi Access Point mode |
| **WebServer.h** | Built-in (ESP32 core) | HTTP server for upload page |
| **LittleFS.h** | Built-in (ESP32 core) | Flash filesystem for video storage |

**Install U8g2:**
- Open Arduino IDE → **Sketch → Include Library → Manage Libraries**
- Search **"U8g2"** → Install by *Oliver Kraus*

<div align="center">

### Python

</div>

| Package | Install | Purpose |
|---------|---------|---------|
| **Python 3** | [python.org](https://www.python.org/downloads/) | Runtime |
| **OpenCV** | `pip install opencv-python` | Video decode, resize, threshold |

```bash
pip install opencv-python
```

---

## 🚀 Usage

<div align="center">

### Step 1️⃣ — Convert Your Video

</div>

Place your video in the same folder as `image-convertor.py`, naming it `video.mp4` (or edit the filename constant at the bottom of the script):

```bash
python image-convertor.py
```

Output: **`video.bin`** — a flat binary file, one 1024-byte frame after another.

**What the converter does internally:**

```python
import cv2, numpy as np

cap = cv2.VideoCapture("video.mp4")
out = open("video.bin", "wb")

while True:
    ret, frame = cap.read()
    if not ret:
        break
    
    frame = cv2.resize(frame, (128, 64))           # Resize to display resolution
    gray  = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) # Strip colour → grayscale
    _, bw = cv2.threshold(gray, 128, 255,           # Threshold → pure 1-bit
                          cv2.THRESH_BINARY)
    
    # Pack 8 pixels per byte, LSB-first
    packed = np.packbits(bw.flatten() // 255, bitorder='little')
    out.write(packed.tobytes())                     # Write 1024 bytes

cap.release()
out.close()
```

> 💡 **Keep videos short.** ESP32 flash holds ~1500 frames — about 2.5 minutes at 10 fps. For longer clips, reduce fps or trim the video first.

<div align="center">

### Step 2️⃣ — Flash the ESP32 Firmware

</div>

1. Open `sketch_main.ino` in **Arduino IDE**
2. Select **Tools → Board → ESP32 Dev Module**
3. Select the correct **Port** (`COMx` / `/dev/ttyUSB0`)
4. Click **Upload** (hold BOOT button if needed)
5. Once uploaded, open **Serial Monitor** at **115200 baud** to confirm startup

Expected Serial Monitor output:
```
LittleFS mounted.
WiFi AP started: ESP32-OLED
Web server running at http://192.168.4.1
Waiting for upload...
```

<div align="center">

### Step 3️⃣ — Connect to the ESP32 Hotspot

</div>

On your phone or laptop:

| Setting | Value |
|---------|-------|
| **WiFi SSID** | `YOUR-WIFI-NAME` |       
| **Password** | `YOUR-WIFI-PASSWORD` |
| **Upload URL** | `http://192.168.4.1` |

```
\\ PREFER 4G WIFI SETUP, AS ESP32 DOES NOT WORKS FINE WITH 5G NETWORK
```
> ⚠️ Your device will show "No internet" — that's expected. The ESP32 is a local AP, not a router.

<div align="center">

### Step 4️⃣ — Upload & Play

</div>

1. Open a browser → navigate to **`http://192.168.4.1`**
2. The upload page loads (served by the ESP32)
3. Select your `video.bin` file
4. Tap / click **"Upload & Play"**

During upload:
- OLED shows **"Uploading..."**
- Serial Monitor shows transfer progress

After upload completes:
- Playback starts **immediately** on the OLED
- Video **loops automatically**
- On next power-on, the video **resumes without re-uploading**

---

## ⚙️ Configuration

These constants at the top of `sketch_main.ino` control all key behaviour:

```cpp
// WiFi Hotspot
const char* WIFI_NAME = "YOUR-WIFI-NAME";   // AP SSID
const char* WIFI_PASS = "YOU-WIFI-PASSWORD";     // AP password (min 8 chars)

// Playback
const int FRAME_DELAY = 100;            // ms between frames (100 = 10 fps)
```

<table>
  <tr>
    <th>Constant</th>
    <th>Default</th>
    <th>Description</th>
    <th>Notes</th>
  </tr>
  <tr>
    <td><code>WIFI_NAME</code></td> 
    <td><code>ESP32-OLED-(example)</code></td>
    <td>Hotspot SSID visible on WiFi scan</td>
    <td>Max 32 characters</td>
  </tr>
  <tr>
    <td><code>WIFI_PASS</code></td>
    <td><code>12345678-(example)</code></td>
    <td>Hotspot WPA2 password</td>
    <td>Minimum 8 characters required</td>
  </tr>
  <tr>
    <td><code>FRAME_DELAY</code></td>
    <td><code>100</code> ms</td>
    <td>Delay between frames</td>
    <td>Lower = faster playback</td>
  </tr>
</table>

### FPS Quick Reference

| `FRAME_DELAY` | Effective FPS | ~Max Video Length (1500 frames) |
|--------------|--------------|--------------------------------|
| `200` ms | 5 fps | ~5 min |
| `100` ms | 10 fps | ~2.5 min |
| `67` ms | 15 fps | ~1.7 min |
| `50` ms | 20 fps | ~1.25 min |

> ⚠️ **Match fps in both places:** if you change `FRAME_DELAY`, also update the `fps` parameter in the Python converter so the video plays at the correct speed.

---

## 📁 File Format

`video.bin` is a **headerless flat binary** file. There is no metadata, no compression, no container format.

```
video.bin layout:
┌─────────────────────────┐
│  Frame 0  — 1024 bytes  │
├─────────────────────────┤
│  Frame 1  — 1024 bytes  │
├─────────────────────────┤
│  Frame 2  — 1024 bytes  │
├─────────────────────────┤
│  ...                    │
├─────────────────────────┤
│  Frame N  — 1024 bytes  │
└─────────────────────────┘

Total file size = N frames × 1024 bytes

Frame count = file size ÷ 1024  (no header needed)
```

### Frame Encoding

```
Each frame = 128 × 64 = 8192 pixels → 1024 bytes

Pixel order: row by row, left to right
Bit order:   LSB-first within each byte

Byte 0 covers pixels: [0,1,2,3,4,5,6,7]   (row 0, cols 0–7)
Byte 1 covers pixels: [8,9,10,11,12,13,14,15]  (row 0, cols 8–15)
...
Byte 15 covers pixels: [120–127]           (row 0, cols 120–127)
Byte 16 starts row 1 ...

Bit value:  0 = black pixel
            1 = white pixel
```

**Why no header?** The frame count is implicit — the ESP32 simply reads 1024-byte chunks until EOF, then seeks back to byte 0 to loop. This keeps the format trivially simple and the ESP32 code minimal.

---

## 📂 Project Structure

```
ESP32-OLED-VideoPlayer/
│
├── 📄 sketch_main.ino          # ESP32 Arduino firmware
│   ├── WiFi AP setup
│   ├── LittleFS mount + file read
│   ├── WebServer upload handler
│   └── Frame-by-frame OLED playback loop
│
├── 🐍 image-convertor.py   (binary image)       # PC-side video converter
│   ├── OpenCV video decode
│   ├── Resize → 128×64
│   ├── Grayscale + threshold
│   └── LSB-first bit packing → video.bin
│ 
├── 🐍 image-convertor.py  (Floyd - Steinberg)   # PC-side video converter      
│   ├── OpenCV video decode
│   ├── Resize → 128×64
│   ├── Grayscale + threshold
│   └── LSB-first bit packing → video.bin
│ 
├── 📦 video.bin                                 # Generated binary (after conversion)
│   └── Flat binary, 1024 bytes/frame, no header
│
└── 📖 README.md                                 # This documentation
```

---

## 💾 Flash Storage & Limits

```
ESP32 total flash:     4 MB (typical)
Firmware partition:   ~1.5 MB
LittleFS partition:   ~1.5 MB  ← video stored here
OTA/other:            remainder

Usable video storage: ~1,500,000 bytes

Bytes per frame:       1,024
Max frames:           ~1,464 frames

At 10 fps:            ~146 seconds  (~2.5 minutes)
At 5 fps:             ~293 seconds  (~4.9 minutes)
```

**Tips to maximise storage:**
- Trim video to only what you need before converting
- Lower fps (raise `FRAME_DELAY`) to fit more wall-clock time in the same number of frames
- Keep the original footage short — the converter extracts every frame at the source video's native fps before writing to `.bin`

---

## 🐛 Troubleshooting

<details>
<summary><b>❌ OLED shows nothing / all white / all black</b></summary>

**Solutions:**
1. Double-check all 7 SPI wires — CS, DC, RST, CLK, MOSI, VCC (3.3V), GND
2. Confirm you are using **SH1106**, not SSD1306 (the U8g2 constructor differs)
3. Verify VCC is connected to **3.3V**, not 5V
4. Try swapping CS and DC pins if screen shows scrambled output
5. Check Serial Monitor for U8g2 init errors

</details>

<details>
<summary><b>❌ WiFi hotspot "ESP32-OLED" doesn't appear</b></summary>

**Solutions:**
1. Hold the **EN/Reset** button to restart the ESP32
2. Open Serial Monitor at **115200 baud** — confirm "WiFi AP started"
3. Reflash the firmware — LittleFS partition may need formatting
4. Ensure `WIFI_PASS` is at least 8 characters (WPA2 requirement)

</details>

<details>
<summary><b>❌ Upload fails or browser shows error</b></summary>

**Solutions:**
1. Confirm you navigated to `http://192.168.4.1` — not `https://`
2. File must be a valid `.bin` produced by the converter (not a raw video)
3. Check `video.bin` file size is a multiple of 1024 — if not, the converter had an error
4. Check Serial Monitor for LittleFS write errors (flash may be full)
5. Try a different browser — some mobile browsers interfere with file uploads

</details>

<details>
<summary><b>❌ Video plays at wrong speed</b></summary>

**Solutions:**
1. Ensure `FRAME_DELAY` in the sketch matches the target fps
2. The Python converter extracts frames at the **source video's fps** — a 30fps source video will produce 3× as many frames as needed for 10fps playback
3. Add `fps` sampling in the converter to only extract every Nth frame:
   ```python
   SOURCE_FPS = cap.get(cv2.CAP_PROP_FPS)   # e.g. 30
   TARGET_FPS = 10
   KEEP_EVERY = int(SOURCE_FPS / TARGET_FPS) # keep every 3rd frame
   
   frame_count = 0
   while True:
       ret, frame = cap.read()
       if not ret: break
       if frame_count % KEEP_EVERY == 0:
           # ... convert and write frame
       frame_count += 1
   ```

</details>

<details>
<summary><b>❌ "LittleFS mount failed" in Serial Monitor</b></summary>

**Solutions:**
1. In `setup()`, use `LittleFS.begin(true)` — the `true` argument **formats** on first use:
   ```cpp
   if (!LittleFS.begin(true)) {
       Serial.println("LittleFS mount failed!");
   }
   ```
2. Ensure the correct LittleFS partition scheme is selected:
   - Arduino IDE → **Tools → Partition Scheme → Default 4MB with spiffs** (or "Huge App")
3. After changing partition scheme, you must re-upload the firmware

</details>

---

## 🔮 Future Improvements

<table>
  <tr>
    <th>Enhancement</th>
    <th>Description</th>
    <th>Status</th>
  </tr>
  <tr>
    <td><b>🎞️ Dithering</b></td>
    <td>Floyd-Steinberg dithering in converter for smoother grayscale appearance</td>
    <td>🔄 Planned</td>
  </tr>
  <tr>
    <td><b>▶️ Playback Controls</b></td>
    <td>Web interface with pause, seek, and speed controls</td>
    <td>🔄 Planned</td>
  </tr>
  <tr>
    <td><b>📁 Multi-Video Library</b></td>
    <td>Store and select between multiple .bin files on flash</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>🔊 Audio Sync</b></td>
    <td>Buzzer or I2S audio playback synced to video frames</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>📡 SD Card Support</b></td>
    <td>Optional SD card for larger/longer videos</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>🗜️ RLE Compression</b></td>
    <td>Simple run-length encoding to store more frames in flash</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>🌐 SSD1306 Support</b></td>
    <td>Alternative driver path for the more common SSD1306 OLED</td>
    <td>📋 Idea</td>
  </tr>
</table>

---

## 📜 License

<div align="center">

This project is licensed under the **MIT License**

Free to use, modify, and distribute with attribution.

</div>

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:00D4FF,100:E7352C&height=100&section=footer" alt="Footer"/>

<br>

<i>🎬 "Fit a movie theatre in your pocket — one bit at a time."</i>

<br><br>

**Made with ⚡ for tinkerers who push hardware to its limits**

<br>

---

**© 2025 | ESP32 OLED Video Player | MIT License**

<br>

⭐ If this project impressed you, please **star the repo**!

<br>

</div>
