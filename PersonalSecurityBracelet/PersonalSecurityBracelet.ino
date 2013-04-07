/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int buttonPin = 7;

int buttonState = 0;

unsigned long time;
unsigned long oldTime = 0;
unsigned long timeDelta = 0;
unsigned long threshold = 2500;

unsigned long clickTime;

struct steps {
  boolean one;
  boolean two;
  boolean three;
};

steps stepsvar = {false, false, false};

boolean doubleclick = false;
boolean clicked = false;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(115200);
  pinMode(buttonPin, INPUT); 
  digitalWrite(buttonPin, HIGH); // sets the default (unpressed) state of switchPin to HIGH
}

// the loop routine runs over and over again forever:
void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {

    if (!clicked && stepsvar.two) {

      doubleclick = true;
    }

    else {
      clicked = true;
      clickTime = millis();
      doubleclick = false;
      stepsvar.one = true;
      stepsvar.two = false;
      stepsvar.three = false;
    }

    if (oldTime > 0)
    {
      timeDelta += millis() - oldTime;
      oldTime = millis();

      if (timeDelta > threshold) 
      {
        Serial.println("EMERGENCY!");
        timeDelta = 0;
        oldTime = 0;
      }
    }
    
    oldTime = millis();

  }

  else {

    if (clicked) {
        stepsvar.two = true;
	clicked = false;
	doubleclick = false;
    }

    if (doubleclick) {
      if (millis() - clickTime < 2000) {
        Serial.println("CANCEL");
      }
      
      clicked = false;
      doubleclick = false;
      stepsvar.one = false;
      stepsvar.two = false;
      stepsvar.three = false;
    }

  }
}


