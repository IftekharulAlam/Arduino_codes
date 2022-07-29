#include <SoftwareSerial.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define SSerialRX        4  //Serial Receive pin
#define SSerialTX        5  //Serial Transmit pin

#define SSerialTxControl 8   //RS485 Direction control
#define RS485Transmit    HIGH
#define RS485Receive     LOW

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX

float t;

void setup() {
  // put your setup code here, to run once:
  pinMode(SSerialTxControl, OUTPUT);
  digitalWrite(SSerialTxControl, RS485Receive);  // Init Transceiver
  RS485Serial.begin(9600);   // set the data rate 

  Serial.begin(9600);
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }


  

}

void loop() {
   if (RS485Serial.available())
  {
    t = RS485Serial.read();   // Read the byte 


  // put your main code here, to run repeatedly:
display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(5, 5);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  display.print("T:");
  display.print(t);
   display.print("*C");
   display.print("---");
  display.setCursor(5, 20);
  display.print("Air");
  display.print(t);
   display.print("A");
  
  display.display();
  
  Serial.println(t);
//delay(10);
  }
}
