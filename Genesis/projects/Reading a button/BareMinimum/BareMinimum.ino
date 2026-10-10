//Reading a button
const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;      

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
//Button tougle with debounce
const int BUTTON_PIN = 2;
const int LED_PIN = 13;

int ledState = LOW;
int lastButtonState = HIGH; // Starts HIGH due to INPUT_PULLUP

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int currentButtonState = digitalRead(BUTTON_PIN);
  delay(50); // Software debounce delay

  // Detect falling edge (transition from released to pressed)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    ledState = !ledState; // Toggle state
    digitalWrite(LED_PIN, ledState);
  }

  lastButtonState = currentButtonState;
}
//Reaction time game
const int buttonPin = 2;
const int ledPin = 13;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0)); // Seed random number generator with analog noise
}

void loop() {
  Serial.println("Get ready...");
  
  // 1. Random delay between 2000ms (2s) and 5000ms (5s)
  int randomWait = random(2000, 5000);
  delay(randomWait);

  // 2. Turn on LED and start the timer
  digitalWrite(ledPin, HIGH);
  unsigned long startTime = millis();

  // 3. Wait until the user presses the button
  while (digitalRead(buttonPin) == HIGH) {
    // Loop does nothing while waiting for the press (HIGH = unpressed)
  }
  // 4. Calculate reaction time
  unsigned long reactionTime = millis() - startTime;
  
  // 5. Turn off LED and print results
  digitalWrite(ledPin, LOW);
  Serial.print("Your reaction time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  // Pause before starting the next round
  delay(3000);
}