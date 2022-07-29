#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos1 = 0;    // variable to store the servo position
int pos2 = 180;
int pin = 2;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(pin, INPUT_PULLUP);
  myservo.write(90);              // tell servo to go to position in variable 'pos'

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(pin) == 0) {
    myservo.write(pos1);              // tell servo to go to position in variable 'pos'



  }
  else {
    myservo.write(pos2);              // tell servo to go to position in variable 'pos'

  }
}
