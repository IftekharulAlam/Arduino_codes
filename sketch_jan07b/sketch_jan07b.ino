// Open loop motor control example for L298N board
#include <SimpleFOC.h>

#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8

// BLDC motor & driver instance
// BLDCMotor motor = BLDCMotor(pole pair number);
BLDCMotor motor = BLDCMotor(11);
// BLDCDriver3PWM driver = BLDCDriver3PWM(pwmA, pwmB, pwmC, Enable(optional));
BLDCDriver3PWM driver = BLDCDriver3PWM(IN1, IN2, IN3);

void setup() {
  // deactivate the OUT4 output
  pinMode(IN4,OUTPUT);
  digitalWrite(IN4,LOW);


  // driver config
  // power supply voltage [V]
  driver.voltage_power_supply = 12;
  driver.init();
  // link the motor and the driver
  motor.linkDriver(&driver);

  // limiting motor movements
  motor.voltage_limit = 3;   // [V]
  motor.velocity_limit = 20; // [rad/s]

  // open loop control config
  motor.controller = MotionControlType::velocity_openloop;

  // init motor hardware
  motor.init();

  Serial.begin(115200);
  Serial.println("Motor ready!");
  _delay(1000);
}

float target_velocity = 2; // [rad/s]

void loop() {
  // open loop velocity movement
  // using motor.voltage_limit and motor.velocity_limit
  motor.move(target_velocity);

}
