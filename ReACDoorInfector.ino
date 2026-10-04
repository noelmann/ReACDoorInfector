#include "USB.h"
#include "USBHIDKeyboard.h"
#include "keyboardLayout/KeyboardLayout.h"

USBHIDKeyboard Keyboard;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);

  Keyboard.begin(KeyboardLayout_de_DE);
  USB.begin();

  delay(1000);

 
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("cmd");
  delay(1000);
  Keyboard.println("start http://google.com && exit");
  //Keyboard.press(KEY_RETURN);
  //Keyboard.releaseAll();
}

void loop() {
  Serial.println("Test");
  delay(1000);
}