#include <Servo.h>

Servo myservo;

int pos = 5;
int servo_pin1 = 12;
int servo_pin = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(servo_pin1, INPUT);


  myservo.attach(servo_pin);
  myservo.write(45);
}

void loop() {

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
}
