<h1 align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=32&pause=1000&color=639ccf&center=true&vCenter=true&width=600&lines=Ultrasonic+Distance+Measurement;Arduino+%2B+Python+Integration;Real-Time+Sensor+Processing" alt="Typing SVG" />
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-UNO-00979D?style=for-the-badge&logo=arduino&logoColor=white" alt="Arduino"/>
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
  <img src="https://img.shields.io/badge/Python-3.8+-3776AB?style=for-the-badge&logo=python&logoColor=white" alt="Python"/>
  <img src="https://img.shields.io/badge/Status-Stable-success?style=for-the-badge" alt="Status"/>
  <img src="https://img.shields.io/badge/License-MIT-lightgrey?style=for-the-badge" alt="License"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Domain-Embedded%20Systems-orange?style=flat-square" alt="Domain"/>
  <img src="https://img.shields.io/badge/IoT-Sensor%20Integration-blue?style=flat-square" alt="IoT"/>
  <img src="https://img.shields.io/badge/Real--Time-Processing-green?style=flat-square" alt="Real-Time"/>
</p>

---

<div align="center">

### 🎯 Portfolio-Grade Embedded Systems Project

> **Comprehensive distance measurement system demonstrating ultrasonic sensing, real-time signal processing, hardware–software integration, and multi-platform interfacing using Arduino UNO.**

**⭐ Perfect for academics, portfolio demonstrations, and embedded systems fundamentals**

</div>

---

## 📋 Table of Contents

- [🚀 Project Overview](#-project-overview)
- [✨ Key Features](#-key-features)
- [🎬 Demo](#-demo)
- [📦 Hardware Requirements](#-hardware-requirements)
- [🔌 Circuit Connections](#-circuit-connections)
- [🧠 Working Principle](#-working-principle)
- [💻 Software Setup](#-software-setup)
- [🚀 Quick Start Guide](#-quick-start-guide)
- [🔧 Customization](#-customization)
- [🎓 Learning Outcomes](#-learning-outcomes)
- [🌟 Use Cases](#-use-cases)
- [🐛 Troubleshooting](#-troubleshooting)
- [📊 Technical Specifications](#-technical-specifications)
- [🤝 Contributing](#-contributing)
- [📞 Connect](#-connect)

---

## 🚀 Project Overview

<div align="center">
  <table>
    <tr>
      <td align="center" width="33%">
        <img src="https://cdn-icons-png.flaticon.com/512/2942/2942813.png" width="80" height="80" alt="Sensors"/>
        <br><b>Real-Time Sensing</b>
        <br>10 Hz sampling rate with HC-SR04
      </td>
      <td align="center" width="33%">
        <img src="https://cdn-icons-png.flaticon.com/512/2165/2165004.png" width="80" height="80" alt="Integration"/>
        <br><b>Multi-Platform</b>
        <br>Arduino + Python integration
      </td>
      <td align="center" width="33%">
        <img src="https://img.icons8.com/office/100/Production-machine.png" width="80" height="80" alt="Professional"/>
        <br><b>Production Ready</b>
        <br>Clean, modular, documented
      </td>
    </tr>
  </table>
</div>

This project implements a **comprehensive distance measurement system** featuring:

- 🎯 **Real-time distance calculation** with visual LED feedback
- 🖥️ **Dual Python interface support** (GUI + Audio Alert System)
- 🔔 **Threshold-based object detection** and triggering
- 📡 **Serial communication protocol** for cross-platform integration

Designed to be **modular, deterministic, and interview-ready** — optimized for academic excellence and portfolio demonstrations.

---

## ✨ Key Features

<div align="center">

| Feature | Description |
|---------|-------------|
| ⚡ **Hardware-Software Integration** | Seamless Arduino-Python communication via UART |
| 🎨 **Multiple Output Modes** | Compatible with GUI and audio alert systems simultaneously |
| 🔄 **Real-time Processing** | 10 Hz sampling rate with precise distance calculation |
| 💡 **Visual Feedback** | LED indicator for proximity alerts (10-40 cm range) |
| 🧩 **Modular Design** | Easy to extend and customize for specific applications |
| 📝 **Professional Code** | Clean, well-documented, interview-ready implementation |

</div>

---

## 🎬 Demo

<div align="center">

### System Architecture

```
┌─────────────────┐         ┌──────────────────┐         ┌─────────────────┐
│   HC-SR04       │  GPIO   │   Arduino UNO    │  UART   │  Python Host    │
 │  Ultrasonic     │ ──────> │  Microcontroller │ ──────> │   Application   │ 
│    Sensor       │         │                  │         │   (GUI/Audio)   │
└─────────────────┘         └──────────────────┘         └─────────────────┘
│
▼
┌──────────────┐
│  LED Visual  │
│   Feedback   │
└──────────────┘
```

### Expected Output

**Serial Monitor (9600 baud):**
```
25.3
23.7
21.4
PLAY_AUDIO  ← Trigger sent when object in range
20.1
18.9
```

**LED Behavior:**
- 🟢 **OFF**: Distance > 40 cm or < 10 cm
- 🔴 **ON**: Distance between 10-40 cm (object detected)

</div>

---

## 📦 Hardware Requirements

<div align="center">

### Components List

<table>
  <tr>
    <th>Component</th>
    <th>Quantity</th>
    <th>Purpose</th>
    <th>Specifications</th>
  </tr>
  <tr>
    <td><img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/arduino/arduino-original.svg" width="20"/> Arduino UNO</td>
    <td align="center">1</td>
    <td>Microcontroller</td>
    <td>ATmega328P, 5V logic</td>
  </tr>
  <tr>
    <td>🔊 HC-SR04 Sensor</td>
    <td align="center">1</td>
    <td>Distance measurement</td>
    <td>2-400 cm range, 40 kHz</td>
  </tr>
  <tr>
    <td>💡 LED (any color)</td>
    <td align="center">1</td>
    <td>Visual indicator</td>
    <td>5mm, 20mA forward current</td>
  </tr>
  <tr>
    <td>🔌 220Ω Resistor</td>
    <td align="center">1</td>
    <td>LED current limiting</td>
    <td>1/4W, ±5% tolerance</td>
  </tr>
  <tr>
    <td>🔗 Jumper Wires</td>
    <td align="center">6+</td>
    <td>Connections</td>
    <td>Male-to-male</td>
  </tr>
  <tr>
    <td>🔌 USB Type-B Cable</td>
    <td align="center">1</td>
    <td>Programming & power</td>
    <td>Data-capable cable</td>
  </tr>
</table>

</div>

---

## 🔌 Circuit Connections

<div align="center">

### Pin Mapping

<table>
  <tr>
    <th colspan="3">HC-SR04 → Arduino UNO</th>
  </tr>
  <tr>
    <th>HC-SR04 Pin</th>
    <th>Arduino Pin</th>
    <th>Description</th>
  </tr>
  <tr>
    <td>VCC</td>
    <td>5V</td>
    <td>Power supply (+)</td>
  </tr>
  <tr>
    <td>GND</td>
    <td>GND</td>
    <td>Ground reference</td>
  </tr>
  <tr>
    <td>TRIG</td>
    <td>D9</td>
    <td>Trigger pulse input</td>
  </tr>
  <tr>
    <td>ECHO</td>
    <td>D10</td>
    <td>Echo pulse output</td>
  </tr>
</table>

<table>
  <tr>
    <th colspan="2">LED Circuit</th>
  </tr>
  <tr>
    <th>LED Terminal</th>
    <th>Connection</th>
  </tr>
  <tr>
    <td>Anode (+) [Long leg]</td>
    <td>D3 (via 220Ω resistor)</td>
  </tr>
  <tr>
    <td>Cathode (–) [Short leg]</td>
    <td>GND</td>
  </tr>
</table>

### Circuit Diagram

```
        ┌─────────────────────────────┐
        │      Arduino UNO            │
        │                             │
                      │  5V  ──────────────────────>│ VCC (HC-SR04)
                      │  GND ──────────────────────>│ GND (HC-SR04)
             │  D9  ──────────────────────>│ TRIG
             │  D10 <──────────────────────│ ECHO
        │                             │
            │  D3  ───[220Ω]───>│+LED−│──>│ GND
        │                             │
                 │  USB <──────────────────────│ Computer
        └─────────────────────────────┘
```

📌 **Note:** For visual circuit diagram, see `circuit_diagram.png` in repository

</div>

---

## 🧠 Working Principle

<div align="center">

### Distance Measurement Algorithm

</div>

<table>
<tr>
<td width="50%">

**Step-by-Step Process:**

1. **Trigger Phase**
   - Arduino sends 10µs HIGH pulse to TRIG pin

2. **Ultrasonic Emission**
   - HC-SR04 emits 8 pulses of 40 kHz ultrasonic waves

3. **Echo Detection**
   - Waves reflect from object and return to sensor

4. **Time Measurement**
   - ECHO pin stays HIGH for duration proportional to distance

5. **Distance Calculation**
   ```cpp
   Distance (cm) = (Duration × 0.0343) / 2
   ```

6. **Threshold Detection**
   - LED activates when distance is 10-40 cm

7. **Serial Output**
   - Distance values transmitted via UART (9600 baud)

</td>
<td width="50%">

**Mathematical Foundation:**

```
Speed of Sound in Air:
  343 m/s = 0.0343 cm/µs

Time-of-Flight:
  Total Time = Distance to Object × 2 / Speed

Distance Formula:
  Distance = (Time × Speed) / 2
  Distance = (Duration × 0.0343) / 2
```

**Why divide by 2?**
- Ultrasonic wave travels to object **and back**
- Measured time includes **round-trip travel**

**Measurement Range:**
- Minimum: **2 cm** (sensor limitation)
- Maximum: **400 cm** (signal attenuation)
- Accuracy: **±3 mm** (optimal conditions)

</td>
</tr>
</table>

---

## 💻 Software Setup

<div align="center">

### Arduino Development Environment

<table>
  <tr>
    <td align="center" width="33%">
      <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/arduino/arduino-original.svg" width="80" height="80" alt="Arduino"/>
      <br><b>Arduino IDE</b>
      <br>Version 1.8.x or 2.x
    </td>
    <td align="center" width="33%">
      <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" width="80" height="80" alt="C++"/>
      <br><b>Language</b>
      <br>C/C++ (Arduino Core)
    </td>
    <td align="center" width="33%">
      <img src="https://img.icons8.com/color/96/000000/console.png" width="80" height="80" alt="Serial"/>
      <br><b>Communication</b>
      <br>UART @ 9600 baud
    </td>
  </tr>
</table>

### Python Environment (Optional)

<table>
  <tr>
    <td align="center" width="25%">
      <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg" width="60" height="60" alt="Python"/>
      <br><b>Python 3.8+</b>
    </td>
    <td align="center" width="25%">
      <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg" width="60" height="60" alt="PySerial"/>
      <br><b>pyserial</b>
    </td>
    <td align="center" width="25%">
      <img src="https://img.icons8.com/color/96/000000/music.png" width="60" height="60" alt="Pygame"/>
      <br><b>pygame</b>
    </td>
    <td align="center" width="25%">
      <img src="https://img.icons8.com/color/96/000000/console.png" width="60" height="60" alt="Terminal"/>
      <br><b>Terminal</b>
    </td>
  </tr>
</table>

**Install Python dependencies:**
```bash
pip install pyserial pygame
```

</div>

---

## 🚀 Quick Start Guide

<div align="center">

### 📁 Step 1: Clone Repository

</div>

```bash
git clone https://github.com/aryan-r03/ultrasonic-distance-arduino.git
cd ultrasonic-distance-arduino
```

<div align="center">

### ⚡ Step 2: Upload Arduino Code

</div>

1. Open **Arduino IDE**
2. Load `arduino_sketch_simple.ino`
3. Connect Arduino UNO via USB
4. Configure IDE:
   - **Tools** → **Board** → **Arduino UNO**
   - **Tools** → **Port** → Select correct port
     - Windows: `COM3`, `COM4`, etc.
     - macOS: `/dev/cu.usbmodem*`
     - Linux: `/dev/ttyUSB0`, `/dev/ttyACM0`
5. Click **Upload** (→ button)
6. Wait for "Done uploading" message

<div align="center">

### 🔍 Step 3: Verify Operation

</div>

**Open Serial Monitor:** `Tools` → `Serial Monitor` (or `Ctrl+Shift+M`)

**Set to:** `9600 baud`

**Expected Output:**
```
25.3
23.7
21.4
PLAY_AUDIO    ← Trigger when object at 10-40 cm
20.1
18.9
```

**Physical Testing:**
1. Move hand/object in front of sensor
2. LED should illuminate when object is 10-40 cm away
3. "PLAY_AUDIO" appears in serial when LED is ON

<div align="center">

### 🐍 Step 4: Run Python Interfaces (Optional)

</div>

<table>
<tr>
<td width="50%">

**Option A: GUI Display**

```bash
python Distance_GUI.py
```

**Features:**
- 📊 Real-time distance visualization
- 🎨 Color-coded display:
  - 🟢 Green: >50 cm (Safe)
  - 🟡 Yellow: 20-50 cm (Caution)
  - 🔴 Red: <20 cm (Alert)
- 🔊 Text-to-speech announcements

</td>
<td width="50%">

**Option B: Audio Alert System**

```bash
python Distance_custom_audio.py
```

**Features:**
- 🎵 Listens for "PLAY_AUDIO" trigger
- 🔊 Plays sequential audio warnings
- ⏱️ 5-second cooldown between alerts
- 📁 Custom audio file support

</td>
</tr>
</table>

**⚠️ Important:** Update serial port in Python files:

```python
# macOS
SERIAL_PORT = "/dev/cu.usbmodem101"

# Linux
SERIAL_PORT = "/dev/ttyUSB0"

# Windows
SERIAL_PORT = "COM3"
```

---

## 🔧 Customization

<div align="center">

### Modify Detection Range

</div>

Edit in `arduino_sketch_simple.ino`:

```cpp
#define MIN_DISTANCE 10  // Minimum trigger distance (cm)
#define MAX_DISTANCE 40  // Maximum trigger distance (cm)

// Example: Detect objects 20-60 cm away
#define MIN_DISTANCE 20
#define MAX_DISTANCE 60
```

<div align="center">

### Adjust Sampling Rate

</div>

```cpp
delay(100);  // Current: 10 Hz (100ms interval)

// Faster sampling (20 Hz)
delay(50);

// Slower sampling (5 Hz)
delay(200);
```

<div align="center">

### Change Debounce Period

</div>

```cpp
#define DEBOUNCE_DELAY 1500  // Milliseconds between triggers

// Reduce trigger frequency (3 seconds)
#define DEBOUNCE_DELAY 3000

// Increase trigger frequency (1 second)
#define DEBOUNCE_DELAY 1000
```

<div align="center">

### Modify LED Behavior

</div>

```cpp
// Current: LED ON when object in range
digitalWrite(LED_PIN, HIGH);

// Inverse: LED OFF when object in range
digitalWrite(LED_PIN, LOW);

// Blinking LED
digitalWrite(LED_PIN, millis() % 500 < 250 ? HIGH : LOW);
```

---

## 🎓 Learning Outcomes

<div align="center">
  <table>
    <tr>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/integrated-circuit.png" width="60" height="60" alt="Embedded"/>
        <br><b>Embedded Systems</b>
        <br>
        <ul align="left">
          <li>Time-of-flight measurement</li>
          <li>GPIO & digital signals</li>
          <li>PWM concepts</li>
          <li>Real-time processing</li>
        </ul>
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/code.png" width="60" height="60" alt="Software"/>
        <br><b>Software Engineering</b>
        <br>
        <ul align="left">
          <li>Serial protocols (UART)</li>
          <li>Hardware-software integration</li>
          <li>Multi-platform design</li>
          <li>State machine implementation</li>
        </ul>
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/python.png" width="60" height="60" alt="Python"/>
        <br><b>Cross-Platform Dev</b>
        <br>
        <ul align="left">
          <li>Python serial communication</li>
          <li>GUI development</li>
          <li>Audio processing</li>
          <li>Real-time data handling</li>
        </ul>
      </td>
      <td align="center" width="25%">
        <img src="https://img.icons8.com/color/96/000000/technical-support.png" width="60" height="60" alt="Professional"/>
        <br><b>Professional Skills</b>
        <br>
        <ul align="left">
          <li>Clean, maintainable code</li>
          <li>Comprehensive documentation</li>
          <li>Modular architecture</li>
          <li>Version control practices</li>
        </ul>
      </td>
    </tr>
  </table>
</div>

---

## 🌟 Use Cases

<table>
<tr>
<td width="33%">

### 🎓 Academic & Learning
- 📚 Embedded systems labs
- 🔬 Microcontroller programming
- 🧪 Sensor integration demos
- 📊 Data acquisition projects

</td>
<td width="33%">

### 🚀 Practical Applications
- 🤖 **Robotics**: Navigation systems
- 🚗 **Automotive**: Parking assistance
- 🏠 **Smart Home**: Automated doors
- 🏭 **Industrial**: Presence detection
- 📡 **IoT**: Distance-based triggers

</td>
<td width="33%">

### 💼 Portfolio Enhancement
- ✅ Hardware-software integration
- ✅ Multi-language proficiency
- ✅ Professional documentation
- ✅ Real-world problem solving
- ✅ Interview-ready project

</td>
</tr>
</table>

---

## 🐛 Troubleshooting

<details>
<summary><b>❌ No Serial Output</b></summary>

**Solutions:**
- ✅ Check USB connection (use data-capable cable, not charge-only)
- ✅ Verify correct COM port selected in Arduino IDE
- ✅ Confirm baud rate is **9600** in Serial Monitor
- ✅ Check Arduino board selection: **Tools** → **Board** → **Arduino UNO**
- ✅ Try different USB port on computer
- ✅ Restart Arduino IDE

</details>

<details>
<summary><b>📏 Incorrect Distance Readings</b></summary>

**Solutions:**
- ✅ Verify HC-SR04 wiring:
  - VCC → 5V
  - GND → GND
  - TRIG → D9
  - ECHO → D10
- ✅ Ensure sensor has clear line of sight (no obstructions)
- ✅ Check 5V power supply is stable (measure with multimeter: 4.8-5.2V)
- ✅ Avoid angled surfaces (use flat, perpendicular objects)
- ✅ Don't use sound-absorbing materials (foam, fabric)
- ✅ Test at 20-50 cm distance first (optimal range)

</details>

<details>
<summary><b>💡 LED Not Working</b></summary>

**Solutions:**
- ✅ Check LED polarity:
  - Long leg (anode) → 220Ω resistor → D3
  - Short leg (cathode) → GND
- ✅ Verify 220Ω resistor is in series (not parallel)
- ✅ Confirm LED is not burnt out (test with battery)
- ✅ Check D3 pin connection
- ✅ Test with multimeter: LED should drop ~2V when ON

</details>

<details>
<summary><b>🐍 Python Script Connection Errors</b></summary>

**Solutions:**
- ✅ **Close Arduino Serial Monitor** before running Python (port conflict)
- ✅ Update `SERIAL_PORT` variable with correct port:
  ```python
  # Find your port:
  # Windows: Device Manager → Ports (COM & LPT)
  # macOS: ls /dev/cu.*
  # Linux: ls /dev/ttyUSB* /dev/ttyACM*
  ```
- ✅ Check port permissions (Linux/macOS):
  ```bash
  sudo chmod 666 /dev/ttyUSB0
  # or add user to dialout group:
  sudo usermod -a -G dialout $USER
  ```
- ✅ Install required libraries:
  ```bash
  pip install pyserial pygame
  ```
- ✅ Verify Python version: `python --version` (3.8+)

</details>

<details>
<summary><b>⚠️ Unstable/Fluctuating Readings</b></summary>

**Solutions:**
- ✅ Add smoothing/filtering in code:
  ```cpp
  // Moving average of last 5 readings
  float readings[5];
  float average = 0;
  for(int i = 0; i < 5; i++) {
    readings[i] = distance;
    average += readings[i];
  }
  average /= 5;
  ```
- ✅ Increase `DEBOUNCE_DELAY` to reduce noise
- ✅ Shield sensor from electromagnetic interference
- ✅ Use shielded cables for long wire runs
- ✅ Add decoupling capacitor (0.1µF) across VCC-GND

</details>

---

## 📊 Technical Specifications

<div align="center">

### System Performance

<table>
  <tr>
    <th>Parameter</th>
    <th>Value</th>
    <th>Notes</th>
  </tr>
  <tr>
    <td><b>Operating Voltage</b></td>
    <td>5V DC</td>
    <td>Regulated from USB (4.8-5.2V)</td>
  </tr>
  <tr>
    <td><b>Current Consumption</b></td>
    <td>~30mA</td>
    <td>Arduino (15mA) + HC-SR04 (15mA)</td>
  </tr>
  <tr>
    <td><b>Measurement Range</b></td>
    <td>2 cm - 400 cm</td>
    <td>Effective: 10-300 cm</td>
  </tr>
  <tr>
    <td><b>Accuracy</b></td>
    <td>±3 mm</td>
    <td>Under optimal conditions</td>
  </tr>
  <tr>
    <td><b>Resolution</b></td>
    <td>1 cm</td>
    <td>Limited by calculation</td>
  </tr>
  <tr>
    <td><b>Measurement Angle</b></td>
    <td>15° cone</td>
    <td>30° total beam width</td>
  </tr>
  <tr>
    <td><b>Ultrasonic Frequency</b></td>
    <td>40 kHz</td>
    <td>8 pulses per measurement</td>
  </tr>
  <tr>
    <td><b>Sampling Rate</b></td>
    <td>10 Hz</td>
    <td>100ms measurement cycle</td>
  </tr>
  <tr>
    <td><b>Serial Baud Rate</b></td>
    <td>9600</td>
    <td>UART, 8N1 configuration</td>
  </tr>
  <tr>
    <td><b>Response Time</b></td>
    <td><100 ms</td>
    <td>Total system latency</td>
  </tr>
</table>

### Environmental Conditions

<table>
  <tr>
    <th>Parameter</th>
    <th>Range</th>
  </tr>
  <tr>
    <td><b>Operating Temperature</b></td>
    <td>-10°C to 60°C</td>
  </tr>
  <tr>
    <td><b>Storage Temperature</b></td>
    <td>-20°C to 70°C</td>
  </tr>
  <tr>
    <td><b>Humidity</b></td>
    <td>10% - 90% RH (non-condensing)</td>
  </tr>
</table>

</div>

---

## 📂 Project Structure

```
ultrasonic-distance-arduino/
│
├── 📄 arduino_sketch_simple.ino          # Main Arduino sketch (RECOMMENDED)
├── 📄 arduino_sketch_compatible.ino      # Advanced mode-selectable version
│
├── 🐍 Distance_GUI.py                    # Real-time GUI display interface
├── 🐍 Distance_custom_audio.py           # Audio alert system
│
├── 🖼️ circuit_diagram.png                # Wiring diagram
├── 📖 README.md                          # This file
├── 📜 LICENSE                            # MIT License
│
└── 📁 audio_files/                       # Audio alerts (user-provided)
    ├── 🔊 audio_1.mp3
    ├── 🔊 audio_2.mp3
    └── 🔊 audio_3.mp3
```

---

## 🔄 Version History

<div align="center">

### Version Timeline

</div>

<table>
  <tr>
    <th>Version</th>
    <th>Date</th>
    <th>Changes</th>
  </tr>
  <tr>
    <td><b>v2.0</b><br><i>(Current)</i></td>
    <td>Jan 2025</td>
    <td>
      ✅ Added dual Python interface support<br>
      ✅ Implemented mode-selectable operation<br>
      ✅ Enhanced serial protocol<br>
      ✅ Improved documentation<br>
      ✅ Added troubleshooting guide
    </td>
  </tr>
  <tr>
    <td><b>v1.5</b></td>
    <td>Dec 2024</td>
    <td>
      ✅ Added debounce mechanism<br>
      ✅ Improved stability<br>
      ✅ Added configuration options
    </td>
  </tr>
  <tr>
    <td><b>v1.0</b></td>
    <td>Nov 2024</td>
    <td>
      ✅ Basic distance measurement<br>
      ✅ LED indicator<br>
      ✅ Serial output
    </td>
  </tr>
</table>

---

## 🤝 Contributing

<div align="center">

**Contributions are welcome!** Help improve this project:

</div>

1. 🍴 Fork the repository
2. 🌿 Create a feature branch
   ```bash
   git checkout -b feature/enhancement
   ```
3. ✍️ Commit your changes
   ```bash
   git commit -m 'Add amazing enhancement'
   ```
4. 📤 Push to the branch
   ```bash
   git push origin feature/enhancement
   ```
5. 🔀 Open a Pull Request

<div align="center">

### Contribution Guidelines

</div>

- 📝 Follow existing code style
- ✅ Test thoroughly before submitting
- 📖 Update documentation for new features
- 🐛 Include issue number in PR description
- 💬 Provide clear commit messages

---

## 📄 License

<div align="center">

This project is licensed under the **MIT License**

See [LICENSE](LICENSE) file for complete details

</div>

```
MIT License - Free to use, modify, and distribute
Attribution appreciated but not required
```

---

## 👨‍💻 Author

<div align="center">

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=24&pause=1000&color=22C55E&center=true&vCenter=true&width=435&lines=Created+by+Aryan+Ranjan;Embedded+Systems+Engineer;ML+%26+IoT+Developer" alt="Author Typing SVG" />

<br>

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/aryan-r03">
        <img src="https://img.shields.io/badge/GitHub-aryan--r03-181717?style=for-the-badge&logo=github" alt="GitHub"/>
      </a>
    </td>
    <td align="center">
      <a href="https://linkedin.com/in/aryan-ranjan03">
        <img src="https://img.shields.io/badge/LinkedIn-aryan--ranjan03-0A66C2?style=for-the-badge&logo=linkedin" alt="LinkedIn"/>
      </a>
    </td>
  </tr>
  <tr>
    <td align="center">
      <a href="mailto:aryanr.ranjan@gmail.com">
        <img src="https://img.shields.io/badge/Email-Contact-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email"/>
      </a>
    </td>
    <td align="center">
      <a href="https://instagram.com/__aryan_.r03">
        <img src="https://img.shields.io/badge/Instagram-Follow-E4405F?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram"/>
      </a>
    </td>
  </tr>
</table>

<br>

**🎓 Computer Applications in AI & ML**
<br>
**Building at the intersection of hardware and software**

</div>

---

## 🙏 Acknowledgments

<div align="center">

Special thanks to:

- 🌐 **Arduino Community** for comprehensive documentation
- 📘 **HC-SR04 Datasheet Authors** for technical specifications
- 🐍 **PySerial & Pygame Contributors** for Python libraries
- 👥 **Open Source Community** for continuous inspiration

</div>

---

## 📞 Support & Contact

<div align="center">

### Need Help?

<table>
  <tr>
    <td align="center" width="33%">
      <a href="https://github.com/aryan-r03/ultrasonic-distance-arduino/issues"></a>
      <img src="https://img.icons8.com/color/96/000000/github.png" width="60" height="60" alt="GitHub"/>
      <br><b>Open an Issue</b>
      <br><b>GitHub Issues</b>
    </td>
    <td align="center" width="33%">
      <a href="mailto:aryanr.ranjan@gmail.com">
      <img src="https://img.icons8.com/color/96/000000/email.png" width="60" height="60" alt="Email"/>
      <br><b>Email</b>
    </td>
    <td align="center" width="33%">
      <img src="https://img.icons8.com/color/96/000000/document.png" width="60" height="60" alt="Docs"/>
      <br><b>Documentation</b>
      <br>See README & Code Comments
    </td>
  </tr>
</table>

<br>

</div>

---

<div align="center">

## 🌟 Show Your Support

**If this project helped you, please consider:**

<a href="https://github.com/aryan-r03/ultrasonic-distance-arduino">
  <img src="https://img.shields.io/github/stars/aryan-r03/ultrasonic-distance-arduino?style=social" alt="GitHub stars"/>
</a>
<a href="https://github.com/aryan-r03/ultrasonic-distance-arduino/fork">
  <img src="https://img.shields.io/github/forks/aryan-r03/ultrasonic-distance-arduino?style=social" alt="GitHub forks"/>
</a>
<a href="https://github.com/aryan-r03/ultrasonic-distance-arduino/watchers">
  <img src="https://img.shields.io/github/watchers/aryan-r03/ultrasonic-distance-arduino?style=social" alt="GitHub watchers"/>
</a>

<br><br>

**⭐ Star this repository if you found it helpful!**

**🍴 Fork it to customize for your projects!**

**📢 Share it with others learning embedded systems!**

</div>

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=100&section=footer" alt="Footer"/>

<br>

<i>💡 "Hardware is hard. Software is soft. Integration is magic."</i>

<br><br>

**Made with Arduino** by [Aryan Ranjan](https://github.com/aryan-r03)

<br>

![Profile Views](https://komarev.com/ghpvc/?username=aryan-r03&label=Project%20Views&color=0e75b6&style=flat)

<br>

---

**© 2025 Aryan Ranjan | Open Source | IoT & Embedded Systems **

</div>
