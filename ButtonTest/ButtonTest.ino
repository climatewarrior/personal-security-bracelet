/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int buttonPin = 7;

int buttonState = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(buttonPin, INPUT); 
  digitalWrite(buttonPin, HIGH);     // sets the default (unpressed) state of switchPin to HIGH

  Serial.begin(9600);    
}

// the loop routine runs over and over again forever:
void loop() {
  
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    Serial.println(7);
    
    
  }
}
