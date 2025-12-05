// firmware/sensor_node/main.cpp

#include <Arduino.h>
#include <DHT.h>

// ------------- CONFIGURATION -------------

// DHT sensor
#define DHTPIN        4       // GPIO for DHT data pin (change if needed)
#define DHTTYPE       DHT22   // DHT11 or DHT22

// Analog pins for sensors (change to match your board)
#define MQ135_PIN     A0
#define SOUND_PIN     A1

// LoRa UART pins for XIAO ESP32-C3
// Change these to match how you wired TX/RX to the Reyax module
#define LORA_RX_PIN   7   // XIAO pin connected TO Reyax TX
#define LORA_TX_PIN   6   // XIAO pin connected TO Reyax RX

// LoRa settings
#define LORA_BAUD     115200
#define LORA_TARGET_ADDR  0   // 0 = broadcast to all / default

// Measurement interval
// If you enable deep sleep, this will be the sleep duration:
const uint32_t MEASURE_INTERVAL_MS = 15000; // 15 seconds

// ------------- GLOBALS -------------

DHT dht(DHTPIN, DHTTYPE);
HardwareSerial LoRaSerial(1); // UART1 on ESP32C3

// ------------- HELPER FUNCTIONS -------------

void initLoRa() {
  // Start UART for LoRa
  LoRaSerial.begin(LORA_BAUD, SERIAL_8N1, LORA_RX_PIN, LORA_TX_PIN);

  delay(500);

  // Optional: configure module (band, network id, etc.)
  // These depend on your country and settings; defaults usually work for testing.
  // Example (uncomment and adapt if needed):
  // LoRaSerial.println("AT+IPR=115200"); // set baud rate
  // delay(200);
  // LoRaSerial.println("AT+ADDRESS=1");
  // delay(200);
  // LoRaSerial.println("AT+NETWORKID=18");
  // delay(200);
}

void sendLoRaPayload(const String &payload) {
  // Format: AT+SEND=<address>,<length>,<data>
  String cmd = "AT+SEND=";
  cmd += String(LORA_TARGET_ADDR);
  cmd += ",";
  cmd += String(payload.length());
  cmd += ",";
  cmd += payload;

  LoRaSerial.println(cmd);
  Serial.print("[LoRa] Sending: ");
  Serial.println(cmd);
}

// ------------- SETUP -------------

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println("LoRaSense Sensor Node starting...");

  dht.begin();
  initLoRa();

  // Small delay to let LoRa module boot
  delay(1000);
}

// ------------- LOOP -------------

void loop() {
  // 1) Read temperature & humidity
  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  // DHT read can fail, check for NaN
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("[DHT] Failed to read from DHT sensor!");
    temperature = -1000.0;
    humidity    = -1.0;
  }

  // 2) Read air quality (MQ135)
  int mqRaw = analogRead(MQ135_PIN);

  // 3) Read sound level
  int soundRaw = analogRead(SOUND_PIN);

  // 4) (Optional) Convert raw values to more meaningful scales
  // For now we just send raw ADC values.
  // You can calibrate MQ135 and sound later.

  // 5) Build CSV payload: temp,humidity,sound,mq135
  String payload =
    String(temperature, 2) + "," +
    String(humidity, 2)    + "," +
    String(soundRaw)       + "," +
    String(mqRaw);

  Serial.print("[Sensor] Payload: ");
  Serial.println(payload);

  // 6) Send via LoRa
  sendLoRaPayload(payload);

  // 7) Wait or deep sleep

  // Simple delay version:
  delay(MEASURE_INTERVAL_MS);

  // Deep sleep version (uncomment if you want deep sleep mode):
  /*
  Serial.println("[Power] Going to deep sleep...");
  delay(100);

  // Convert ms to microseconds
  uint64_t sleepTimeUs = (uint64_t)MEASURE_INTERVAL_MS * 1000ULL;

  esp_sleep_enable_timer_wakeup(sleepTimeUs);
  esp_deep_sleep_start();
  */
}

