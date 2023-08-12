#include <LiquidCrystal_I2C.h>
String words;

//LiquidCrystal lcd(12,11,5,4,3,2);
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

void setup()
{
    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Initialising.");
    delay(1000);
    lcd.clear();
    lcd.print("Initialising..");
    delay(1000);
    lcd.clear();
    lcd.print("Initialising...");
    delay(1000);
    lcd.clear();
    lcd.print("Maker : Techduino");
    delay(2000);
}

void loop()
{
    lcd.clear();
    Serial.print("Enter the line : ");
    while (Serial.available()==0) {
    }
    words = Serial.readString();
    Serial.println(words);
    lcd.setCursor(0,0);
    lcd.print(words);
    delay(5000);
    Serial.println(" ");
}
