#include <Wire.h> 

#include "DHT.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

#define DHTPIN 2     

#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);
void setup() {
dht.begin();
  lcd.begin(16, 2);
  
   lcd.setCursor(0,0);
  lcd.print("   Welcome to ");
   lcd.setCursor(0,1);
   lcd.print("  Fab Lab IUB");
   delay(4000);
}

void loop() {

  int sensorValue = analogRead(A0);

 int t = dht.readTemperature();
  int h = dht.readHumidity();
  //delay(500);
 lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print("C ");
 //lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.print(h);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("   Air QI:");
    lcd.print(sensorValue);
    lcd.print("    ");

}
