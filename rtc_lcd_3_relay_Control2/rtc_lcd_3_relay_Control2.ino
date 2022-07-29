#include <Wire.h> // Library for I2C communication
#include <SPI.h>  // not used here, but needed to prevent a RTClib compile error
#include "RTClib.h"
#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

RTC_DS1307 RTC;     // Setup an instance of DS1307 naming it RTC

int Relay_1 = 9;
int Relay_2 = 10;
int Relay_3 = 11;
int Relay_on_time = 17;
int Relay_off_time = 18;
int Menu_Pin = 2;
int sigk;
int counte = 0;
DateTime now;



void setup() {
  // put your setup code here, to run once:
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  digitalWrite(Relay_1, HIGH);
  digitalWrite(Relay_2, HIGH);
  digitalWrite(Relay_3, HIGH);
  pinMode(Menu_Pin, INPUT_PULLUP);
  Wire.begin(); // Start the I2C

  lcd.init();
  lcd.backlight();
  RTC.begin();  // Init RTC
  now = RTC.now();

}

void loop() {

  sigk = digitalRead(Menu_Pin);
  if (sigk == LOW) {
    counte++;

  }
  if (counte > 3) {
    counte = 0;

  }
  if (counte > 0) {

   // lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Relay OFF");
    lcd.setCursor(0, 1);
    lcd.print("Relay ON");
    lcd.setCursor(9, 0);
    lcd.print("R");



  }

  if (now.minute() == Relay_on_time) {
    digitalWrite(Relay_1, LOW);
    digitalWrite(Relay_2, LOW);
    digitalWrite(Relay_3, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Relay ON");


  }
  if (now.minute() == Relay_off_time) {
    digitalWrite(Relay_1, HIGH);
    digitalWrite(Relay_2, HIGH);
    digitalWrite(Relay_3, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Relay OFF");
  }
  else {

    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    lcd.setCursor(6, 0);
    lcd.print(now.hour(), DEC);
    lcd.print(":");
    lcd.print(now.minute(), DEC);
    lcd.print(":");
    lcd.print(now.second(), DEC);
    lcd.print(" ");

  }




}
