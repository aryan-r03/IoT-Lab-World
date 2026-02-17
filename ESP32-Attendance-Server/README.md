<h1 align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=32&pause=1000&color=00D4FF&center=true&vCenter=true&width=700&lines=IoT+RFID+Attendance+System;ESP32+%2B+Python+Flask;Real-Time+Excel+Logging;Smart+Automation+Project" alt="Typing SVG" />
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge&logo=espressif&logoColor=white" alt="ESP32"/>
  <img src="https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white" alt="Python"/>
  <img src="https://img.shields.io/badge/Flask-000000?style=for-the-badge&logo=flask&logoColor=white" alt="Flask"/>
  <img src="https://img.shields.io/badge/Arduino_IDE-00878F?style=for-the-badge&logo=arduino&logoColor=white" alt="Arduino IDE"/>
  <img src="https://img.shields.io/badge/Excel-217346?style=for-the-badge&logo=microsoftexcel&logoColor=white" alt="Excel"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Hardware-ESP32%20%2B%20RC522-orange?style=flat-square" alt="Hardware"/>
  <img src="https://img.shields.io/badge/Communication-WiFi%20%2F%20HTTP-blue?style=flat-square" alt="WiFi"/>
  <img src="https://img.shields.io/badge/Output-Excel%20Logging-brightgreen?style=flat-square" alt="Excel"/>
  <img src="https://img.shields.io/badge/Level-Beginner%20Friendly-success?style=flat-square" alt="Level"/>
</p>

---

<div align="center">

### 📡 Smart IoT Attendance Tracking — Tap. Log. Done.

> **Fully automated attendance system using RFID card scanning on ESP32, wirelessly transmitting to a Python Flask server, and recording student details with real-time date & time directly into an Excel file.**

**🎓 Built for academic demonstration and college project submission**

[Features](#-features) • [Hardware](#-hardware-components) • [Wiring](#-wiring-diagrams) • [How to Run](#-how-to-run) • [Working Principle](#-working-principle)

</div>

---

## 📋 Table of Contents

- [🌟 Project Overview](#-project-overview)
- [✨ Features](#-features)
- [🎬 System Flow](#-system-flow)
- [🧰 Hardware Components](#-hardware-components)
- [💻 Software & Tools](#-software--tools)
- [🔌 Wiring Diagrams](#-wiring-diagrams)
- [📂 Project Structure](#-project-structure)
- [⚙️ How to Run](#%EF%B8%8F-how-to-run)
- [🔧 Working Principle](#-working-principle)
- [👨‍🎓 Student Mapping](#-student-mapping)
- [📊 Sample Output](#-sample-output)
- [🖼️ Project Pictures](#%EF%B8%8F-project-pictures)
- [🐛 Troubleshooting](#-troubleshooting)
- [🚀 Future Improvements](#-future-improvements)
- [📜 License](#-license)

---

## 🌟 Project Overview

<div align="center">
  <table>
    <tr>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/rfid-signal.png" width="80" height="80" alt="RFID"/>
        <br><b>RFID Scanning</b>
        <br>RC522 module
        <br>UID detection
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/wifi.png" width="80" height="80" alt="WiFi"/>
        <br><b>WiFi Transfer</b>
        <br>ESP32 HTTP POST
        <br>Real-time sync
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/nolan/96/flask.png" width="80" height="80" alt="Flask"/>
        <br><b>Flask Server</b>
        <br>UID → Name mapping
        <br>Attendance logic
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/ms-excel.png" width="80" height="80" alt="Excel"/>
        <br><b>Excel Logging</b>
        <br>Auto date & time
        <br>Persistent records
      </td>
    </tr>
  </table>
</div>

This project bridges **embedded hardware** and **web server software** to build a complete, end-to-end automated attendance system. A student taps their RFID card, the ESP32 reads the UID and posts it to a local Flask server over WiFi, the server maps it to a student record, and saves it instantly to an Excel file — all with no manual input.

### 🎯 What Makes This Project Special

<table>
<tr>
<td width="50%">

**Hardware Side:**
- ⚡ Real RFID card scanning (RC522)
- 📟 Live feedback on I2C LCD display
- 🔔 Buzzer confirmation on scan
- 📡 ESP32 WiFi data transmission
- 🔌 Complete hardware integration

</td>
<td width="50%">

**Software Side:**
- 🐍 Python Flask REST endpoint
- 📊 Auto Excel file creation (openpyxl)
- 🕐 Real-time timestamp logging
- 🗂️ UID-to-student name mapping
- 💾 Persistent `.xlsx` attendance records

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
    <td><b>📡 Hardware</b></td>
    <td>
      ✅ RFID card/tag scanning via RC522<br>
      ✅ ESP32 WiFi communication<br>
      ✅ 16x2 I2C LCD status display<br>
      ✅ Buzzer audio confirmation<br>
      ✅ SPI + I2C simultaneous bus use<br>
      ✅ 3.3V / 5V mixed power handling
    </td>
  </tr>
  <tr>
    <td><b>🐍 Server</b></td>
    <td>
      ✅ Python Flask HTTP POST receiver<br>
      ✅ UID → student name & department mapping<br>
      ✅ Auto-generated date & time stamps<br>
      ✅ Excel file created on first run<br>
      ✅ Rows appended (never overwritten)<br>
      ✅ Formatted .xlsx with headers
    </td>
  </tr>
  <tr>
    <td><b>📊 Output</b></td>
    <td>
      ✅ SNO, Name, Department columns<br>
      ✅ Date (YYYY-MM-DD) column<br>
      ✅ Time (HH:MM:SS) column<br>
      ✅ Human-readable Excel format<br>
      ✅ Compatible with MS Excel & Google Sheets<br>
      ✅ Persistent across server restarts
    </td>
  </tr>
  <tr>
    <td><b>🔧 Developer Experience</b></td>
    <td>
      ✅ Serial Monitor output for debugging<br>
      ✅ LCD feedback for user confirmation<br>
      ✅ Easy UID-to-name table in server code<br>
      ✅ Single IP address config change needed<br>
      ✅ Minimal dependencies (2 pip packages)<br>
      ✅ Clean, beginner-friendly code
    </td>
  </tr>
</table>

---

## 🎬 System Flow

<div align="center">

### End-to-End Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                    HARDWARE LAYER                           │
│                                                             │
│   [RFID Card]                                               │
│       │  tap                                                │
│       ▼                                                     │
│   [RC522 RFID Module] ─── SPI ───► [ESP32]                  │
│                                      │                      │
│                          ┌───────────┼───────────┐          │
│                          ▼           ▼           ▼          │
│                       [LCD]      [Buzzer]    [WiFi]         │
│                    "Attendance    *BEEP*     Send UID       │
│                     Marked!"                to Server       │
└──────────────────────────────┬──────────────────────────────┘
│

HTTP POST /attend
Body: { "uid": "A3B2C1D0" }

│
▼
┌─────────────────────────────────────────────────────────────┐
│                  SOFTWARE LAYER (PC / Server)               │
│                                                             │
│   [Python Flask Server]  ← http://<PC_IP>:5000              │
│       │                                                     │
│       ├─ Receive UID                                        │
│       ├─ Lookup in student dictionary                       │
│       │      "A3B2C1D0" → Aryan Ranjan, CS, SNO 4           │
│       ├─ Get current datetime.now()                         │
│       └─ Append row to attendance.xlsx                      │
│                                                             │
│   [attendance.xlsx]                                         │
│   ┌─────┬──────────────┬────────────┬────────────┬────────┐ │
│   │ SNO │ NAME         │ DEPARTMENT │ DATE       │ TIME   │ │
│   ├─────┼──────────────┼────────────┼────────────┼────────┤ │
│   │  01 │ Aryan Ranjan │ CS         │ 2026-01-21 │ 08:30  │ │
│   └─────┴──────────────┴────────────┴────────────┴────────┘ │
└─────────────────────────────────────────────────────────────┘
```

### Timing Sequence

<div align="center">
<table>
  <tr>
    <th>#</th>
    <th>Timestamp</th>
    <th>Component</th>
    <th>Action</th>
  </tr>
  <tr>
    <td>1</td>
    <td><b>t = 0ms</b></td>
    <td>Student</td>
    <td>Taps RFID card</td>
  </tr>
  <tr>
    <td>2</td>
    <td><b>t = 10ms</b></td>
    <td>RC522 (RFID Module)</td>
    <td>Reads UID via SPI</td>
  </tr>
  <tr>
    <td>3</td>
    <td><b>t = 20ms</b></td>
    <td>ESP32</td>
    <td>Validates UID read</td>
  </tr>
  <tr>
    <td>4</td>
    <td><b>t = 50ms</b></td>
    <td>ESP32 → Flask Server</td>
    <td>Sends HTTP POST over WiFi</td>
  </tr>
  <tr>
    <td>5</td>
    <td><b>t = 80ms</b></td>
    <td>Flask Server</td>
    <td>Maps UID → student record</td>
  </tr>
  <tr>
    <td>6</td>
    <td><b>t = 85ms</b></td>
    <td>Flask Server</td>
    <td>DateTime stamped, row written to Excel</td>
  </tr>
  <tr>
    <td>7</td>
    <td><b>t = 90ms</b></td>
    <td>Flask Server → ESP32</td>
    <td>Returns 200 OK response</td>
  </tr>
  <tr>
    <td>8</td>
    <td><b>t = 100ms</b></td>
    <td>LCD Display</td>
    <td>Shows "Attendance Marked!"</td>
  </tr>
  <tr>
    <td>9</td>
    <td><b>t = 105ms</b></td>
    <td>Buzzer</td>
    <td>Beeps (scan confirmation)</td>
  </tr>
  <tr>
    <td>10</td>
    <td><b>t = 3000ms</b></td>
    <td>LCD Display</td>
    <td>Resets to "Scan Your Card"</td>
  </tr>
</table>


</div>

---

## 🧰 Hardware Components

<div align="center">

### List of Requirements

</div>

<table>
  <tr>
    <th>#</th>
    <th>Component</th>
    <th>Specification</th>
    <th>Quantity</th>
    <th>Purpose</th>
  </tr>
  <tr>
    <td>1</td>
    <td><b>ESP32 Dev Board</b></td>
    <td>ESP32-WROOM-32 / DevKit v1</td>
    <td>1</td>
    <td>Main microcontroller + WiFi</td>
  </tr>
  <tr>
    <td>2</td>
    <td><b>RFID Module</b></td>
    <td>MFRC522 (RC522), 13.56 MHz</td>
    <td>1</td>
    <td>Read RFID card UIDs</td>
  </tr>
  <tr>
    <td>3</td>
    <td><b>RFID Cards / Tags</b></td>
    <td>Mifare Classic 1K (white card or keychain tag)</td>
    <td>4+</td>
    <td>One per student</td>
  </tr>
  <tr>
    <td>4</td>
    <td><b>16x2 I2C LCD</b></td>
    <td>With PCF8574 I2C backpack, address 0x27</td>
    <td>1</td>
    <td>Status messages display</td>
  </tr>
  <tr>
    <td>5</td>
    <td><b>Buzzer</b></td>
    <td>Active buzzer, 5V</td>
    <td>1</td>
    <td>Audio scan confirmation</td>
  </tr>
  <tr>
    <td>6</td>
    <td><b>Breadboard</b></td>
    <td>Full-size or half-size</td>
    <td>1</td>
    <td>Circuit prototyping</td>
  </tr>
  <tr>
    <td>7</td>
    <td><b>Jumper Wires</b></td>
    <td>Male-to-Male and Male-to-Female</td>
    <td>~20</td>
    <td>Component connections</td>
  </tr>
  <tr>
    <td>8</td>
    <td><b>USB Cable</b></td>
    <td>Micro-USB (for ESP32 power + programming)</td>
    <td>1</td>
    <td>Power & code upload</td>
  </tr>
</table>

> ⚠️ **Important:** The RC522 RFID module runs on **3.3V only**. Connecting it to 5V will damage the module permanently.

---

## 💻 Software & Tools

<div align="center">

<table>
  <tr>
    <td align="center" width="25%">
      <img src="https://img.icons8.com/color/96/000000/arduino.png" width="60" height="60" alt="Arduino IDE"/>
      <br><b>Arduino IDE</b>
      <br>ESP32 firmware
      <br>v1.8+ or v2.x
    </td>
    <td align="center" width="25%">
      <img src="https://img.icons8.com/nolan/96/flask.png" width="60" height="60" alt="Python"/>
      <br><b>Python 3.x</b>
      <br>Flask server
      <br>v3.8+
    </td>
    <td align="center" width="25%">
      <img src="https://img.icons8.com/nolan/96/flask.png" width="60" height="60" alt="Flask"/>
      <br><b>Flask</b>
      <br>HTTP REST API
      <br>pip install
    </td>
    <td align="center" width="25%">
      <img src="https://img.icons8.com/color/96/000000/ms-excel.png" width="60" height="60" alt="OpenPyXL"/>
      <br><b>OpenPyXL</b>
      <br>Excel read/write
      <br>pip install
    </td>
  </tr>
</table>

### Arduino Libraries Required

| Library | Install Via | Purpose |
|---------|-------------|---------|
| `MFRC522` | Library Manager | RC522 RFID card reading |
| `LiquidCrystal_I2C` | Library Manager | 16x2 I2C LCD control |
| `WiFi.h` | Built-in (ESP32) | WiFi connectivity |
| `HTTPClient.h` | Built-in (ESP32) | HTTP POST requests |
| `SPI.h` | Built-in | SPI bus for RC522 |
| `Wire.h` | Built-in | I2C bus for LCD |

</div>

---

## 🔌 Wiring Diagrams

<div align="center">

### Complete Connection Overview
```

ESP32 DevKit
┌──────────────────┐
     3.3V ────────┤ 3V3          GND ├──────── GND (all)
│                  │
    RC 522 SDA ───┤ GPIO 5   GPIO 18 ├──────── RC522 SCK
     RC 522 RST ───┤ GPIO 22  GPIO 19 ├──────── RC522 MISO
      LCD SDA ─────┤ GPIO 21  GPIO 23 ├──────── RC522 MOSI
│                  │
      LCD SCL ─────┤ GPIO 22          │                   
      Buzzer + ────┤ GPIO 27          │                   
                     │              VIN ├──────── LCD VCC (5V)
└──────────────────┘

```
</div>

---

### 🟢 1️⃣ ESP32 ↔ RFID RC522 (SPI)

<table>
  <tr>
    <th>RC522 Pin</th>
    <th>ESP32 Pin</th>
    <th>Wire Color (Suggested)</th>
    <th>Purpose</th>
  </tr>
  <tr>
    <td><b>SDA (SS)</b></td>
    <td>GPIO 5</td>
    <td>🟡 Yellow</td>
    <td>SPI Chip Select</td>
  </tr>
  <tr>
    <td><b>SCK</b></td>
    <td>GPIO 18</td>
    <td>🟠 Orange</td>
    <td>SPI Clock</td>
  </tr>
  <tr>
    <td><b>MOSI</b></td>
    <td>GPIO 23</td>
    <td>🔵 Blue</td>
    <td>Master Out Slave In</td>
  </tr>
  <tr>
    <td><b>MISO</b></td>
    <td>GPIO 19</td>
    <td>🟢 Green</td>
    <td>Master In Slave Out</td>
  </tr>
  <tr>
    <td><b>RST</b></td>
    <td>GPIO 22</td>
    <td>⚪ White</td>
    <td>Module Reset</td>
  </tr>
  <tr>
    <td><b>3.3V</b></td>
    <td>3.3V</td>
    <td>🔴 Red</td>
    <td>Power ⚠️ 3.3V ONLY</td>
  </tr>
  <tr>
    <td><b>GND</b></td>
    <td>GND</td>
    <td>⚫ Black</td>
    <td>Ground</td>
  </tr>
</table>

> ⚠️ **Critical:** RC522 must be powered from **3.3V**, never 5V!

---

### 🟢 2️⃣ ESP32 ↔ LCD I2C (16x2, Address 0x27)

<table>
  <tr>
    <th>LCD Pin</th>
    <th>ESP32 Pin</th>
    <th>Wire Color (Suggested)</th>
    <th>Purpose</th>
  </tr>
  <tr>
    <td><b>VCC</b></td>
    <td>VIN (5V)</td>
    <td>🔴 Red</td>
    <td>Power (5V needed for backlight)</td>
  </tr>
  <tr>
    <td><b>GND</b></td>
    <td>GND</td>
    <td>⚫ Black</td>
    <td>Ground</td>
  </tr>
  <tr>
    <td><b>SDA</b></td>
    <td>GPIO 21</td>
    <td>🔵 Blue</td>
    <td>I2C Data</td>
  </tr>
  <tr>
    <td><b>SCL</b></td>
    <td>GPIO 22</td>
    <td>🟡 Yellow</td>
    <td>I2C Clock</td>
  </tr>
</table>

> 💡 **Note:** If LCD shows blocks/no text, use a small screwdriver to adjust the **contrast potentiometer** on the I2C backpack.

---

### 🟢 3️⃣ ESP32 ↔ Buzzer

<table>
  <tr>
    <th>Buzzer Pin</th>
    <th>ESP32 Pin</th>
    <th>Wire Color (Suggested)</th>
    <th>Purpose</th>
  </tr>
  <tr>
    <td><b>+ (Positive)</b></td>
    <td>GPIO 27</td>
    <td>🔴 Red</td>
    <td>GPIO control signal</td>
  </tr>
  <tr>
    <td><b>− (Negative)</b></td>
    <td>GND</td>
    <td>⚫ Black</td>
    <td>Ground</td>
  </tr>
</table>

---

### 🟢 4️⃣ Power Summary

<table>
  <tr>
    <th>Device</th>
    <th>Power Source</th>
    <th>Voltage</th>
    <th>Notes</th>
  </tr>
  <tr>
    <td><b>RC522 RFID</b></td>
    <td>ESP32 3.3V pin</td>
    <td>3.3V ⚠️</td>
    <td>Never connect to 5V</td>
  </tr>
  <tr>
    <td><b>16x2 LCD</b></td>
    <td>ESP32 VIN pin</td>
    <td>5V</td>
    <td>Needs 5V for backlight</td>
  </tr>
  <tr>
    <td><b>Buzzer</b></td>
    <td>GPIO 27 (controlled)</td>
    <td>3.3V signal</td>
    <td>Active buzzer works at 3.3V</td>
  </tr>
  <tr>
    <td><b>ESP32</b></td>
    <td>USB (PC or power bank)</td>
    <td>5V via USB</td>
    <td>Regulates internally to 3.3V</td>
  </tr>
  <tr>
    <td><b>All GND</b></td>
    <td>Common GND rail</td>
    <td>0V</td>
    <td>All grounds must be connected together</td>
  </tr>
</table>
</div>
---

### 🟢 5️⃣ Pre-Submission Hardware Checklist

<div align = 'centre'>
<table>
  <tr>
    <th>#</th>
    <th>Status</th>
    <th>Checklist Item</th>
    <th>Category</th>
  </tr>
  <tr>
    <td>1</td>
    <td>☐</td>
    <td>RC522 powered from <b>3.3V pin</b> (NOT 5V)</td>
    <td>Hardware</td>
  </tr>
  <tr>
    <td>2</td>
    <td>☐</td>
    <td>All GND pins connected to common ground</td>
    <td>Hardware</td>
  </tr>
  <tr>
    <td>3</td>
    <td>☐</td>
    <td>LCD shows "Scan Your Card" on boot</td>
    <td>Hardware</td>
  </tr>
  <tr>
    <td>4</td>
    <td>☐</td>
    <td>Buzzer beeps when a card is scanned</td>
    <td>Hardware</td>
  </tr>
  <tr>
    <td>5</td>
    <td>☐</td>
    <td>Serial Monitor shows UID on scan (115200 baud)</td>
    <td>Firmware</td>
  </tr>
  <tr>
    <td>6</td>
    <td>☐</td>
    <td>PC server is running and accessible on LAN</td>
    <td>Network</td>
  </tr>
  <tr>
    <td>7</td>
    <td>☐</td>
    <td><b>serverIP</b> in .ino matches your PC's IP address</td>
    <td>Network</td>
  </tr>
  <tr>
    <td>8</td>
    <td>☐</td>
    <td>PC and ESP32 are on the same WiFi network</td>
    <td>Network</td>
  </tr>
  <tr>
    <td>9</td>
    <td>☐</td>
    <td><b>attendance.xlsx</b> is being created/updated</td>
    <td>Software</td>
  </tr>
</table>
</div>div

---

## 📂 Project Structure

```
ESP32_Attendance/
│
├── 📄 server-main.ino       # ESP32 Arduino firmware
│   └── Reads RFID UID, sends HTTP POST to Flask server
│
├── 🐍 attendance-main.py          # Python Flask server
│   └── Maps UID → student, writes to Excel
│
├── 📊 attendance.xlsx              # Auto-generated attendance file
│   └── Created on first scan, rows appended each scan
│
└── 📖 README.md                    # This documentation
```

### Key Code Sections

<details>
<summary><b>📄 server-main.ino  — Key Snippet</b></summary>

```cpp
#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>

// --- CONFIGURE THESE ---
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* serverIP = "YOUR_PC_IP";  // e.g. "192.168.1.100"

// Pin definitions
#define SS_PIN  5
#define RST_PIN 22
#define BUZZER  27

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  // Read UID
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();

  // Send to Flask server
  HTTPClient http;
  http.begin("http://" + String(serverIP) + ":5000/attend");
  http.addHeader("Content-Type", "application/json");
  String payload = "{\"uid\":\"" + uid + "\"}";
  int code = http.POST(payload);

  // Feedback
  if (code == 200) {
    lcd.print("Attendance Marked");
    tone(BUZZER, 1000, 200);  // Beep
  }
  
  rfid.PICC_HaltA();
}
```

</details>

<details>
<summary><b>🐍 attendance-main.py  — Key Snippet</b></summary>

```python
from flask import Flask, request, jsonify
from openpyxl import load_workbook, Workbook
from datetime import datetime
import os

app = Flask(__name__)
EXCEL_FILE = "attendance.xlsx"

# UID → Student mapping
students = {
    "A3B2C1D0": {"sno": 1, "name": "ARYAN RANJAN", "dept": "CS"},
    "B4C3D2E1": {"sno": 2, "name": "KANISH SINGH", "dept": "CS"},
    "C5D4E3F2": {"sno": 3, "name": "DIKSHANT SHARMA",  "dept": "CS"},
    "D6E5F4A3": {"sno": 4, "name": "ANURAG JHA",  "dept": "CS"},
}

@app.route('/attend', methods=['POST'])
def mark_attendance():
    uid = request.json.get('uid', '').upper()
    
    if uid not in students:
        return jsonify({"status": "unknown"}), 404
    
    student = students[uid]
    now = datetime.now()
    
    # Load or create Excel workbook
    if os.path.exists(EXCEL_FILE):
        wb = load_workbook(EXCEL_FILE)
        ws = wb.active
    else:
        wb = Workbook()
        ws = wb.active
        ws.append(["SNO", "NAME", "DEPARTMENT", "DATE", "TIME"])
    
    # Append attendance row
    ws.append([
        student['sno'],
        student['name'],
        student['dept'],
        now.strftime("%Y-%m-%d"),
        now.strftime("%H:%M:%S")
    ])
    wb.save(EXCEL_FILE)
    
    print(f"✓ Marked: {student['name']} at {now.strftime('%H:%M:%S')}")
    return jsonify({"status": "ok"}), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
```

</details>

---

## ⚙️ How to Run

<div align="center">

### Step 1️⃣ — Install Python Dependencies

</div>

```bash
pip install flask openpyxl
```

<div align="center">

### Step 2️⃣ — Find Your PC's IP Address

</div>

<table>
<tr>
<td width="33%">

**Windows:**
```cmd
ipconfig
```
Look for **IPv4 Address**
e.g. `192.168.1.100`

</td>
<td width="33%">

**macOS:**
```bash
ipconfig getifaddr en0
```
Returns your local IP

</td>
<td width="33%">

**Linux:**
```bash
hostname -I
```
Returns your local IP

</td>
</tr>
</table>

> ⚠️ Your PC and ESP32 **must be on the same WiFi network**

<div align="center">

### Step 3️⃣ — Start the Flask Server

</div>

```bash
# Navigate to project folder
cd path/to/ESP32_Attendance

# Start server
python attendance-main.py 
```

You should see:
```
 * Running on http://0.0.0.0:5000
 * Running on http://192.168.1.100:5000
```

<div align="center">

### Step 4️⃣ — Configure & Upload ESP32 Code

</div>

1. Open `server-main.ino ` in **Arduino IDE**
2. Update these three lines:

```cpp
const char* ssid     = "YOUR_WIFI_NAME";      // Your WiFi SSID
const char* password = "YOUR_WIFI_PASSWORD";   // Your WiFi password
const char* serverIP = "192.168.1.100";        // Your PC's IP from Step 2
```

3. Select **Board**: `Tools → Board → ESP32 Dev Module`
4. Select **Port**: `Tools → Port → COMx` (Windows) or `/dev/ttyUSB0` (Linux)
5. Click **Upload** (→ button)
6. Open **Serial Monitor** at **115200 baud** to see debug output

<div align="center">

### Step 5️⃣ — Add Your RFID Card UIDs

</div>

1. Scan a card and note the UID from the **Serial Monitor**:
   ```
   Card UID: A3 B2 C1 D0
   ```

2. Add it to the `students` dictionary in `attendance-main.py `:
   ```python
   students = {
       "A3B2C1D0": {"sno": 1, "name": "YOUR NAME", "dept": "CS"},
   }
   ```

3. Restart the Flask server

---

## 🔧 Working Principle

```
Step 1 ─ Student holds RFID card near RC522 reader
Step 2 ─ RC522 reads 4-byte UID via 13.56 MHz RF field
Step 3 ─ ESP32 reads UID from RC522 over SPI bus
Step 4 ─ ESP32 formats UID as uppercase hex string
Step 5 ─ ESP32 sends HTTP POST → Flask server via WiFi
          Body: { "uid": "A3B2C1D0" }
Step 6 ─ Flask server looks up UID in students dictionary
Step 7 ─ Server generates current date (datetime.now())
Step 8 ─ Server appends row to attendance.xlsx
Step 9 ─ Server returns HTTP 200 OK to ESP32
Step 10 ─ ESP32 displays "Attendance Marked!" on LCD
Step 11 ─ Buzzer beeps once (200ms tone)
Step 12 ─ System resets, ready for next card
```

---

## 👨‍🎓 Student Mapping

Assign each physical RFID card to a student in `attendance-main.py `:

```python
students = {
    "UID_OF_CARD_1": {"sno": 1, "name": "ARYAN RANJAN", "dept": "CS"},
    "UID_OF_CARD_2": {"sno": 2, "name": "KANISH SINGH",     "dept": "CS"},
    "UID_OF_CARD_3": {"sno": 3, "name": "DIKSHANT SHARMA",  "dept": "CS"},
    "UID_OF_CARD_4": {"sno": 4, "name": "ANURAG JHA",  "dept": "CS"},
}
```

**To get each card's UID:**
1. Run the server
2. Scan the card
3. Check Serial Monitor — UID is printed there
4. Paste it into the dictionary

<table>
  <tr>
    <th>SNO</th>
    <th>Name</th>
    <th>Department</th>
    <th>Card UID (example)</th>
  </tr>
  <tr>
    <td>1</td>
    <td>ARYAN RANJAN</td>
    <td>CS</td>
    <td>A3B2C1D0</td>
  </tr>
  <tr>
    <td>2</td>
    <td>KANISH SINGH</td>
    <td>CS</td>
    <td>B4C3D2E1</td>
  </tr>
  <tr>
    <td>3</td>
    <td>DIKSHANT SHARMA</td>
    <td>CS</td>
    <td>C5D4E3F2</td>
  </tr>
  <tr>
    <td>4</td>
    <td>Aryan Ranjan</td>
    <td>CS</td>
    <td>D6E5F4A3</td>
  </tr>
</table>

---

## 📊 Sample Output

**Console output when card is scanned:**
```
✓ Marked: ARYAN RANJAN at 08:30:12
✓ Marked: ANURAG JHA at 08:31:05
✓ Marked: KANISH SINGH at 08:32:44
```

**attendance.xlsx generated file:**

| SNO | NAME | DEPARTMENT | DATE | TIME |
|-----|------|------------|------|------|

---


<!-- <div align="center">

**Hardware Setup**

![Project Setup](https://github.com/user-attachments/assets/af1baa00-2d59-44d7-9fcd-2309c6d7923a)

![Wiring View](https://github.com/user-attachments/assets/2c31c6eb-ad11-4e8e-98d2-f0b127c159d7)

![LCD Display](https://github.com/user-attachments/assets/a204457c-8a16-4cf1-87e6-86438a3c3973)

![Full Assembly](https://github.com/user-attachments/assets/80fd92e0-fd23-4d62-899a-da9c874a0686)

</div> -->

---

## 🐛 Troubleshooting

<details>
<summary><b>❌ ESP32 can't connect to WiFi</b></summary>

**Symptoms:** Serial Monitor shows `Connecting to WiFi...` indefinitely

**Solutions:**
1. Double-check `ssid` and `password` in the `.ino` file
2. Ensure 2.4 GHz network — ESP32 **does not support 5 GHz**
3. Move ESP32 closer to router
4. Try restarting both router and ESP32

</details>

<details>
<summary><b>❌ HTTP POST fails / no response from server</b></summary>

**Symptoms:** LCD shows "Error" or Serial Monitor shows HTTP error code

**Solutions:**
1. Verify `serverIP` matches your PC's current IP (it can change!)
2. Confirm Flask server is running: browser visit `http://YOUR_IP:5000`
3. Check both devices are on the **same WiFi network**
4. Disable Windows Firewall temporarily, or allow Python through firewall

</details>

<details>
<summary><b>❌ RFID card not being read</b></summary>

**Symptoms:** No UID printed in Serial Monitor when card is tapped

**Solutions:**
1. Check SPI wiring — MOSI/MISO are frequently swapped
2. Confirm RC522 is powered from **3.3V**, not 5V
3. Verify `SS_PIN=5` and `RST_PIN=22` match your wiring
4. Reduce distance — RC522 reads best within 3 cm
5. Try a different RFID card/tag

</details>

<details>
<summary><b>❌ LCD shows no text / all blocks</b></summary>

**Symptoms:** LCD is on but displays only filled rectangles or nothing

**Solutions:**
1. **Contrast:** Adjust the small potentiometer screw on the I2C backpack
2. **Address:** Try `0x3F` instead of `0x27` in the code
3. **Power:** LCD needs 5V on VCC — use VIN pin, not 3.3V
4. **I2C Scanner:** Upload an I2C scanner sketch to confirm the address

```cpp
// Quick I2C Scanner sketch
#include <Wire.h>
void setup() {
  Wire.begin(21, 22);
  Serial.begin(115200);
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0)
      Serial.printf("Found I2C device at 0x%02X\n", addr);
  }
}
void loop() {}
```

</details>

<details>
<summary><b>❌ Excel file not created / not updating</b></summary>

**Symptoms:** No `attendance.xlsx` appears, or old data remains

**Solutions:**
1. Check the server terminal — look for Python errors
2. Ensure you have write permission in the project folder
3. Close the Excel file if it's open in MS Excel before scanning
4. Verify `openpyxl` is installed: `pip install openpyxl`

</details>

---

## 🚀 Future Improvements

<table>
  <tr>
    <th>Enhancement</th>
    <th>Description</th>
    <th>Status</th>
  </tr>
  <tr>
    <td><b>📊 Web Dashboard</b></td>
    <td>Flask HTML dashboard to view attendance in browser</td>
    <td>🔄 Planned</td>
  </tr>
  <tr>
    <td><b>☁️ Cloud Sync</b></td>
    <td>Push attendance to Google Sheets or Firebase</td>
    <td>🔄 Planned</td>
  </tr>
  <tr>
    <td><b>📱 Mobile Alerts</b></td>
    <td>WhatsApp / Telegram notification on scan</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>🔒 Duplicate Check</b></td>
    <td>Prevent double-marking within same session</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>🖨️ PDF Report</b></td>
    <td>Auto-generate daily attendance PDF</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>🔋 Battery Powered</b></td>
    <td>Portable version with LiPo battery</td>
    <td>📋 Idea</td>
  </tr>
</table>

---

## 📜 License

<div align="center">

This project is licensed under the **MIT License** — free to use, modify, and distribute with attribution.

</div>

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:00D4FF,100:E7352C&height=100&section=footer" alt="Footer"/>

<br>

<i>⚡ "Automate the routine. Focus on what matters."</i>



<br>

---

**© 2025 Aryan Ranjan | IoT RFID Attendance System | MIT License**

<br>

⭐ Found this useful? **Star the repo** and share it with your classmates!

<br>

</div>
