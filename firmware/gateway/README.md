# LoRaSense – Gateway Firmware

This folder contains the firmware for the **LoRa receiver gateway**, which processes messages from all sensor nodes.

## 📡 Features
- Receives LoRa packets from sensor nodes
- Parses CSV payloads
- Displays readings on OLED
- Sends data to a cloud dashboard (Supabase / Thingspeak)
- Optional: TinyML anomaly detection

## 📁 Files
- `main.cpp` → Main gateway firmware
- `config.h` (optional)

## 🔌 Hardware Used
- ESP32 Dev Board
- Reyax RYLR998 LoRa Module
- SSD1306 OLED Display (I2C)

## 🔧 Pin Mapping
| Component | Pin |
|----------|-----|
| LoRa RX | GPIO 17 |
| LoRa TX | GPIO 16 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |

## 🚀 Upload
1. Install ESP32 board package.
2. Select **ESP32 Dev Module**
3. Upload with:


