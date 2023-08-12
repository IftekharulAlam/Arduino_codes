#include <Servo.h>

Servo myservo;


int pos = 5;
int mainLight =  2;
int algieLight =  3;
int mainLight1 =  4;
int algieLight1 =  5;
int servo_pin1 = 7;
int servo_pin = 6;

void setup() {
  pinMode(mainLight, OUTPUT);
  pinMode(algieLight, OUTPUT);
  pinMode(mainLight1, INPUT);
  pinMode(servo_pin1, INPUT);
  pinMode(algieLight1, INPUT);

  myservo.attach(servo_pin);
  myservo.write(50);
}

void loop() {
  int o = digitalRead(mainLight1);
  int h =  digitalRead(algieLight1);
  int s =  digitalRead(servo_pin1);
  if (s == 1 ) {
    for (pos = 5; pos <= 45; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
    for (pos = 45; pos >= 5; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }

  }
  else
  {
    myservo.write(45);
  }
  if (o == 1 ) {
    digitalWrite(mainLight, HIGH);

  }
  if (o == 0 ) {
    digitalWrite(mainLight, LOW);

  }
  if (h == 0 ) {
    digitalWrite(algieLight, LOW);

  }
  if (h == 1 ) {
    digitalWrite(algieLight, HIGH);

  }
}
