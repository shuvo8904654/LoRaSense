// firmware/gateway/main.cpp

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --------- OLED CONFIG ---------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1    // Not used with I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// --------- LORA UART CONFIG ---------
HardwareSerial LoRaSerial(2); // Use UART2 on ESP32

// Adjust these pins to match your wiring to the Reyax module
#define LORA_RX_PIN   16   // ESP32 pin connected TO Reyax TX
#define LORA_TX_PIN   17   // ESP32 pin connected TO Reyax RX
#define LORA_BAUD     115200

// --------- GLOBALS ---------
String loRaInput;

// Parsed sensor values
float gTemp   = 0.0;
float gHumid  = 0.0;
int   gNoise  = 0;
int   gMQ     = 0;

// --------- FORWARD DECLS ---------
void updateDisplay();
void parsePayload(const String &payload);
void handleLoRaLine(const String &line);

// --------- SETUP ---------

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println("LoRaSense Gateway starting...");

  // Init LoRa serial
  LoRaSerial.begin(LORA_BAUD, SERIAL_8N1, LORA_RX_PIN, LORA_TX_PIN);
  delay(500);

  // Init OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("[OLED] SSD1306 allocation failed!");
  } else {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("LoRaSense Gateway");
    display.display();
  }

  delay(1000);
}

// --------- LOOP ---------

void loop() {
  // Read from LoRa UART line-by-line
  while (LoRaSerial.available()) {
    char c = LoRaSerial.read();
    if (c == '\r') continue;   // ignore CR
    if (c == '\n') {
      if (loRaInput.length() > 0) {
        handleLoRaLine(loRaInput);
        loRaInput = "";
      }
    } else {
      loRaInput += c;
    }
  }

  // You can periodically push to cloud here (HTTP POST, etc.)
  // uploadToCloud(gTemp, gHumid, gNoise, gMQ);

  delay(10);
}

// --------- LoRa Handling ---------

void handleLoRaLine(const String &line) {
  Serial.print("[LoRa RAW] ");
  Serial.println(line);

  // Reyax RYLR998 receives data like:
  // +RCV=0,<len>,<payload>,<RSSI>,<SNR>
  if (line.startsWith("+RCV=")) {
    // Find the third comma (start of payload)
    int firstComma  = line.indexOf(',');
    int secondComma = line.indexOf(',', firstComma + 1);
    int thirdComma  = line.indexOf(',', secondComma + 1);
    if (thirdComma == -1) {
      Serial.println("[LoRa] Malformed +RCV line");
      return;
    }

    String payload = line.substring(secondComma + 1, thirdComma); // might still contain length, so we refine
    // Actually line format: +RCV=addr,len,payload,RSSI,SNR
    // So better:
    //   part after second comma up to third comma = payload string
    payload = line.substring(secondComma + 1, thirdComma);

    Serial.print("[LoRa PAYLOAD] ");
    Serial.println(payload);

    parsePayload(payload);
    updateDisplay();
  } else {
    // Other responses from module (OK, etc.)
    Serial.print("[LoRa INFO] ");
    Serial.println(line);
  }
}

// --------- CSV Payload Parsing ---------
// Expected: temp,humid,noise,mq

void parsePayload(const String &payload) {
  int c1 = payload.indexOf(',');
  int c2 = payload.indexOf(',', c1 + 1);
  int c3 = payload.indexOf(',', c2 + 1);

  if (c1 == -1 || c2 == -1 || c3 == -1) {
    Serial.println("[Parse] Invalid CSV payload");
    return;
  }

  String sTemp  = payload.substring(0,   c1);
  String sHumid = payload.substring(c1 + 1, c2);
  String sNoise = payload.substring(c2 + 1, c3);
  String sMQ    = payload.substring(c3 + 1);

  gTemp  = sTemp.toFloat();
  gHumid = sHumid.toFloat();
  gNoise = sNoise.toInt();
  gMQ    = sMQ.toInt();

  Serial.println("[Parsed]");
  Serial.print("  Temp  : "); Serial.println(gTemp);
  Serial.print("  Humid : "); Serial.println(gHumid);
  Serial.print("  Noise : "); Serial.println(gNoise);
  Serial.print("  MQ135 : "); Serial.println(gMQ);
}

// --------- OLED DISPLAY ---------

void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);

  display.println("LoRaSense Gateway");
  display.println("-----------------");
  display.print("Temp : "); display.print(gTemp, 1); display.println(" C");
  display.print("Humid: "); display.print(gHumid, 1); display.println(" %");
  display.print("Noise: "); display.print(gNoise);    display.println(" raw");
  display.print("MQ135: "); display.print(gMQ);       display.println(" raw");

  display.display();
}

