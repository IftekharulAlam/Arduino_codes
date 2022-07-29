#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float t;
int reading;
int tempPin = 0;
int relay = 8;

void setup()
{
//analogReference(INTERNAL);
Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(relay,OUTPUT);

}

void loop()
{
reading = analogRead(tempPin);
t = reading / 9.31;
lcd.setCursor(0,0);
  lcd.print("Temp:  ");
  lcd.print(t);
  if(t >=30){
    digitalWrite(relay,LOW);
  }
  if(t<=25){
    digitalWrite(relay,HIGH);
    }
delay(200);
}

