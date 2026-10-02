#include <WiFi.h>
#include "ThingSpeak.h"

// Wokwi Virtual WiFi Credentials
const char* WIFI_NAME = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

// ThingSpeak Details
unsigned long myChannelNumber = 3395420;    // <-- Replace with your Channel ID
const char* myApiKey = "T5ZSJ0VRK8XOB2RA"; // <-- Replace with your Write API Key
const char* server = "GET https://api.thingspeak.com/update?api_key=T5ZSJ0VRK8XOB2RA&field1=0";

// Hardware Pin Definitions
const int LDR_PIN = 34;  // LDR Analog Pin
const int LED_PIN = 13;  // LED Digital Pin

// Automation Threshold
// ESP32 ADC reads 0 (Dark) to 4095 (Bright)
// You can adjust this number based on when you want the light to trigger
const int LDR_THRESHOLD = 1500; 

WiFiClient client;

void setup() {
  Serial.begin(115200);
  
  // Set Pin Modes
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // Connect to Wokwi's virtual WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read the analog value from the LDR module
  int ldrValue = analogRead(LDR_PIN);
  Serial.print("Current Light Value: ");
  Serial.println(ldrValue);

  // SMART AUTOMATION LOGIC:
  // If it's dark (value is less than threshold), turn ON the LED
  if (ldrValue < LDR_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("-> It's DARK: LED turned ON!");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("-> It's BRIGHT: LED turned OFF!");
  }

  // Update Field 1 of your ThingSpeak Channel
  ThingSpeak.setField(1, ldrValue);
  
  // Upload to ThingSpeak
  int responseCode = ThingSpeak.writeFields(myChannelNumber, myApiKey);
  if (responseCode == 200) {
    Serial.println("ThingSpeak update successful.");
  } else {
    Serial.print("Problem updating channel. HTTP Error code: ");
    Serial.println(responseCode);
  }

  // 15-second delay for ThingSpeak limit
  Serial.println("Waiting 15 seconds...\n");
  delay(5000); 
}
