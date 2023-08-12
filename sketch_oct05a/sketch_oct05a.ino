//
//#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); // ARDUINO UNO
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display



//LiquidCrystal lcd(3, 2, 1, 7, 8, 9, 10); // ATTINY84
byte buttons[] = {6, 7, 8}; //10 for additional pin
const byte nrButtons = 3; // change to 4 if additional button added
int menusize = 12;
String menu[] = {
  "Menu",                   //0
  "Menu>LED",               //1
  "Menu>LED>Off",           //2
  "Menu>LED>On",            //3
  "Menu>LED>Fade",          //4
  "Menu>LED>Blink",         //5
  "Menu>LCDlight",          //6
  "Menu>LED1",              //7
  "Menu>LED1>Off",          //8
  "Menu>LED1>On",            //9
  "Menu>LED1>Fade",          //10
  "Menu>LED1>Blink",         //11

};

int t;
byte pressedButton, currentPos, currentPosParent, possiblePos[20], possiblePosCount, possiblePosScroll = 0;
String parent = "";

int brightness;
int LCDtoggle = 0;
int fadeAmount = 5;
unsigned long timer = (millis() / 10);
int ledMode = 0;
int ledModeone = 0;

void updateMenu () {
  possiblePosCount = 0;
  while (possiblePosCount == 0) {

    for (t = 1; t < menusize; t++) {
      if (mid(menu[t], 1, inStrRev(menu[t], ">") - 1).equals(menu[currentPos])) {
        possiblePos[possiblePosCount]  =  t;
        possiblePosCount = possiblePosCount + 1;
      }
    }

    //find the current parent for the current menu
    parent = mid(menu[currentPos], 1, inStrRev(menu[currentPos], ">") - 1);
    currentPosParent = 0;
    for (t = 0; t < menusize; t++) {
      if (parent == menu[t]) {
        currentPosParent = t;
      }
    }

    // reached the end of the Menu line
    if (possiblePosCount == 0) {
      //Menu Option Items
      switch (currentPos) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11: //Choose between 2,3,4,5
          for (t = 2; t < 12; t++) {
            if (mid(menu[t], len(menu[t]), 1) == "*") {
              menu[t] = mid(menu[t], 1, len(menu[t]) - 1);
            }
          }
          menu[currentPos] = menu[currentPos] + "*";
          break;
        case 12: //Toggle
          if (mid(menu[currentPos], len(menu[currentPos]), 1) == "*") {
            menu[currentPos] = mid(menu[currentPos], 1, len(menu[currentPos]) - 1);
          } else {
            menu[currentPos] = menu[currentPos] + "*";
          }

          break;
      }

      //Set Variables
      switch (currentPos) {
        case 2:
          ledMode = 0;
          break;
        case 3:
          ledMode = 1;
          break;
        case 4:
          brightness = 128;
          ledMode = 2;
          break;
        case 5:
          brightness = 0;
          ledMode = 3;
          break;
        case 8:
          ledModeone = 0;
          break;
        case 9:
          ledModeone = 1;
        case 10:
          brightness = 128;
          ledModeone = 2;
          break;
        case 11:
          brightness = 0;
          ledModeone = 3;
          break;
          break;
        case 12:
          LCDtoggle = abs(LCDtoggle - 1);
          break;
      }

      // go to the parent
      currentPos = currentPosParent;
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(mid(menu[currentPos], inStrRev(menu[currentPos], ">") + 1, len(menu[currentPos]) - inStrRev(menu[currentPos], ">")));
  lcd.setCursor(0, 1); lcd.print(mid(menu[possiblePos[possiblePosScroll]], inStrRev(menu[possiblePos[possiblePosScroll]], ">") + 1, len(menu[possiblePos[possiblePosScroll]]) - inStrRev(menu[possiblePos[possiblePosScroll]], ">")));

}

// Look for a button press
byte checkButtonPress() {
  byte bP = 0;
  byte rBp = 0;
  for (t = 0; t < nrButtons; t++) {
    if (digitalRead(buttons[t]) == 0) {
      bP = (t + 1);
    }
  }
  rBp = bP;
  while (bP != 0) { // wait while the button is still down
    bP = 0;
    for (t = 0; t < nrButtons; t++) {
      if (digitalRead(buttons[t]) == 0) {
        bP = (t + 1);
      }
    }
  }
  return rBp;
}



void setup() {
  lcd.backlight();

  lcd.init();
  lcd.clear();

  for (t = 0; t < nrButtons; t++) {
    pinMode(buttons[t], INPUT_PULLUP);
  }

  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);

  lcd.setCursor(0, 0); lcd.print("HELLO");
  delay(1000);
  updateMenu();

}

void loop()
{
  switch (ledMode) {
    case 0:
      analogWrite(9, 0);
      break;
    case 1:
      analogWrite(9, 255);
      break;
    case 3:
      if ((millis() / 10) - timer > 30) {
        timer = (millis() / 10);
        brightness = abs(brightness - 255);
        timer = (millis() / 10);
        analogWrite(9, brightness);
      }
      break;
    case 2:
      if ((millis() / 10) - timer > 3) {
        timer = (millis() / 10);
        analogWrite(9, brightness);
        brightness = brightness + fadeAmount;
        if (brightness <= 0 || brightness >= 255) {
          fadeAmount = -fadeAmount;
        }
      }
      break;
      switch (ledModeone) {
        case 7:
          analogWrite(13, 255);
          break;
        case 10:
          if ((millis() / 10) - timer > 30) {
            timer = (millis() / 10);
            brightness = abs(brightness - 255);
            timer = (millis() / 10);
            analogWrite(13, brightness);
          }
          break;
        case 11:
          if ((millis() / 10) - timer > 3) {
            timer = (millis() / 10);
            analogWrite(13, brightness);
            brightness = brightness + fadeAmount;
            if (brightness <= 0 || brightness >= 255) {
              fadeAmount = -fadeAmount;
            }
          }
          break;
      }
  }

  pressedButton = checkButtonPress();
  if (pressedButton != 0) {
    switch (pressedButton) {
      case 1:
        possiblePosScroll = (possiblePosScroll + 1) % possiblePosCount; // Scroll
        break;
      // If I wanted a 4 button controll of the menu
      //case 4:
      //  possiblePosScroll = (possiblePosScroll + possiblePosCount - 1) % possiblePosCount; // Scroll
      //break;
      case 2:
        currentPos = possiblePos[possiblePosScroll]; //Okay
        break;
      case 3:
        currentPos = currentPosParent; //Back
        possiblePosScroll = 0;
        break;
      case 7:
        possiblePosScroll = (possiblePosScroll + 1) % possiblePosCount; // Scroll
        break;
      // If I wanted a 4 button controll of the menu
      //case 4:
      //  possiblePosScroll = (possiblePosScroll + possiblePosCount - 1) % possiblePosCount; // Scroll
      //break;
      case 8:
        currentPos = possiblePos[possiblePosScroll]; //Okay
        break;
      case 9:
        currentPos = currentPosParent; //Back
        possiblePosScroll = 0;
        break;
    }
    updateMenu();
  }
}
String mid(String str, int start, int len) {
  int t = 0;
  String u = "";
  for (t = 0; t < len; t++) {
    u = u + str.charAt(t + start - 1);
  }
  return u;
}

int inStrRev(String str, String chr) {
  int t = str.length() - 1;
  int u = 0;
  while (t > -1) {
    if (str.charAt(t) == chr.charAt(0)) {
      u = t + 1; t = -1;
    }
    t = t - 1;
  }
  return u;
}

int len(String str) {
  return str.length();
}
