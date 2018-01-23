#include "Keyboard.h"

// THE PRO MICRO IN THE MACRO PAD IS 3V
int RXLED = 17;

void setup() {
  // make pin an input and turn on the pull-up resistor so it goes high unless connected to ground
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  pinMode(RXLED, OUTPUT);
  digitalWrite(RXLED, HIGH);
  
  Keyboard.begin();
}

void loop() {
  // Check the switches:
  int buttonState7 = digitalRead(7);
  int buttonState8 = digitalRead(8);
  int buttonState9 = digitalRead(9);

  if (buttonState9 == HIGH) {
    digitalWrite(RXLED, LOW);
    TXLED1;
  } else {
    digitalWrite(RXLED, HIGH);
    TXLED0;
  }

  if (buttonState7 == LOW && buttonState9 == LOW) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('`');
    Keyboard.releaseAll();
  } else if (buttonState7 == LOW && buttonState9 == HIGH) {
    Keyboard.print("******");
    delay(300);
  }

  if (buttonState8 == LOW && buttonState9 == LOW) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('`');
    Keyboard.releaseAll();
  } else if (buttonState8 == LOW && buttonState9 == HIGH) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('l');
    Keyboard.releaseAll();
  }
}
