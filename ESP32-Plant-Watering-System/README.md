<h1 align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=32&pause=1000&color=22C55E&center=true&vCenter=true&width=700&lines=PlantMind;ESP32+Smart+Watering;Self-Hosted+Dashboard;Zero+Cloud+Dependencies" alt="Typing SVG" />
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge&logo=espressif&logoColor=white" alt="ESP32"/>
  <img src="https://img.shields.io/badge/Arduino_IDE-00878F?style=for-the-badge&logo=arduino&logoColor=white" alt="Arduino IDE"/>
  <img src="https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white" alt="HTML"/>
  <img src="https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black" alt="JavaScript"/>
  <img src="https://img.shields.io/badge/License-MIT-success?style=for-the-badge" alt="License"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Sensors-Temperature%20%2B%20Moisture-blue?style=flat-square" alt="Sensors"/>
  <img src="https://img.shields.io/badge/Auto--Watering-30%25--50%25-green?style=flat-square" alt="Auto"/>
  <img src="https://img.shields.io/badge/Dashboard-Self--Hosted-orange?style=flat-square" alt="Dashboard"/>
  <img src="https://img.shields.io/badge/Cloud-Zero%20Dependencies-brightgreen?style=flat-square" alt="Cloud"/>
</p>

---

<div align="center">

### 🌿 Autonomous Plant Care — No Cloud Required

> **A complete ESP32-based automatic plant watering system that hosts its own web dashboard over local WiFi. Monitor temperature, soil moisture, and control watering from any browser. No Blynk. No AWS. No subscriptions. Just you, your ESP32, and your plants.**

**🌱 Perfect for home automation, smart gardens, IoT learning, and plant enthusiasts**

[How It Works](#-how-it-works) • [Hardware](#-hardware) • [Dashboard](#-dashboard-features) • [API](#-api-reference) • [Setup](#-software-setup)

</div>

---

## 📋 Table of Contents

- [🌟 Project Overview](#-project-overview)
- [✨ Features](#-features)
- [🎬 How It Works](#-how-it-works)
- [🧰 Hardware](#-hardware)
- [🔌 Wiring](#-wiring)
- [📦 Software Setup](#-software-setup)
- [🌐 Dashboard Features](#-dashboard-features)
- [🤖 Auto-Watering Logic](#-auto-watering-logic)
- [📡 API Reference](#-api-reference)
- [📟 LCD Display](#-lcd-display)
- [📂 Project Structure](#-project-structure)
- [🐛 Troubleshooting](#-troubleshooting)
- [🔮 Future Improvements](#-future-improvements)
- [📜 License](#-license)

---

## 🌟 Project Overview

<div align="center">
  <table>
    <tr>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/temperature.png" width="80" height="80" alt="Temperature"/>
        <br><b>DS18B20</b>
        <br>Temperature sensor
        <br>OneWire protocol
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/moisture.png" width="80" height="80" alt="Moisture"/>
        <br><b>Soil Moisture</b>
        <br>Analog sensor
        <br>0-100% reading
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/fluency/96/pump.png" width="80" height="80" alt="Pump"/>
        <br><b>Relay Control</b>
        <br>Water pump
        <br>Auto/manual modes
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/web.png" width="80" height="80" alt="Dashboard"/>
        <br><b>Web Dashboard</b>
        <br>Self-hosted UI
        <br>Live data polling
      </td>
    </tr>
  </table>
</div>

**PlantMind** is a fully self-contained plant watering automation system built on ESP32. Unlike most IoT plant projects that rely on cloud services (Blynk, ThingSpeak, AWS IoT), PlantMind hosts its own responsive web dashboard directly from the ESP32 — no external dependencies, no subscriptions, no internet required. Just connect to your local WiFi and access the dashboard from any browser.

### 🎯 Why This Project Stands Out

<table>
<tr>
<td width="50%">

**Technical Achievements:**
- 🌐 Full web server running on ESP32
- 📦 Dashboard HTML/CSS/JS embedded in firmware (PROGMEM)
- 🔄 Real-time AJAX polling (3-second refresh)
- 📡 RESTful JSON API
- 🤖 Autonomous watering with configurable thresholds
- 📟 Local 16×2 I2C LCD for offline monitoring

</td>
<td width="50%">

**Practical Benefits:**
- 🌿 Never overwater or underwater your plants
- ☁️ Zero cloud dependencies — works offline
- 📱 Control from phone, tablet, or laptop
- 💰 No monthly fees or subscriptions
- 🔒 Private — data never leaves your network
- 🔋 Low power — suitable for solar/battery operation

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
    <td><b>🌡️ Temperature Monitoring</b></td>
    <td>
      ✅ DS18B20 digital sensor (±0.5°C accuracy)<br>
      ✅ OneWire protocol communication<br>
      ✅ Temperature displayed in °C<br>
      ✅ Status badges: Optimal / Warn / Danger<br>
      ✅ Real-time graph on dashboard<br>
      ✅ Configurable alert thresholds
    </td>
  </tr>
  <tr>
    <td><b>💧 Soil Moisture Sensing</b></td>
    <td>
      ✅ Analog capacitive soil sensor<br>
      ✅ 0-100% moisture percentage<br>
      ✅ Animated fill bar visualization<br>
      ✅ Status badges: Dry / Good / Wet<br>
      ✅ Configurable dry/wet thresholds<br>
      ✅ Auto-calibration support
    </td>
  </tr>
  <tr>
    <td><b>💦 Water Pump Control</b></td>
    <td>
      ✅ Relay-controlled water pump<br>
      ✅ Manual ON/OFF toggle from dashboard<br>
      ✅ Automatic watering mode (threshold-based)<br>
      ✅ Safety timeout (prevents over-watering)<br>
      ✅ Pump state displayed on LCD<br>
      ✅ Activity logging with timestamps
    </td>
  </tr>
  <tr>
    <td><b>🌐 Web Dashboard</b></td>
    <td>
      ✅ Self-hosted on ESP32 (no cloud)<br>
      ✅ Responsive design (mobile + desktop)<br>
      ✅ Live data auto-refresh (3-second polling)<br>
      ✅ Material Design inspired UI<br>
      ✅ Animated status cards<br>
      ✅ Activity log feed (last 60 events)<br>
      ✅ Embedded HTML/CSS/JS (PROGMEM)
    </td>
  </tr>
  <tr>
    <td><b>📡 REST API</b></td>
    <td>
      ✅ GET /api/data → live sensor JSON<br>
      ✅ GET /api/pump → manual pump control<br>
      ✅ GET /api/auto → toggle auto-watering<br>
      ✅ CORS enabled for third-party integrations<br>
      ✅ JSON response format<br>
      ✅ Easy Home Assistant / Node-RED integration
    </td>
  </tr>
  <tr>
    <td><b>📟 LCD Display</b></td>
    <td>
      ✅ 16×2 I2C LCD (0x27 or 0x3F)<br>
      ✅ Startup animation (~13 seconds)<br>
      ✅ Shows temp, moisture, pump status<br>
      ✅ Displays WiFi IP address on boot<br>
      ✅ Offline monitoring without dashboard<br>
      ✅ Low power consumption
    </td>
  </tr>
</table>

---

## 🎬 How It Works

<div align="center">

### System Architecture

```
┌────────────────────────────────────────────────────────────┐
│                         LOCAL NETWORK                      │
│                                                            │
│   ┌──────────────┐          ┌──────────────────────────┐   │
│   │   Phone /    │          │        WiFi Router       │   │
│   │   Laptop     │◄────────►│   192.168.x.x subnet     │   │
│   │              │          └───────────┬──────────────┘   │
│   │  Browser:    │                      │                  │
│   │  http://     │                      │                  │
│   │  192.168.x.x │◄─────────────────────┘                  │
│   └──────┬───────┘                                         │
│          │                                                 │
│          │   HTTP GET /                                    │
│          │   HTTP GET /api/data                            │
│          │   HTTP GET /api/pump?state=1                    │
│          └──────────────────────────────┐                  │
│                                         ▼                  │
│                               ┌─────────┴────────────┐     │
│                               │     ESP32            │     │
│                               │   Web Server :80     │     │
│                               │                      │     │
│                               │  GPIO 23 ──► DS18B20 │     │
│                               │  GPIO 33 ──► Soil    │     │
│                               │  GPIO 2  ──► Relay   │     │
│                               │  I2C     ──► LCD     │     │
│                               └──────────────────────┘     │
└────────────────────────────────────────────────────────────┘
```
</div>
### Data Flow

```
Every 3 seconds:
    Browser sends:  GET /api/data
         │
         ▼
    ESP32 reads sensors:
         ├─ DS18B20 (temperature)
         ├─ Analog pin 33 (soil moisture)
         └─ Relay state (pump ON/OFF)
         │
         ▼
    ESP32 responds with JSON:
      {"temp": 24.5,
       "moisture": 62,
       "pump": 0,
       "autoMode": 1}
         │
         ▼
    Browser updates dashboard UI
         ├─ Temperature card + badge
         ├─ Moisture bar + badge
         ├─ Pump toggle button state
         └─ Auto mode toggle state

Auto-watering loop (runs continuously):
    if (autoMode && moisture < 30%)
         → Turn pump ON
    if (autoMode && moisture >= 50%)
         → Turn pump OFF
    
    Display on LCD:
         "Temp: 24.5°C"
         "Soil: 62%  Pump:OFF"
```

### HTTP Endpoints

```
GET /                     → Serve embedded HTML dashboard
GET /api/data             → Return live sensor JSON
GET /api/pump?state=1     → Set relay HIGH (pump ON)
GET /api/pump?state=0     → Set relay LOW (pump OFF)
GET /api/auto?state=1     → Enable auto-watering
GET /api/auto?state=0     → Disable auto-watering
```

</div>

---

## 🧰 Hardware

<table>
  <tr>
    <th>#</th>
    <th>Component</th>
    <th>Specification</th>
    <th>Qty</th>
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
    <td><b>DS18B20</b></td>
    <td>Digital temperature sensor, OneWire</td>
    <td>1</td>
    <td>Measure ambient/soil temperature</td>
  </tr>
  <tr>
    <td>3</td>
    <td><b>Soil Moisture Sensor</b></td>
    <td>Capacitive analog, 3.3V/5V</td>
    <td>1</td>
    <td>Measure soil moisture %</td>
  </tr>
  <tr>
    <td>4</td>
    <td><b>Relay Module</b></td>
    <td>1-channel, 5V coil, 10A contact</td>
    <td>1</td>
    <td>Control water pump ON/OFF</td>
  </tr>
  <tr>
    <td>5</td>
    <td><b>16×2 I2C LCD</b></td>
    <td>HD44780 + PCF8574, 0x27 or 0x3F</td>
    <td>1</td>
    <td>Local display (temp, moisture, status)</td>
  </tr>
  <tr>
    <td>6</td>
    <td><b>Water Pump</b></td>
    <td>DC submersible, 3-6V or 12V</td>
    <td>1</td>
    <td>Deliver water to plant</td>
  </tr>
  <tr>
    <td>7</td>
    <td><b>4.7 kΩ Resistor</b></td>
    <td>Pull-up for DS18B20</td>
    <td>1</td>
    <td>OneWire protocol requirement</td>
  </tr>
  <tr>
    <td>8</td>
    <td><b>Jumper Wires</b></td>
    <td>Male-to-Male, Male-to-Female</td>
    <td>~20</td>
    <td>Component connections</td>
  </tr>
  <tr>
    <td>9</td>
    <td><b>Breadboard</b></td>
    <td>Half-size or full-size</td>
    <td>1</td>
    <td>Prototyping (optional for final build)</td>
  </tr>
  <tr>
    <td>10</td>
    <td><b>Power Supply</b></td>
    <td>5V 2A USB or DC adapter</td>
    <td>1</td>
    <td>Power ESP32 + pump</td>
  </tr>
</table>

> 💡 **Soil Sensor Tip:** Use a **capacitive** sensor, not resistive — capacitive sensors last longer in soil and don't corrode.

---

## 🔌 Wiring

<!-- <div align="center"> -->

### Complete Wiring Diagram

```
                      ESP32 DevKit
              ┌────────────────────────┐
              │                        │
   DS18B20 ───┤ GPIO 23     GPIO 33 ───┼──── Soil Sensor (Analog)
   (Data)     │                        │
              │                        │
   Relay IN ──┤ GPIO 2      GPIO 21 ───┼──── LCD SDA
              │             GPIO 22 ───┼──── LCD SCL
              │                        │
              │            3.3V ───────┼──── DS18B20 VCC + Soil VCC
              │            5V (VIN)────┼──── LCD VCC + Relay VCC
              │            GND ────────┼──── All GND (common)
              └────────────────────────┘
                          │
                4.7kΩ pull-up resistor
                   (GPIO 23 → 3.3V)
```

</div>

### Pin Assignment Table

<table>
  <tr>
    <th>ESP32 Pin</th>
    <th>Connected To</th>
    <th>Function</th>
    <th>Notes</th>
  </tr>
  <tr>
    <td><b>GPIO 23</b></td>
    <td>DS18B20 Data</td>
    <td>OneWire temperature read</td>
    <td>Requires 4.7kΩ pull-up to 3.3V</td>
  </tr>
  <tr>
    <td><b>GPIO 33</b></td>
    <td>Soil Sensor Analog Out</td>
    <td>ADC read (0-4095)</td>
    <td>Mapped to 0-100% in code</td>
  </tr>
  <tr>
    <td><b>GPIO 2</b></td>
    <td>Relay IN</td>
    <td>Digital output (pump control)</td>
    <td>Most relays are active-LOW</td>
  </tr>
  <tr>
    <td><b>GPIO 21</b></td>
    <td>LCD SDA</td>
    <td>I2C data line</td>
    <td>Default ESP32 I2C SDA</td>
  </tr>
  <tr>
    <td><b>GPIO 22</b></td>
    <td>LCD SCL</td>
    <td>I2C clock line</td>
    <td>Default ESP32 I2C SCL</td>
  </tr>
  <tr>
    <td><b>3.3V</b></td>
    <td>DS18B20 VCC, Soil VCC</td>
    <td>Power for sensors</td>
    <td>Sensors run on 3.3V</td>
  </tr>
  <tr>
    <td><b>VIN (5V)</b></td>
    <td>LCD VCC, Relay VCC</td>
    <td>Power for 5V modules</td>
    <td>LCD backlight needs 5V</td>
  </tr>
  <tr>
    <td><b>GND</b></td>
    <td>All GND pins</td>
    <td>Common ground</td>
    <td>Connect all grounds together</td>
  </tr>
</table>

### DS18B20 Pull-Up Resistor

```
        3.3V
         │
        [4.7kΩ]
         │
         ├────── GPIO 23 (Data line)
         │
     DS18B20
         │
        GND
```

> ⚠️ **Critical:** The DS18B20 requires a 4.7 kΩ pull-up resistor between the data line and VCC (3.3V). Without it, you'll get `-127°C` readings.

### Relay Module Notes

Most relay modules are **active-LOW**, meaning:
- `digitalWrite(RELAY_PIN, HIGH)` → Relay **OFF**, pump **OFF**
- `digitalWrite(RELAY_PIN, LOW)` → Relay **ON**, pump **ON**

If your pump turns on unexpectedly at boot, **invert the HIGH/LOW values** in the code's `handlePump()` and `autoWater()` functions.

---

## 📦 Software Setup

<div align="center">

### Step 1️⃣ — Install Arduino IDE

</div>

Download from [arduino.cc](https://www.arduino.cc/en/software) — Version 1.8+ or 2.x works.

<div align="center">

### Step 2️⃣ — Add ESP32 Board Support

</div>

1. Open **File → Preferences**
2. Paste into *Additional Boards Manager URLs*:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
3. Go to **Tools → Board → Boards Manager**
4. Search **"esp32"** → Install **"esp32 by Espressif Systems"**

<div align="center">

### Step 3️⃣ — Install Required Libraries

</div>

Go to **Sketch → Include Library → Manage Libraries** and install:

| Library | Author | Purpose |
|---------|--------|---------|
| **LiquidCrystal_I2C** | Frank de Brabander | I2C LCD display control |
| **DallasTemperature** | Miles Burton | DS18B20 high-level interface |
| **OneWire** | Jim Studt | OneWire protocol for DS18B20 |

> 💡 `WiFi.h` and `WebServer.h` are built into the ESP32 Arduino core — no install needed.

<div align="center">

### Step 4️⃣ — Configure WiFi Credentials

</div>

Open `system.ino` and update these two lines near the top:

```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";
```

> ⚠️ **Security Tip:** Never commit real WiFi credentials to a public repository. Create a `secrets.h` file:

```cpp
// secrets.h (add to .gitignore)
const char* ssid = "MyNetwork";
const char* pass = "MyPassword";
```

Then in `system.ino`:
```cpp
#include "secrets.h"
```

<div align="center">

### Step 5️⃣ — Upload Firmware

</div>

1. Connect ESP32 via USB
2. Select **Tools → Board → ESP32 Dev Module** (or your specific variant)
3. Select **Tools → Port → COMx** (Windows) or `/dev/ttyUSB0` (Linux)
4. Click **Upload** (→)
5. If upload fails, hold **BOOT button** while clicking Upload
6. Open **Serial Monitor** at **115200 baud**

Expected Serial Monitor output:
```
=================================
    PlantMind Initializing
=================================
LCD startup animation...
Connecting to WiFi: MyNetwork
WiFi connected!
IP Address: 192.168.1.87
Starting web server on port 80...
Server ready!
=================================
```

---

## 🌐 Dashboard Features

<div align="center">

### Accessing the Dashboard

</div>

After the ESP32 boots:

1. Note the **IP address** displayed on the LCD or in Serial Monitor (e.g., `192.168.1.87`)
2. On any device connected to the **same WiFi network**, open a browser
3. Navigate to: **`http://192.168.1.87`** (use your actual IP)
4. The dashboard loads instantly and begins live-polling every 3 seconds

### Dashboard UI Layout
<div align="center">
  
```
┌────────────────────────────────────────────────┐
│       🌿 🌿 PlantMind - Dashboard 🌿 🌿       │
│      Real-Time Plant Monitoring & Control      │
├────────────────────────────────────────────────┤
│                                                │
│  ┌──────────────────┐    ┌──────────────────┐  │
│  │    Temperature   │    │   Soil Moisture  │  │
│  │                  │    │                  │  │
│  │      24.5 °C     │    │       62%        │  │
│  │                  │    │                  │  │
│  │    [✓ Optimal]   │    │  ███████▒▒▒▒▒▒   │  │
│  │                  │    │     [✓ Good]     │  │
│  └──────────────────┘    └──────────────────┘  │
│                                                │
│  ┌──────────────────────────────────────────┐  │
│  │  Water Pump Control                      │  │
│  │                                          │  │
│  │  Status: OFF                             │  │
│  │  [ Turn ON ]                             │  │
│  │                                          │  │
│  └──────────────────────────────────────────┘  │
│                                                │
│  ┌──────────────────────────────────────────┐  │
│  │  Auto-Watering Mode                      │  │
│  │                                          │  │
│  │  [ Enable ]  [ Disable ]                 │  │
│  │                                          │  │
│  │  Thresholds: Dry < 30%, Wet > 50%        │  │
│  └──────────────────────────────────────────┘  │
│                                                │
│  ┌──────────────────────────────────────────┐  │
│  │  Activity Log                            │  │
│  │                                          │  │
│  │  [12:34:56] Pump turned ON               │  │
│  │  [12:32:10] Auto mode enabled            │  │
│  │  [12:30:00] Moisture below 30%           │  │
│  │  ...                                     │  │
│  └──────────────────────────────────────────┘  │
│                                                │
│  Device IP: 192.168.1.87     Uptime: 2h 15m    │
└────────────────────────────────────────────────┘
```

</div>

### Dashboard Features Table

<table>
  <tr>
    <th>Feature</th>
    <th>Description</th>
  </tr>
  <tr>
    <td><b>🌡️ Temperature Card</b></td>
    <td>
      • Live °C reading (updates every 3 seconds)<br>
      • Status badge: <span style="color:green">Optimal</span> (15-28°C), <span style="color:orange">Warn</span> (28-35°C), <span style="color:red">Danger</span> (>35°C)<br>
      • Animated value transitions<br>
      • Responsive layout
    </td>
  </tr>
  <tr>
    <td><b>💧 Moisture Card</b></td>
    <td>
      • Live % reading (0-100%)<br>
      • Animated horizontal fill bar<br>
      • Status badge: <span style="color:red">Dry</span> (<30%), <span style="color:green">Good</span> (30-70%), <span style="color:blue">Wet</span> (>70%)<br>
      • Color-coded visual feedback
    </td>
  </tr>
  <tr>
    <td><b>🔌 Pump Toggle</b></td>
    <td>
      • Manual ON/OFF button<br>
      • Shows current pump state<br>
      • Sends GET /api/pump?state=1 or 0<br>
      • Auto-disables auto mode when manually toggled
    </td>
  </tr>
  <tr>
    <td><b>🤖 Auto Mode</b></td>
    <td>
      • Enable/disable autonomous watering<br>
      • Threshold display: "Dry < 30%, Wet > 50%"<br>
      • Off by default (safety)<br>
      • Indicator shows current mode state
    </td>
  </tr>
  <tr>
    <td><b>📋 Activity Log</b></td>
    <td>
      • Timestamped event feed<br>
      • Last 60 entries displayed<br>
      • Auto-scrolls to newest<br>
      • Events: pump on/off, auto mode toggle, threshold alerts
    </td>
  </tr>
</table>

---

## 🤖 Auto-Watering Logic

<div align="center">

### Threshold-Based Control

</div>

```
Moisture reading loop (every 3 seconds):

    Read moisture sensor (0-100%)
         │
         ▼
    Is Auto Mode enabled?
         │
         ├─ NO  → Skip automatic control
         │
         └─ YES → Check thresholds:
                     │
                     ├─ Moisture < 30% ?
                     │      │
                     │      └─ YES → Turn pump ON
                     │
                     └─ Moisture ≥ 50% ?
                            │
                            └─ YES → Turn pump OFF
```

### Threshold Table

| Condition | Pump Action | Reasoning |
|-----------|-------------|-----------|
| **Moisture < 30%** | 🔴 Turn **ON** | Soil is dry — plant needs water |
| **30% ≤ Moisture < 50%** | ⏸️ **No change** | Hysteresis zone — prevents rapid toggling |
| **Moisture ≥ 50%** | 🟢 Turn **OFF** | Soil is sufficiently moist |

> 💡 **Hysteresis Zone (30-50%):** This "deadband" prevents the pump from rapidly cycling ON/OFF when moisture hovers around a single threshold. The pump only turns ON when moisture drops below 30%, and only turns OFF when it rises above 50%.

### Manual Override Behaviour

```
User clicks "Turn ON" in dashboard
    │
    ▼
Pump turns ON immediately
    │
    ▼
Auto mode is DISABLED automatically
    │
    └─ Prevents auto-logic from interfering with manual control
```

> ⚠️ **Safety:** Manual pump control always disables auto mode to prevent conflicting commands.

---

## 📡 API Reference

All endpoints return JSON and include `Access-Control-Allow-Origin: *` for CORS.

### `GET /api/data`

**Description:** Returns current sensor readings and device state.

**Response:**
```json
{
  "temp": 24.50,
  "moisture": 62,
  "pump": 0,
  "autoMode": 1,
  "ip": "192.168.1.87"
}
```

**Fields:**
- `temp` — Temperature in °C (float)
- `moisture` — Soil moisture % (integer, 0-100)
- `pump` — Pump state (0 = OFF, 1 = ON)
- `autoMode` — Auto-watering enabled (0 = disabled, 1 = enabled)
- `ip` — ESP32 IP address (string)

**Usage:**
```bash
curl http://192.168.1.87/api/data
```

---

### `GET /api/pump?state=<0|1>`

**Description:** Manually control water pump. Also disables auto mode.

**Parameters:**
- `state` (required):
  - `1` = Turn pump **ON**
  - `0` = Turn pump **OFF**

**Response:**
```json
{
  "success": true,
  "pump": 1,
  "autoMode": 0
}
```

**Usage:**
```bash
# Turn pump ON
curl http://192.168.1.87/api/pump?state=1

# Turn pump OFF
curl http://192.168.1.87/api/pump?state=0
```

---

### `GET /api/auto?state=<0|1>`

**Description:** Enable or disable automatic watering mode.

**Parameters:**
- `state` (required):
  - `1` = Enable auto-watering
  - `0` = Disable auto-watering

**Response:**
```json
{
  "success": true,
  "autoMode": 1
}
```

**Usage:**
```bash
# Enable auto mode
curl http://192.168.1.87/api/auto?state=1

# Disable auto mode
curl http://192.168.1.87/api/auto?state=0
```

---

## 📟 LCD Display

<div align="center">

### Startup Animation

</div>

On boot, the LCD displays a ~13-second startup sequence:

```
Line 1:  PlantMind v1.0
Line 2:  Initializing...

(2 second delay)

Line 1:  Connecting WiFi
Line 2:  MyNetwork...

(waiting for connection)

Line 1:  WiFi Connected!
Line 2:  IP: 192.168.1.87

(5 second display)
```

<div align="center">

### Normal Operation Display

</div>

During normal operation, the LCD shows live data:

```
┌────────────────┐
│Temp: 24.5°C    │
│Soil: 62%  OFF  │  ← "OFF" or "ON" (pump state)
└────────────────┘
```

**Update frequency:** Every 3 seconds (synchronized with sensor readings)

---

## 📂 Project Structure

```
PlantMind/
│
├── 📄 system.ino                 # Complete firmware (single file)
│   ├── WiFi setup
│   ├── Sensor reading (DS18B20 + soil)
│   ├── Relay control logic
│   ├── Auto-watering thresholds
│   ├── WebServer routes
│   ├── Embedded HTML dashboard (PROGMEM)
│   └── LCD display routines
│
└── 📖 README.md                  # This documentation
```

> 💡 **Single-File Architecture:** The entire project lives in one `.ino` file. The dashboard HTML/CSS/JavaScript is embedded as a `PROGMEM` string constant — no SPIFFS partition or SD card needed.

---

## 🐛 Troubleshooting

<details>
<summary><b>❌ LCD shows garbage characters or blocks</b></summary>

**Symptoms:** LCD displays random symbols, all filled blocks, or nothing

**Solutions:**
1. **I2C address wrong:** Most LCDs use `0x27`, but some use `0x3F`. Change in code:
   ```cpp
   LiquidCrystal_I2C lcd(0x3F, 16, 2);  // Try 0x3F instead of 0x27
   ```
2. **Contrast too high/low:** Rotate the small potentiometer screw on the I2C backpack
3. **Wiring:** Verify SDA→GPIO 21, SCL→GPIO 22, VCC→5V, GND→GND
4. **I2C Scanner:** Upload an I2C scanner sketch to find the correct address:
   ```cpp
   #include <Wire.h>
   void setup() {
     Wire.begin(21, 22);
     Serial.begin(115200);
     for (byte i = 1; i < 127; i++) {
       Wire.beginTransmission(i);
       if (Wire.endTransmission() == 0) {
         Serial.printf("Found I2C device at 0x%02X\n", i);
       }
     }
   }
   void loop() {}
   ```

</details>

<details>
<summary><b>❌ Temperature reads -127°C or -196.6°F</b></summary>

**Symptoms:** DS18B20 always returns -127°C (error code)

**Solutions:**
1. **Missing pull-up resistor:** Add a 4.7 kΩ resistor between GPIO 23 and 3.3V
2. **Wiring:** Verify DS18B20 data pin → GPIO 23, VCC → 3.3V (not 5V), GND → GND
3. **Dead sensor:** Test with a multimeter — data line should read ~3.3V when idle
4. **Wrong OneWire pin in code:** Confirm `#define ONE_WIRE_BUS 23`

</details>

<details>
<summary><b>❌ Moisture always reads 0% or 100%</b></summary>

**Symptoms:** Soil sensor returns only extreme values

**Solutions:**
1. **Calibration needed:** Adjust the `map()` range in code:
   ```cpp
   // Default:
   int moisture = map(raw, 4095, 0, 0, 100);
   
   // Calibrate by reading dry and wet values:
   // - Insert sensor in dry soil → note Serial Monitor value (e.g., 3500)
   // - Insert sensor in wet soil → note Serial Monitor value (e.g., 1500)
   
   // Update map() call:
   int moisture = map(raw, 3500, 1500, 0, 100);  // Dry=3500, Wet=1500
   ```
2. **Sensor type:** Capacitive sensors read 0-3000 range; resistive sensors vary widely
3. **ADC pin:** ESP32 GPIO 33 is a valid ADC pin — GPIO 34-39 are input-only

</details>

<details>
<summary><b>❌ Can't access dashboard from browser</b></summary>

**Symptoms:** Browser shows "This site can't be reached" or timeout

**Solutions:**
1. **Same network:** Ensure phone/laptop is on the **same WiFi** as ESP32
2. **Correct IP:** Get the current IP from Serial Monitor or LCD — it may change after restart
3. **HTTP not HTTPS:** Use `http://` — ESP32 doesn't support SSL
4. **Firewall:** Temporarily disable firewall on PC to test
5. **Ping test:** Open terminal and run `ping 192.168.1.87` — if no reply, ESP32 isn't reachable

</details>

<details>
<summary><b>❌ Pump turns on at boot or won't turn off</b></summary>

**Symptoms:** Pump activates unexpectedly

**Solutions:**
1. **Active-LOW relay:** Most relays are active-LOW. Invert logic in code:
   ```cpp
   // If pump turns on when it shouldn't:
   digitalWrite(RELAY_PIN, HIGH);  // Should turn OFF
   digitalWrite(RELAY_PIN, LOW);   // Should turn ON
   
   // Swap all HIGH/LOW in handlePump() and autoWater()
   ```
2. **Add pull-up:** Add a 10kΩ resistor from GPIO 2 to 3.3V to keep relay HIGH (off) during boot

</details>

<details>
<summary><b>❌ WiFi won't connect — stuck on "Connecting..."</b></summary>

**Symptoms:** Serial Monitor shows dots indefinitely

**Solutions:**
1. **SSID/password typo:** Double-check spelling, case-sensitivity, and special characters
2. **2.4 GHz only:** ESP32 doesn't support 5 GHz WiFi — check router settings
3. **Hidden SSID:** If your network is hidden, you may need additional config
4. **Signal strength:** Move ESP32 closer to router during testing
5. **Router MAC filter:** Add ESP32's MAC address to allowed devices (printed in Serial Monitor)

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
    <td><b>📊 Historical Charts</b></td>
    <td>Store sensor data in SPIFFS, graph temperature/moisture over time</td>
    <td>🔄 Planned</td>
  </tr>
  <tr>
    <td><b>📧 Email Alerts</b></td>
    <td>Send notifications when moisture drops below threshold</td>
    <td>🔄 Planned</td>
  </tr>
  <tr>
    <td><b>🔋 Battery Support</b></td>
    <td>Deep sleep mode + solar panel integration for off-grid operation</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>🏠 Home Assistant</b></td>
    <td>MQTT integration or Home Assistant RESTful sensor</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>☀️ Light Sensor</b></td>
    <td>Add LDR or BH1750 to monitor sunlight exposure</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>🌐 Multi-Plant Support</b></td>
    <td>Control multiple plants with individual moisture sensors + relays</td>
    <td>📋 Idea</td>
  </tr>
  <tr>
    <td><b>📅 Scheduled Watering</b></td>
    <td>Time-based watering (e.g., every morning at 7 AM) using NTP</td>
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

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:22C55E,100:10B981&height=100&section=footer" alt="Footer"/>

<br>

<i>🌿 "The best time to plant a tree was 20 years ago. The second best time is now — with automation."</i>

<br><br>

**Made with 💚 for Plant Lovers & Makers**

<br>

---

**© 2025 | PlantMind — ESP32 Smart Watering System | MIT License**

<br>

⭐ If this project helped your plants thrive, please **star the repo**!

<br>

[⬆ Back to Top](#)

</div>
