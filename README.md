# IoT Smart Streetlight System with ESP32 & ThingSpeak
An automated, cloud-connected IoT project built for the ESP32. This system monitors ambient light levels using a Light Dependent Resistor (LDR), automatically controls an LED (simulating a streetlight), and logs real-time brightness data to the cloud via the ThingSpeak platform.
#🛠️ Hardware Requirements (or Wokwi Equivalents)
Microcontroller: ESP32 Development Board
Sensors: LDR (Photoresistor) Module
Actuators: 5V/3.3V LED (with a 
220
Ω
 current-limiting resistor)
Hookup: Breadboard and jumper wires
#  Software & Cloud Setup
1. ThingSpeak Configuration
Sign up or log into ThingSpeak.
Create a New Channel.
Enable Field 1 and name it something descriptive (e.g., Ambient Light Level).
Navigate to the API Keys tab and copy your Channel ID and Write API Key.
3. Code Customization
Open the code and replace the placeholder values with your specific ThingSpeak credentials:

unsigned long myChannelNumber = YOUR_CHANNEL_ID;  // Replace with your actual Channel ID
const char* myApiKey = "YOUR_WRITE_API_KEY";     // Replace with your actual Write API Key
