/*
  PicoGamepad

  Turn a Raspberry Pico 2040 into an HID gamepad

  Supports:
  128 Buttons
  8 Analog axes
  4 Hat switches
  
  created 28 June 2021
  by Jake Wilkinson (RealRobots)

  This example code is in the public domain.

  https://www.gitlab.com/realrobots/PicoGamepad
*/

#include <PicoGamepad.h>

PicoGamepad gamepad;

int val;

int lights = 1;
int lightButtonState = 0;

void setup() {  
  // Button on pin 
  pinMode(28, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  digitalWrite(4,lights);
  digitalWrite(28,HIGH);
  digitalWrite(27,HIGH);
}

void loop() {

  gamepad.SetButton(9, !digitalRead(28));
   gamepad.SetButton(1, !digitalRead(27));
  gamepad.SetButton(2, !digitalRead(26));
  gamepad.SetButton(3, !digitalRead(22));
  gamepad.SetButton(4, !digitalRead(21));
  gamepad.SetButton(5, !digitalRead(20));
  gamepad.SetButton(6, !digitalRead(19));
  gamepad.SetButton(7, !digitalRead(18));
  gamepad.SetButton(8, !digitalRead(2));

  if(!digitalRead(3) != lightButtonState){
    if(!digitalRead(3) == HIGH){
      lights = !lights;
      digitalWrite(4,lights);
    }
    lightButtonState = !digitalRead(3);
  }
  

  gamepad.send_update();

  delay(15);
}
