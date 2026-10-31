//1: Two-Way Serial Control (LED Control & Temp Simulation)
const int LED_PIN = 13; // Built-in LED

void setup() {
  Serial.begin(9600); // Must match your laptop's Python script baud rate
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Start with LED off
}

void loop() {
  // Check for incoming commands FROM laptop
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Remove whitespace or hidden carriage returns (\r)

    if (command.equalsIgnoreCase("on")) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("ACK: LED turned ON");
    } else if (command.equalsIgnoreCase("off")) {
      digitalWrite(LED_PIN, LOW);
      Serial.println("ACK: LED turned OFF");
    }
  }
  // Send data TO laptop (Simulated Temp for testing)
  static unsigned long lastSendTime = 0;
  if (millis() - lastSendTime >= 1000) {
    lastSendTime = millis();
    float simulatedTemp = 24.5 + (random(-10, 11) / 10.0); 
    Serial.print("TEMP:");
    Serial.println(simulatedTemp);
  }
}
//2: DHT11 Temperature & Humidity Logger
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // Using the DHT 11 sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); // Wait 2 seconds between measurements

  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Read temperature as Celsius

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("ERROR:Failed to read from DHT sensor");
    return;
  }

  // Print data in CSV format over Serial: Temperature,Humidity
  Serial.print(t);
  Serial.print(",");
  Serial.println(h);
}