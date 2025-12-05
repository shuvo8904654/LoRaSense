<h1>📡 <strong>LoRaSense — Solar-Powered LoRa Environmental Monitoring System</strong></h1>

<p>
LoRaSense is a <strong>low-cost, long-range, solar-powered environmental monitoring system</strong> 
designed to track <strong>air quality, temperature, humidity, and noise pollution</strong> across large areas.  
Each sensor node runs on <strong>solar energy</strong>, communicates using <strong>LoRa</strong>, and sends data to a central 
<strong>ESP32 gateway</strong> that uploads readings to a cloud dashboard and performs optional 
<strong>AI anomaly detection</strong>.
</p>

<p>
This project demonstrates <strong>IoT engineering, wireless networking, 3D design, solar power systems, 
and embedded firmware development</strong>, making it ideal for Hack Club Blueprint (Tier 3).
</p>

<hr>

<h2>🚀 <strong>Features</strong></h2>

<h3>✔ Sensor Node (Solar Powered)</h3>
<ul>
  <li>🌡️ Temperature measurement</li>
  <li>💧 Humidity measurement</li>
  <li>🌫️ Air Quality (MQ135)</li>
  <li>🔊 Noise Level (sound sensor)</li>
  <li>Solar + 18650 battery powered</li>
  <li>XIAO ESP32-C3 ultra-low power MCU</li>
  <li>LoRa communication using RYLR998</li>
  <li>Deep sleep for extended battery life</li>
  <li>Weather-resistant 3D printed enclosure</li>
</ul>

<h3>✔ Gateway Node</h3>
<ul>
  <li>Receives LoRa packets</li>
  <li>ESP32 Dev Board</li>
  <li>Displays data on 0.96" OLED</li>
  <li>Uploads to Supabase / Thingspeak</li>
  <li>Optional TinyML anomaly detection (Edge Impulse)</li>
</ul>

<h3>✔ Dashboard</h3>
<ul>
  <li>Real-time graphs (AQI, temperature, humidity, noise)</li>
  <li>24h & weekly trends</li>
  <li>Alerts for pollution spikes</li>
  <li>Node status and battery health</li>
</ul>

<hr>

<h2>🧱 <strong>System Architecture</strong></h2>

<pre>
[SOLAR SENSOR NODE]
 - XIAO ESP32C3
 - MQ135 Air Sensor
 - DHT11/DHT22
 - Sound Sensor
 - LoRa Module RYLR998
 - Solar + 18650 + Charger Board
            |
            | LoRa Communication
            v
[GATEWAY NODE]
 - ESP32 Dev Kit
 - LoRa Receiver
 - OLED Display
 - WiFi Cloud Uplink
            |
            | HTTPS / WebSocket
            v
[CLOUD DASHBOARD]
 - Supabase / Thingspeak
 - Visualization + Alerts
</pre>

<p><strong>Architecture diagram:</strong> <code>docs/system_architecture.png</code></p>

<hr>

<h2>🧪 <strong>Motivation</strong></h2>
<p>
Air pollution and noise pollution are major problems in many cities. Existing monitoring systems 
are expensive and limited.  
<strong>LoRaSense provides a scalable, affordable solution</strong> that can be deployed anywhere.
</p>

<hr>

<h2>🛠️ <strong>Bill of Materials (BOM)</strong></h2>

<table>
<thead>
<tr><th>Component</th><th>Qty</th><th>Price</th><th>Notes</th></tr>
</thead>
<tbody>
<tr><td>Seeed XIAO ESP32-C3</td><td>1</td><td>$5</td><td>Sensor node MCU</td></tr>
<tr><td>Reyax RYLR998 LoRa Module</td><td>2</td><td>$24</td><td>Node + gateway</td></tr>
<tr><td>MQ135 Air Quality Sensor</td><td>1</td><td>$4</td><td>Measures gases</td></tr>
<tr><td>DHT11 / DHT22</td><td>1</td><td>$3</td><td>Temperature + humidity</td></tr>
<tr><td>Sound Sensor</td><td>1</td><td>$3</td><td>Noise measurement</td></tr>
<tr><td>Solar Panel (0.5–1W)</td><td>1</td><td>$3</td><td>Renewable power</td></tr>
<tr><td>18650 Battery</td><td>1</td><td>$3</td><td>Power storage</td></tr>
<tr><td>TP4056 Charger + Boost</td><td>1</td><td>$2</td><td>Battery charging</td></tr>
<tr><td>ESP32 Dev Board</td><td>1</td><td>$6</td><td>Gateway MCU</td></tr>
<tr><td>OLED 0.96" Display</td><td>1</td><td>$6</td><td>Live readings</td></tr>
<tr><td>3D Printed Case</td><td>1</td><td>FREE</td><td>Blueprint reimbursed</td></tr>
</tbody>
</table>

<p><strong>Total Cost: ~ $62 (Fits Tier 3)</strong></p>

<hr>

<h2>📂 <strong>Repository Structure</strong></h2>

<pre>
LoRaSense/
│
├── firmware/
│   ├── sensor_node/
│   │   ├── main.cpp
│   │   └── README.md
│   │
│   └── gateway/
│       ├── main.cpp
│       └── README.md
│
├── hardware/
│   ├── case/
│   │   ├── LoRaSense_Top.stl
│   │   ├── LoRaSense_Bottom.stl
│   │   └── README.md
│   │
│   └── wiring/
│       ├── schematic.jpg
│       └── wiring_diagram.png
│
├── docs/
│   ├── system_architecture.png
│   └── project_plan.md
│
├── .gitignore
├── LICENSE
└── README.md
</pre>

<hr>

<h2>🔧 <strong>Firmware Overview</strong></h2>

<h3>Sensor Node (XIAO ESP32-C3)</h3>
<ul>
  <li>Reads all sensors</li>
  <li>Packages values into LoRa payload</li>
  <li>Sends data periodically</li>
  <li>Deep sleep enabled</li>
</ul>

<h3>Gateway (ESP32)</h3>
<ul>
  <li>Receives LoRa packets via UART</li>
  <li>Parses CSV payload</li>
  <li>Displays info on OLED</li>
  <li>Uploads to cloud backend</li>
  <li>Runs TinyML anomaly detection</li>
</ul>

<hr>

<h2>📦 <strong>3D Printed Enclosure</strong></h2>
<p>Files located in:</p>

<pre>
hardware/case/
</pre>

<ul>
  <li>LoRaSense_Top.stl</li>
  <li>LoRaSense_Bottom.stl</li>
</ul>

<p>The enclosure includes:</p>
<ul>
  <li>Solar panel mount</li>
  <li>Ventilation slots</li>
  <li>Sensor openings</li>
  <li>Battery compartment</li>
</ul>

<hr>

<h2>📊 <strong>Dashboard</strong></h2>
<p>Supports:</p>
<ul>
  <li>Real-time monitoring</li>
  <li>Historical trends</li>
  <li>Pollution spike alerts</li>
  <li>Battery health & node status</li>
</ul>

<hr>

<h2>🎯 <strong>Project Goals</strong></h2>
<ul>
  <li>Build scalable environmental sensor nodes</li>
  <li>Use LoRa for long-range communication</li>
  <li>Create solar-powered autonomous hardware</li>
  <li>Deploy cloud dashboard</li>
  <li>Integrate TinyML anomaly detection</li>
  <li>Fully document all systems</li>
</ul>

<hr>

<h2>🚧 <strong>Current Status</strong></h2>
<ul>
  <li>✔ Architecture completed</li>
  <li>✔ Repository structure created</li>
  <li>⬜ Sensor node firmware</li>
  <li>⬜ Gateway firmware</li>
  <li>⬜ Wiring diagrams</li>
  <li>⬜ 3D case design</li>
  <li>⬜ Dashboard setup</li>
</ul>

<hr>

<h2>🤝 <strong>Contributions</strong></h2>
<p>Pull requests are welcome!  
This project is open source under the <strong>MIT License</strong>.</p>

