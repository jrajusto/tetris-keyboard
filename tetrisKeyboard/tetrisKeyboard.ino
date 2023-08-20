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

// 16 bit integer for holding input values
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

  // Set button 0 of 128 by reading button on digital pin 28
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
  


  // Set hat direction, 4 hats available. direction is clockwise 0=N 1=NE 2=E 3=SE 4=S 5=SW 6=W 7=NW 8=CENTER 
  // gamepad.SetHat(0, 8);


  // Send all inputs via HID 
  // Nothing is send to your computer until this is called.
  gamepad.send_update();

  // Flash the LED just for fun
  delay(15);
}
