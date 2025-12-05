# LoRaSense – Wiring Diagrams

This folder contains all wiring references for building both the sensor node and gateway.

## 📁 Files
- `schematic.jpg` (optional)
- `wiring_diagram.png` (full wiring image)

## 📡 Sensor Node Wiring
Components connected to XIAO ESP32-C3:
- DHT22 → D4
- MQ135 → A0
- Sound Sensor → A1
- LoRa Module RX/TX → Pins 6/7
- Power from 5V boost converter

## 📶 Gateway Wiring
ESP32 Dev Board:
- LoRa Module → GPIO 16/17
- OLED Display → GPIO 21/22 (I2C)

Refer to `wiring_diagram.png` for full colored connections.

