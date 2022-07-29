
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define mq9pin A0

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {


  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }




}

void loop() {
  int t = analogRead(mq9pin);
  // put your main code here, to run repeatedly:
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(5, 5);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  display.print("CM :");
  if (t < 140) {
    display.print("Normal");

  }
  else if (t > 141) {
    display.print("Danger");


  }

  display.display();
  Serial.print("CM");

  Serial.print(":");
if (t < 140) {
    Serial.print("Normal");

  }
  else if (t > 141) {
    Serial.print("Danger");


  }
  Serial.println("  ");



}
