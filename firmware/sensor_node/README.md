# LoRaSense – Sensor Node Firmware

This folder contains the firmware for the **solar-powered LoRaSense environmental sensor node**.

## 📡 Features
- Reads temperature & humidity (DHT22)
- Reads air quality (MQ135)
- Reads noise level (analog mic)
- Sends data via LoRa (Reyax RYLR998)
- Uses deep sleep to save battery
- Designed for XIAO ESP32-C3

## 📁 Files
- `main.cpp` → Main firmware for the sensor node
- `config.h` (optional) → Pin mappings and settings

## 🔌 Hardware Used
- Seeed XIAO ESP32-C3
- MQ135 Gas Sensor
- DHT22 Temperature/Humidity Sensor
- Analog Sound Sensor
- Reyax RYLR998 LoRa Module
- Solar Panel + TP4056 + 18650 Battery

## 🔧 Setup
1. Install Arduino IDE
2. Add ESP32 Board Manager
3. Select: **XIAO ESP32-C3**
4. Install libraries:
   - DHT sensor library
   - U8g2 (optional)
   - Arduino LoRa/serial libraries

## 🚀 Upload
Connect the XIAO and upload:


