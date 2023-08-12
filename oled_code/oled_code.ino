#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"

RTC_DS1307 RTC;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  RTC.begin(); // load the time from your computer.

  if (! RTC.isrunning())

  {

    Serial.println("RTC is NOT running!");// This will reflect the time that your sketch was compiled

    RTC.adjust(DateTime(__DATE__, __TIME__));

  }
  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(5, 5);     // Start at top-left corner
  display.cp437(true);
  display.print("1630749\n");
  display.print("1621560\n");
  display.print("1721010\n");
  display.display();
  delay(4000);

}

void loop() {

  // put your main code here, to run repeatedly:
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(5, 5);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  display.print("");
  DateTime now = RTC.now();

  display.print(now.day(), DEC);

  display.print('/');

  display.print(now.month(), DEC);

  display.print('/');

  display.print(now.year(), DEC);

  display.print(' ');

  display.print(now.hour(), DEC);

  display.print(':');

  display.print(now.minute(), DEC);

  display.print(':');

  display.print(now.second(), DEC);

  display.println();



  display.display();
}
