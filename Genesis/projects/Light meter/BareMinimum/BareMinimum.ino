// 1.Potentiometer reader.
const int POT_PIN = A0; // Potentiometer middle pin connected to Analog A0

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Read the raw 10-bit analog value (0 to 1023)
  int potValue = analogRead(POT_PIN);
  
  // Calculate voltage: (Raw Value * Max Voltage) / Max ADC Resolution
  float potVoltage = potValue * (5.0 / 1023.0);
  
  // Print results to the Serial Monitor
  Serial.print("Potentiometer Raw ADC: ");
  Serial.print(potValue);
  Serial.print(" | Calculated Voltage: ");
  Serial.print(potVoltage);
  Serial.println("V");
  
  delay(200); // Small delay to make the serial feed readable
}
// 2.Light meter thresholds- LDR added
const int LDR_PIN = A1; // LDR voltage divider connected to Analog A1

// Thresholds for room light level categorization
const int DARK_THRESHOLD = 300;   // Values below this are considered Dark
const int BRIGHT_THRESHOLD = 700; // Values above this are considered Bright

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Read the light sensor value (higher voltage = more light)
  int ldrValue = analogRead(LDR_PIN);
  
  Serial.print("LDR Raw Value: ");
  Serial.print(ldrValue);
  Serial.print(" -> Room is: ");
  
  // Evaluate light levels based on thresholds
  if (ldrValue < DARK_THRESHOLD) {
    Serial.println("DARK");
  } 
  else if (ldrValue >= DARK_THRESHOLD && ldrValue <= BRIGHT_THRESHOLD) {
    Serial.println("DIM");
  } 
  else {
    Serial.println("BRIGHT");
  }
  
  delay(500); // Half-second delay before checking light levels again
}
// 3.Audio Light Tracker (Piezo Buzzer added)
const int LDR_PIN = A1;    // LDR voltage divider connected to Analog A1
const int BUZZER_PIN = 9;  // Piezo buzzer positive leg connected to Digital 9

void setup() {
  // Configure buzzer pin as a power output
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Read the current room light level
  int ldrValue = analogRead(LDR_PIN);
  
  // Map the sensor scale (0-1023) to a delay scale in milliseconds (1000ms down to 50ms)
  // This inversion makes higher light values cause shorter delays (faster beeping)
  int beepDelay = map(ldrValue, 0, 1023, 1000, 50);
  
  // Keep delay inside safe limits to prevent errors if the sensor spikes
  beepDelay = constrain(beepDelay, 50, 1000);
  
  // Trigger a short, crisp beep
  tone(BUZZER_PIN, 1000); // Play a 1000Hz tone
  delay(30);              // Keep it on for 30ms so it sounds like a click/beep
  noTone(BUZZER_PIN);     // Silence the buzzer
  
  // Pause dynamically based on room brightness before the next beep loop
  delay(beepDelay);
}