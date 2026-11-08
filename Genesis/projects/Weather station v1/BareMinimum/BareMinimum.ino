#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Pin Definitions
#define DHTPIN 2
#define DHTTYPE DHT11
#define BUTTON_PIN 3

// Initialize components
// Standard I2C address for PCF8574 backpacks is 0x27. If it doesn't display text, try 0x3F.
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

// Variables for state tracking
bool isCelsius = true;
bool lastButtonState = HIGH;
unsigned long lastUpdate = 0;
const unsigned long updateInterval = 2000; // 2 seconds update rate

void setup() {
  // Initialize Serial for debugging
  Serial.begin(9600);
  
  // Set up button pin with internal pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // Initialize DHT sensor
  dht.begin();
  
  // Initialize LCD display
  lcd.init();
  lcd.backlight();
  
  // Display initial welcome screen
  lcd.setCursor(0, 0);
  lcd.print("Karibu Kenya!");
  lcd.setCursor(0, 1);
  lcd.print("Weather station v1");
  
  // Wait 3 seconds to let the user read the greeting
  delay(3000);
  lcd.clear();
}

void loop() {
  // 1. Check Button State (Debounced Toggle)
  bool currentButtonState = digitalRead(BUTTON_PIN);
  
  // If button goes from HIGH to LOW (pressed down)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    isCelsius = !isCelsius; // Toggle unit selection
    updateWeatherDisplay();   // Refresh screen immediately on press
    delay(50);              // Simple software debounce delay
  }
  lastButtonState = currentButtonState;

  // 2. Periodic Sensor Readings (Every 2 seconds)
  unsigned long currentMillis = millis();
  if (currentMillis - lastUpdate >= updateInterval) {
    lastUpdate = currentMillis;
    updateWeatherDisplay();
  }
}

void updateWeatherDisplay() {
  // Read humidity and temperature values
  float h = dht.readHumidity();
  float t = dht.readTemperature(!isCelsius); // Passing true returns Fahrenheit

  // Check if any reads failed
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error    ");
    return;
  }

  // Clear or format line 1: Temperature
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1); // 1 decimal point accuracy
  lcd.write(0xDF); // Degree symbol code for LCD character map
  if (isCelsius) {
    lcd.print("C   ");
  } else {
    lcd.print("F   ");
  }

  // Format line 2: Humidity
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h, 1);
  lcd.print("%   ");
}
