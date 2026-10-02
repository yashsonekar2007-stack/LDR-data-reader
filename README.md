# IoT Smart Streetlight System with ESP32 & ThingSpeak
An automated, cloud-connected IoT project built for the ESP32. This system monitors ambient light levels using a Light Dependent Resistor (LDR), automatically controls an LED (simulating a streetlight), and logs real-time brightness data to the cloud via the ThingSpeak platform.
# 🛠️ Hardware Requirements (or Wokwi Equivalents)
Microcontroller: ESP32 Development Board 
<br>
Sensors: LDR (Photoresistor) Module
<br>
Actuators: 5V/3.3V LED (with a 
220
 current-limiting resistor)
 <br>
Hookup: Breadboard and jumper wires
# 🚀 Features
Smart Automation: Automatically toggles the LED based on a customizable brightness threshold. <br>
Cloud Logging: Uploads real-time sensory data to ThingSpeak every 15 seconds.<br>
Virtual WiFi Support: Configured to seamlessly connect to Wokwi's virtual WiFi access point.<br>
Serial Diagnostics: Outputs clear debugging information to the Serial Monitor.<br>
