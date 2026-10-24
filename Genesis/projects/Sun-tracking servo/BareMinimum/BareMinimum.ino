//1.LED PWM Fade
const int ledPin = 9; // PWM Pin

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Fade in from min to max
  for (int value = 0; value <= 255; value++) {
    analogWrite(ledPin, value);
    delay(10); 
  }
  // Fade out from max to min
  for (int value = 255; value >= 0; value--) {
    analogWrite(ledPin, value);
    delay(10); 
  }
}
//2.Servo Sweep (SG90).
#include <Servo.h>

Servo myServo;
int pos = 0; // Variable to store the servo position

void setup() {
  myServo.attach(10); // Attaches the servo on pin 10
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(10); // Wait for the servo to reach the position
  }
  // Sweep from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(10);
  }
}
//3.Sun-Tracking Servo
#include <Servo.h>

Servo trackerServo;
int servoPos = 90; // Start at midpoint

const int ldrLeft = A0;  // Left LDR pin
const int ldrRight = A1; // Right LDR pin
const int tolerance = 15; // Buffer to prevent jittering

void setup() {
  trackerServo.attach(10);
  trackerServo.write(servoPos);
  delay(1000);
}

void loop() {
  int valLeft = analogRead(ldrLeft);
  int valRight = analogRead(ldrRight);
  
  // If the left side is brighter, move servo left
  if ((valLeft - valRight) > tolerance) {
    if (servoPos < 180) {
      servoPos++;
      trackerServo.write(servoPos);
    }
  }
  // If the right side is brighter, move servo right
  else if ((valRight - valLeft) > tolerance) {
    if (servoPos > 0) {
      servoPos--;
      trackerServo.write(servoPos);
    }
  }
  
  delay(20); // Smooths out response speed
}
