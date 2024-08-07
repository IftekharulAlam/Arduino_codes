#include "HCPCA9685.h"


#define  I2CAdd 0x40


HCPCA9685 HCPCA9685(I2CAdd);

int IN1_L = 3;
int IN2_L = 5;
int IN3_L = 6;
int IN4_L = 9;

int servo1 = 90;
int servo2 = 180;
int servo3 = 0;
int servo4 = 110;


int incomingByte;
int speed_min = 135; //the minimum "speed" the motors will turn - take it lower and motors don't turn
int speed_max = 255; //

int speed_left = speed_max; // set both motors to maximum speed
int stepsize = 3;

void left();
void right();
void forward();
void backward();

void setup() {

  Serial.begin(9600); // initialize serial communication at 9600 bits per second:
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);


  HCPCA9685.Servo(0, servo1);
  HCPCA9685.Servo(1, servo2);
  HCPCA9685.Servo(2, servo3);
  HCPCA9685.Servo(3, servo4);
  pinMode(IN1_L, OUTPUT);
  pinMode(IN2_L, OUTPUT);
  pinMode(IN3_L, OUTPUT);
  pinMode(IN4_L, OUTPUT);


}

void loop() {
  //if some date is sent, reads it and saves in state

  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    //Serial.println(incomingByte);
    if (incomingByte > 20) {
      speed_left = incomingByte;
    }
  }



  if (incomingByte == 1) {
    forward();  // if the bt_data is '1' the DC motor will go forward// right
  }
  else if (incomingByte == 2) {
    backward(); // if the bt_data is '2' the motor will Reverse//left
  }
  else if (incomingByte == 3) {
    left(); // if the bt_data is '3' the motor will turn left//back
  }
  else if (incomingByte == 4) {
    right(); // if the bt_data is '4' the motor will turn right//right
  }
  else if (incomingByte == 5) {
    stopy();  // if the bt_data '5' the motor will Stop
  }



  else if (incomingByte == 8) {
    if (servo1 < 170) {
      servo1 = servo1 + stepsize;
    }

    Serial.println(servo1);
    HCPCA9685.Servo(0, servo1);
  }
  else if (incomingByte == 9) {
    if (servo1 > 10) {
      servo1 = servo1 - stepsize;
    }

    Serial.println(servo1);
    HCPCA9685.Servo(0, servo1);
  }

  else if (incomingByte == 11) {
    if (servo2 > 10) {
      servo2 = servo2 - stepsize;
    }
    HCPCA9685.Servo(1, servo2);

  }
  else if (incomingByte == 10) {
    if (servo2 < 170) {
      servo2 = servo2 + stepsize;
    }
    HCPCA9685.Servo(1, servo2);
  }

  else if (incomingByte == 12) {
    if (servo3 > 10) {
      servo3 = servo3 - stepsize;
    }
    HCPCA9685.Servo(2, servo3);
  }
  else if (incomingByte == 13) {
    if (servo3 < 170) {
      servo3 = servo3 + stepsize;
    }
    HCPCA9685.Servo(2, servo3);
  }



  else if (incomingByte == 17) {
    if (servo4 > 5) {
      servo4 = servo4 - stepsize;
    }
    HCPCA9685.Servo(3, servo4);
  }
  else if (incomingByte == 16) {
    if (servo4 < 120) {
      servo4 = servo4 + stepsize;
    }
    HCPCA9685.Servo(3, servo4);
  }

  delay(30);


}
void backward() {

  analogWrite(IN1_L, speed_left);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, speed_left);

  analogWrite(IN4_L, 0);



};
void forward() {

  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, speed_left);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, speed_left);


};

void stopy() {

  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, 0);


};
void right() {
  analogWrite(IN1_L, speed_left);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, speed_left);


};
void left() {

  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, speed_left);

  analogWrite(IN3_L, speed_left);

  analogWrite(IN4_L, 0);

};
