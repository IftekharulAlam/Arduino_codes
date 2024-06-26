
#include <SoftwareSerial.h>
#include <AFMotor.h>
char incomingByte;
int speed_min = 135;
int speed_max = 255;

int left_speed = speed_max; // set both motors to maximum speed
int right_speed = speed_max;


AF_DCMotor motor_one(1); // create motor #1, 1KHz pwm
AF_DCMotor motor_two(2); // create motor #2, 1KHz pwm
AF_DCMotor motor_three(3); // create motor #1, 1KHz pwm
AF_DCMotor motor_four(4); // create motor #2, 1KHz pwm

void left(int left_speed, int right_speed);
void right(int left_speed, int right_speed);
void forward(int left_speed, int right_speed);
void backward(int left_speed, int right_speed);
void forward_left(int left_speed, int right_speed);
void forward_right(int left_speed, int right_speed);
void back_left(int left_speed, int right_speed);
void back_right(int left_speed, int right_speed);
void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps - this is the speed the serial interface will work at
  Serial.println("Motor test!");// display message for test purposes when connected to a serial monitor
}

void loop() {

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
  }


  switch (incomingByte)
  {
    case 'S':
      {
        stopo( left_speed, right_speed);
        //Serial.println("Stop\n");
        incomingByte = '*';
      }
      break;

    case 'B':

      { backward(left_speed, right_speed);

        // Serial.println("Forward\n");
        incomingByte = '*';
      }
      break;

    case 'F':

      { forward(left_speed, right_speed);
        // Serial.println("Backward\n");
        incomingByte = '*';
      }
      break;

    case 'R':
      // turn right
      {
        right(left_speed, right_speed);
        // Serial.println("Rotate Right\n");
        incomingByte = '*';
      }
      break;
    case 'L':
      {
        left(left_speed, right_speed);
        //Serial.println("Rotate Left\n");
        incomingByte = '*';
      }
      break;
    case '1':

      { left_speed = 20;
        right_speed = 20;
        //Serial.println("Speed 1\n");
        incomingByte = '*';
      }
      break;
    case '2':
      {
        left_speed = 40;
        right_speed = 40;
        //Serial.println("Speed 2 \n");
        incomingByte = '*';
      }
      break;
    case '3':
      {
        left_speed = 60;
        right_speed = 60;
        //Serial.println("Speed 3 \n");
        incomingByte = '*';
      }
      break;
    case '4':
      {
        left_speed = 80;
        right_speed = 80;
        //Serial.println("Speed 4 \n");
        incomingByte = '*';
      }
      break;
    case '5':
      {
        left_speed = 100;
        right_speed = 100;
        //Serial.println("Speed 5 \n");
        incomingByte = '*';
      }
      break;
    case '6':
      {
        left_speed = 120;
        right_speed = 120;
        //Serial.println("Speed 6 \n");
        incomingByte = '*';
      }
      break;
    case '7':
      {
        left_speed = 150;
        right_speed = 150;
        // Serial.println("Speed 7 \n");
        incomingByte = '*';
      }
      break;
    case '8':
      {
        left_speed = 180;
        right_speed = 180;
        //Serial.println("Speed 8 \n");
        incomingByte = '*';
      }
      break;
    case '9':
      {
        left_speed = 200;
        right_speed = 200;
        //Serial.println("Speed 9 \n");
        incomingByte = '*';
      }
      break;
    case 'q':
      {
        left_speed = 255;
        right_speed = 255;
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;
    case 'I':
      {
        back_right(left_speed, right_speed);
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;
    case 'H':
      {
        back_left(left_speed, right_speed);
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;
    case 'J':
      {
        forward_right(left_speed, right_speed);
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;
    case 'G':
      {
        forward_left(left_speed, right_speed);
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;
  }
}
void forward(int left_speed, int right_speed) {
  motor_one.run(FORWARD);
  motor_two.run(FORWARD);
  motor_three.run(FORWARD);

  motor_four.run(FORWARD);

  motor_one.setSpeed(left_speed);
  motor_two.setSpeed(left_speed);
  motor_three.setSpeed(255);

  motor_four.setSpeed(right_speed);



};
void backward(int left_speed, int right_speed) {
  motor_one.run(BACKWARD);
  motor_two.run(BACKWARD);
  motor_three.run(BACKWARD);

  motor_four.run(BACKWARD);

  motor_one.setSpeed(left_speed);
  motor_two.setSpeed(left_speed);
  motor_three.setSpeed(right_speed);

  motor_four.setSpeed(right_speed);


};
void right(int left_speed, int right_speed) {
  motor_one.run(BACKWARD);
  motor_two.run(BACKWARD);
  motor_three.run(FORWARD);

  motor_four.run(FORWARD);

  motor_one.setSpeed(left_speed);
  motor_two.setSpeed(left_speed);
  motor_three.setSpeed(right_speed);

  motor_four.setSpeed(right_speed);
};
void left(int left_speed, int right_speed) {
  motor_one.run(FORWARD);
  motor_two.run(FORWARD);
  motor_three.run(BACKWARD);

  motor_four.run(BACKWARD);

  motor_one.setSpeed(left_speed);
  motor_two.setSpeed(left_speed);
  motor_three.setSpeed(right_speed);

  motor_four.setSpeed(right_speed);



};
void stopo(int left_speed, int right_speed) {
  motor_one.run(RELEASE);
  motor_two.run(RELEASE);
  motor_three.run(RELEASE);

  motor_four.run(RELEASE);

  motor_one.setSpeed(0);
  motor_two.setSpeed(0);
  motor_three.setSpeed(0);

  motor_four.setSpeed(0);


};
void forward_left(int left_speed, int right_speed) {
  motor_one.run(FORWARD);
  motor_two.run(FORWARD);

  motor_one.setSpeed(left_speed);
  motor_two.setSpeed(left_speed);


};
void forward_right(int left_speed, int right_speed) {

  motor_three.run(FORWARD);

  motor_four.run(FORWARD);


  motor_three.setSpeed(right_speed);

  motor_four.setSpeed(right_speed);
}; void back_left(int left_speed, int right_speed) {
  motor_one.run(FORWARD);
  motor_two.run(FORWARD);

  motor_one.setSpeed(left_speed);
  motor_two.setSpeed(left_speed);


};
void back_right(int left_speed, int right_speed) {

  motor_three.run(FORWARD);

  motor_four.run(FORWARD);


  motor_three.setSpeed(right_speed);

  motor_four.setSpeed(right_speed);
};
//-----------------------------------------------------------------------------------------------------------------------
