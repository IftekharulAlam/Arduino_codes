#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display
signed short temp, secondes;
char timeline[16];
int MenuPin = 3;
int startPin = 2;
int upPin = 4;
int downPin = 5;
int counterF = 0;
int temp_Time = 2;
int pin = 9;
int pin2 = 10;

int sigk;
int my = 0;
int counte = 0;

int Relay_Time = 1;

int upPinl;
int downPinl;

int startPinl;
int st_Button;

void blinkLine(int num1, int num2) {

  startPinl = digitalRead(MenuPin);
  upPinl = digitalRead(upPin);
  downPinl = digitalRead(downPin);

  lcd.setCursor(0, 1);
  temp_Time = num1;
  Relay_Time = num2;

  if (Relay_Time < 0 ) {
    Relay_Time = 0;
  };

  if (temp_Time < 0 ) {
    temp_Time = 0;
  };

  if (startPinl == HIGH) {
    my++;

  }
  if (my > 4) {
    counte = 0;
    my = 0;
  }

  if (my > 1) {
    if (upPinl == HIGH) {

      Relay_Time++;

    }
    if (downPinl == HIGH) {

      Relay_Time--;

    }
    lcd.setCursor(0, 0);
    lcd.print("Temp:      Time:");
    delay(200);
    lcd.setCursor(0, 0);
    lcd.print("Temp:           ");
    delay(200);

    lcd.setCursor(0, 1);
    lcd.print(String(temp_Time) + "          " + String(Relay_Time));


  }

  else {
    if (upPinl == HIGH) {

      temp_Time++;

    }
    if (downPinl == HIGH) {

      temp_Time--;

    }
    lcd.setCursor(0, 0);
    lcd.print("Temp:      Time:");
    delay(200);
    lcd.setCursor(0, 0);
    lcd.print("           Time:");
    delay(200);

    lcd.setCursor(0, 1);
    lcd.print(String(temp_Time) + "          " + String(Relay_Time));

  }


};

void setup() {
  pinMode(MenuPin, INPUT);
  pinMode(startPin, INPUT);
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin, OUTPUT);
  lcd.init();
  lcd.backlight();
  digitalWrite(pin2, HIGH);

}

void loop() {
  sigk = digitalRead(MenuPin);
  st_Button = digitalRead(startPin);
  if (sigk == HIGH) {
    counte++;
  }

  if ( secondes == Relay_Time) {
    digitalWrite(pin2, HIGH);
    secondes = 0;
    counterF = 0;
  }

  if (counte > 0) {
    lcd.setCursor(0, 0);
    lcd.print("Temp:      Time:");
    lcd.setCursor(0, 1);
    blinkLine(temp_Time, Relay_Time);

  }
  if (st_Button == HIGH) {
    counterF++;



  } if (counterF > 0) {
    digitalWrite(pin2, LOW);
  }
  if (counterF > 0) {
    // digitalWrite(pin2, LOW);
    secondes++;
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print(String(temp_Time) + "          " + String(secondes) + " ");
  }


  else {
    lcd.setCursor(0, 0);
    lcd.print("Temp:      Time:");
    lcd.setCursor(0, 1);
    lcd.print(String(temp_Time) + "          " + String(Relay_Time));

  }


}
