//Standard blink pattern
void setup(){
  pinMode(13,OUTPUT); //Initializing digital pin as output
}
void loop(){
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}
//Sequential/chser pattern
void setup(){
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}
void loop(){
  for (int pin=11; pin <=13; pin++){       //looping each digital pins
    digitalWrite(pin,HIGH);
    delay(500);
    digitalWrite(pin,LOW);
  }
}
//Random flasher pattern
void setup(){
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  randomSeed(analogRead(0));   //initializing random seed using noise from unconnected analog pin
}
void loop(){
  int randomPin = random(10,14);    //select random pins
  int randomDelay = random(200);    //random on/off duration
  digitalWrite(randomPin, HIGH);
  delay(randomDelay);
  digitalWrite(randomPin, LOW);
  delay(randomDelay);
}
//Status/error codes pattern
const int STATUS_OK = 0;           //define status states
const int STATUS_WARNING = 1;
const int STATUS_ERROR = 2;

int currentStatus = STATUS_ERROR;  //set current system status to test different patterns

void setup(){
  pinMode(10,OUTPUT);    //green LED-system OK
  pinMode(11,OUTPUT);     //yellow LED-warning
  pinMode(12,OUTPUT);      //red LED-critical error
  pinMode(13,OUTPUT);       //built in LED-heartbeet
}
void loop(){
  digitalWrite(13,HIGH);
  delay(100);
  digitalWrite(13,LOW);

  switch(currentStatus){                   //execute pattern bsed on current status
    case STATUS_OK:                         //solid green
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      delay(500);
      break;
    case STATUS_WARNING:                     //slow blinking yellow
      digitalWrite(10, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      delay(400);
      digitalWrite(11, LOW);
      delay(500);
      break;
    case STATUS_ERROR:                       //Rapid flashing red
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      for(int i = 0; i<4; i++){
        digitalWrite(12,HIGH);
        delay(100);
        digitalWrite(12,LOW);
        delay(100);
      }
      delay(100);                     //small pause before repeating
      break;
  }
}