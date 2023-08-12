#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int distance;
const int trigPin_for_sonar1 = 3;
const int echoPin_for_sonar1 = 2;

int relay_1 = 12;
void setup() {
  pinMode(trigPin_for_sonar1, OUTPUT);
  pinMode(echoPin_for_sonar1, INPUT);
  pinMode(relay_1, HIGH);

  //Serial.begin(9600);
  digitalWrite(relay_1, HIGH);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");
  lcd.clear();
}

void loop() {
  distance = sonar_data();
  if (distance < 50) {
    lcd.setCursor(0, 0);
    lcd.print("Relay ON ");
    digitalWrite(relay_1, LOW);

  }
  else {
    digitalWrite(relay_1, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Relay OFF");
  }
}
int sonar_data() {
  long duration1;
  int distance1;
  digitalWrite(trigPin_for_sonar1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_for_sonar1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_for_sonar1, LOW);
  duration1 = pulseIn(echoPin_for_sonar1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  return distance1;

}
