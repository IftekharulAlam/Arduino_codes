#include <Wire.h> // Library for I2C communication
#include <SPI.h>  // not used here, but needed to prevent a RTClib compile error
#include "RTClib.h"
#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

RTC_DS1307 RTC;     // Setup an instance of DS1307 naming it RTC

int Relay_1 = 9;
int Relay_2 = 10;
int Relay_3 = 11;
int Relay_on_time = 9;
int Relay_off_time = 20;




void setup() {
  // put your setup code here, to run once:
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  digitalWrite(Relay_1, HIGH);
  digitalWrite(Relay_2, HIGH);
  digitalWrite(Relay_3, HIGH);
  Wire.begin(); // Start the I2C

  lcd.init();
  lcd.backlight();
  RTC.begin();  // Init RTC


}

void loop() {
  DateTime now = RTC.now();

  if (now.hour() >= Relay_on_time && now.hour() < Relay_off_time ) {
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    lcd.setCursor(6, 0);
    lcd.print(now.hour(), DEC);
    lcd.print(":");
    lcd.print(now.minute(), DEC);
    lcd.print(":");
    lcd.print(now.second(), DEC);
    lcd.print(" ");
    digitalWrite(Relay_1, LOW);
    digitalWrite(Relay_2, LOW);
    digitalWrite(Relay_3, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Relay ON");


  }
  if (now.hour() == Relay_off_time) {
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    lcd.setCursor(6, 0);
    lcd.print(now.hour(), DEC);
    lcd.print(":");
    lcd.print(now.minute(), DEC);
    lcd.print(":");
    lcd.print(now.second(), DEC);
    lcd.print(" ");

    digitalWrite(Relay_1, HIGH);
    digitalWrite(Relay_2, HIGH);
    digitalWrite(Relay_3, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Relay OFF");
  }

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
