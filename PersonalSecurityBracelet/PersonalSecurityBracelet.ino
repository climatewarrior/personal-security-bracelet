#include "ClickButton.h"

const int buttonPin = 3;
const int led = 2;
int ledState = 0;
ClickButton button(buttonPin, LOW, CLICKBTN_PULLUP);

// Arbitrary LED function 
int LEDfunction = 0;
int oldLEDfunction = 0;

boolean blink = false;
boolean printed = false;

// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(115200);

  // Setup button timers (all in milliseconds / ms)
  // (These are default if not set, but changeable for convenience)
  button.maxPresses     = 2;    // max button multiclick count
  button.debounceTime   = 20;   // Debounce timer in ms
  button.multiclickTime = 250;  // Time limit for multi clicks
  button.heldDownTime   = 1000; // time until "held-down clicks" register

  pinMode(led, OUTPUT); 
  digitalWrite(led, LOW);
}

// the loop routine runs over and over again forever:
void loop() {

  // Update button state
  button.Update();

  oldLEDfunction = LEDfunction;

  // Save click codes in LEDfunction, as click codes are reset at next Update()
  if (button.click != 0) LEDfunction = button.click;

  if(button.click == 1) {
      printed = false;
  }

  if (oldLEDfunction != LEDfunction) {
      printed = false;
  }

  //Serial.println(LEDfunction);

  if(LEDfunction == 2) {

      if (!printed) {
	  Serial.print("1");
	  printed = true;
      }
      ledState = (millis()/2000)%2;
      blink = true;
  }

  if(LEDfunction == -1) {

      if (!printed) {
	  Serial.print("2");
	  printed = true;
      }

      blink = false;
  }


  if (blink) {
      digitalWrite(led, ledState);
  }

}
