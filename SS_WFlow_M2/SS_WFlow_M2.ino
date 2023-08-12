#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
signed short minutesl, secondes;
char timeline[16];

int pin = 9;
int Repeat_Time = 2;

int sigk;
int my = 0;

int Pump_Time = 1;
int counte = 0;
int Menu_Pin = 2;

void blinkLine(int num1, int num2) {

  Repeat_Time = num1;

  Pump_Time = num2;
  if (Pump_Time > 5 ) {
    Pump_Time = 5;
  };
  if (Pump_Time < 1 ) {
    Pump_Time = 1;
  };

  lcd.setCursor(0, 1);
  lcd.print(" T = " + String(Repeat_Time));
  lcd.print("  M = " + String(Pump_Time) + "  ");


};

void setup() {
  pinMode(pin, OUTPUT);
  pinMode(Menu_Pin, INPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  lcd.init();
  lcd.backlight();
  Repeat_Time = analogRead(A3);
  Repeat_Time = Repeat_Time / 100;

  Pump_Time = analogRead(A2);
  Pump_Time = Pump_Time / 100;
  if (Pump_Time > 5 ) {
    Pump_Time = 5;
  };
  if (Pump_Time < 1 ) {
    Pump_Time = 1;
  };
  blinkLine(Repeat_Time, Pump_Time);

  digitalWrite(pin, HIGH);

}

void loop() {
  sigk = digitalRead(Menu_Pin);


  if (sigk == HIGH) {
    counte++;

  }
  if (counte > 3) {
    counte = 0;
    my = 0;

  }

  if (secondes == 60)
  {
    secondes = 0;
    minutesl++;
  }
  if (minutesl == Repeat_Time) {
    digitalWrite(pin, LOW);

  }
  if (minutesl == Repeat_Time + Pump_Time) {
    secondes = 0;
    minutesl = 0;
    digitalWrite(pin, HIGH);
  }
  if (counte > 0) {
    //     blinkTheWhole();


    lcd.setCursor(0, 0);
    lcd.print("  set your time ");
    lcd.setCursor(0, 1);
    Repeat_Time = analogRead(A3);
    Repeat_Time = Repeat_Time / 100;

    Pump_Time = analogRead(A2);
    Pump_Time = Pump_Time / 100;
    blinkLine(Repeat_Time, Pump_Time);


    secondes = 0;
    minutesl = 0;
    digitalWrite(pin, HIGH);

  }



  else {
    lcd.setCursor(0, 0);

    lcd.print("Chronometre :");


    lcd.setCursor(0, 1);
    sprintf(timeline, "%0.2d mins %0.2d secs", minutesl, secondes);
    lcd.backlight();


    lcd.print(timeline);

    delay(1000);
    secondes++;


  }




}
