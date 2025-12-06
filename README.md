<h1><strong>LoRaSense — Solar Powered LoRa Environmental Monitoring System</strong></h1>

<p>
LoRaSense is a project I built to collect environmental data over long distances using LoRa.
Each sensor node runs on a small solar setup and sends measurements like temperature, humidity,
air quality, and noise level to a central ESP32 gateway. The gateway forwards everything to a cloud
dashboard. I also experimented with simple anomaly detection for unusual readings.
</p>

<p>
This project covers several areas: IoT, low-power hardware, wireless communication,
firmware development, and 3D printed enclosures. It fits well as a Blueprint Tier 3 project.
</p>

<hr>

<h2><strong>Features</strong></h2>

<h3>Sensor Node (Solar Powered)</h3>
<ul>
  <li>Temperature readings</li>
  <li>Humidity readings</li>
  <li>Air quality using MQ135</li>
  <li>Noise level sensing</li>
  <li>Solar powered with 18650 battery</li>
  <li>Runs on XIAO ESP32-C3</li>
  <li>LoRa communication using RYLR998</li>
  <li>Deep sleep for lower power use</li>
  <li>3D printed outdoor enclosure</li>
</ul>

<h3>Gateway Node</h3>
<ul>
  <li>Receives LoRa packets</li>
  <li>Built with ESP32 Dev Board</li>
  <li>Shows readings on a small OLED</li>
  <li>Sends data to the cloud dashboard</li>
  <li>Supports lightweight anomaly detection</li>
</ul>

<h3>Dashboard</h3>
<ul>
  <li>Real-time sensor readings</li>
  <li>Daily and weekly trends</li>
  <li>Alerts for sudden changes</li>
  <li>Battery and node status</li>
</ul>

<hr>

<h2><strong>System Architecture</strong></h2>

<pre>
[SENSOR NODE]
 - XIAO ESP32C3
 - MQ135 sensor
 - DHT11/DHT22
 - Sound sensor
 - RYLR998 LoRa module
 - Solar panel + 18650 battery

        LoRa

[GATEWAY]
 - ESP32 Dev Kit
 - LoRa receiver
 - OLED display
 - WiFi to cloud

[CLOUD]
 - Supabase or Thingspeak
 - Graphs and alerts
</pre>

<p>Architecture image: docs/system_architecture.png</p>

<hr>

<h2><strong>Motivation</strong></h2>

<p>
Air and noise pollution are common problems but proper monitoring systems are usually expensive
and hard to deploy. I wanted to see if it was possible to build something simple, low-cost,
and easy to install in many locations. LoRaSense was made with that idea in mind.
</p>

<hr>

<h2><strong>Bill of Materials (BOM)</strong></h2>

<table>
<thead>
<tr><th>Component</th><th>Qty</th><th>Price</th><th>Notes</th></tr>
</thead>
<tbody>
<tr><td>Seeed XIAO ESP32-C3</td><td>1</td><td>$5</td><td>MCU for the sensor node</td></tr>
<tr><td>Reyax RYLR998 LoRa Module</td><td>2</td><td>$24</td><td>Used for node and gateway</td></tr>
<tr><td>MQ135 Sensor</td><td>1</td><td>$4</td><td>Air quality</td></tr>
<tr><td>DHT11 or DHT22</td><td>1</td><td>$3</td><td>Temperature and humidity</td></tr>
<tr><td>Sound Sensor</td><td>1</td><td>$3</td><td>Noise level</td></tr>
<tr><td>Solar Panel</td><td>1</td><td>$3</td><td>Powers the node</td></tr>
<tr><td>18650 Battery</td><td>1</td><td>$3</td><td>Energy storage</td></tr>
<tr><td>TP4056 Charger Module</td><td>1</td><td>$2</td><td>Battery charging</td></tr>
<tr><td>ESP32 Dev Board</td><td>1</td><td>$6</td><td>Gateway MCU</td></tr>
<tr><td>0.96 inch OLED Display</td><td>1</td><td>$6</td><td>Shows readings</td></tr>
<tr><td>3D Printed Case</td><td>1</td><td>Free</td><td>Printed through Blueprint</td></tr>
</tbody>
</table>

<p>Total cost is around $62.</p>

<hr>

<h2><strong>Repository Structure</strong></h2>

<pre>
LoRaSense/
├── firmware/
│   ├── sensor_node/
│   └── gateway/
├── hardware/
│   ├── case/
│   └── wiring/
├── docs/
└── README.md
</pre>

<hr>

<h2><strong>Firmware Overview</strong></h2>

<h3>Sensor Node</h3>
<ul>
  <li>Reads each sensor</li>
  <li>Creates a simple packet</li>
  <li>Sends the data through LoRa</li>
  <li>Goes into deep sleep until the next cycle</li>
</ul>

<h3>Gateway</h3>
<ul>
  <li>Listens for LoRa packets</li>
  <li>Breaks down the incoming data</li>
  <li>Shows values on the OLED</li>
  <li>Uploads readings to the cloud</li>
  <li>Runs a basic anomaly detection model</li>
</ul>

<hr>

<h2><strong>3D Printed Enclosure</strong></h2>

<p>Case files are inside:</p>

<pre>
hardware/case/
</pre>

<ul>
  <li>LoRaSense_Top.stl</li>
  <li>LoRaSense_Bottom.stl</li>
</ul>

<p>
The enclosure includes space for the solar panel, the sensors, and the battery.
There are openings for airflow and sensor exposure.
</p>

<hr>

<h2><strong>Dashboard</strong></h2>

<p>The dashboard shows:</p>

<ul>
  <li>Live readings</li>
  <li>History over time</li>
  <li>Alerts for unusual spikes</li>
  <li>Battery and node health</li>
</ul>

<hr>

<h2><strong>Project Goals</strong></h2>

<ul>
  <li>Create simple outdoor sensor nodes</li>
  <li>Use LoRa for long range data transmission</li>
  <li>Run everything from solar power</li>
  <li>Build a working dashboard</li>
  <li>Add basic anomaly detection</li>
  <li>Document the whole system</li>
</ul>

<hr>

<h2><strong>Current Status</strong></h2>

<ul>
  <li>Architecture done</li>
  <li>Firmware for both boards completed</li>
  <li>Wiring diagrams done</li>
  <li>3D enclosure finished</li>
  <li>Dashboard is still in progress</li>
</ul>

<hr>

<h2><strong>Contributions</strong></h2>

<p>
The project is open source and licensed under MIT.
Pull requests and improvements are welcome.
</p>
