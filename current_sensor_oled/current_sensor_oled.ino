// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"   // Include Emon Library
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
EnergyMonitor emon1;                   // Create an instance

void setup()
{  
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  emon1.current(A1, 111.1);             // Current: input pin, calibration.
}

void loop()
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(5, 5);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  display.print("Current:");
  display.print(Irms);
   display.print("A");
  display.display();



  
 // Serial.print(Irms*230.0);         // Apparent power
 // Serial.print(" ");
  Serial.println(Irms);          // Irms
}
