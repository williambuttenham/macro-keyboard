#include "Keyboard.h"

void setup() {
  // make pin an input and turn on the pull-up resistor so it goes high unless connected to ground
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  // pinMode(9, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  // Check the switches:
  int buttonState7 = digitalRead(7);
  int buttonState8 = digitalRead(8);
  // int buttonState9 = digitalRead(9);

  if (buttonState7 == LOW) {
    Keyboard.write('*');
    Keyboard.write('*');
    Keyboard.write('*');
    Keyboard.write('*');
    Keyboard.write('*');
    Keyboard.write('*');
    Keyboard.write('*');
    Keyboard.write('*');
    Keyboard.write('*');
    Keyboard.write('*');
    delay(1000);
  }

  if (buttonState8 == LOW) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('l');
    Keyboard.releaseAll();
    delay(1000);
  }

  // if (buttonState9 == HIGH) {
  // }
  delay(1000);
}