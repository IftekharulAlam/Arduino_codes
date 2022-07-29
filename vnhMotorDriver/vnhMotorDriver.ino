#include "DualVNH5019MotorShield.h"

DualVNH5019MotorShield md;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  Serial.println("Dual VNH5019 Motor Shield");
  md.init();
}

void loop() {
  // put your main code here, to run repeatedly:
md.setM1Speed(400);
md.setM2Speed(400);

}
