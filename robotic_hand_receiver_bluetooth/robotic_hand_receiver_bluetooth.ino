#include <SoftwareSerial.h>
#include <Servo.h>    //the library which helps us to control the servo motor

#define SSerialRX        4  //Serial Receive pin
#define SSerialTX        5 
SoftwareSerial Bluetooth(SSerialRX, SSerialTX); // RX, TX
Servo myServo1;
Servo myServo3;
Servo myServo4;
Servo myServo2;
Servo myServo5;
int msg[5];


void setup() {
  // put your setup code here, to run once:
Bluetooth.begin(9600);
Serial.begin(9600);
  //define the servo input pins
  myServo1.attach(10); //A1
  myServo2.attach(9); //A2
  myServo3.attach(6); //A3
  myServo4.attach(5); //A4
  myServo5.attach(3); //A5

    myServo1.write(110); //A1
    myServo2.write(20); //A2
    myServo3.write(150); //A3
    myServo4.write(160); //A4
    myServo5.write(130); //A5
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Bluetooth.available())
  {
    msg[5] = Bluetooth.read();
  }
    Serial.print(msg[4]);
    Serial.print(" ");
    Serial.print(msg[3]);
    Serial.print(" ");
    Serial.print(msg[2]);
    Serial.print(" ");
    Serial.print(msg[1]);
    Serial.print(" ");
    Serial.print(msg[0]);
    Serial.println(" ");

  
    // Read the byte 
    myServo1.write(msg[4]); //A1
    myServo2.write(msg[3]); //A2
    myServo3.write(msg[2]); //A3
    myServo4.write(msg[1]); //A4
    myServo5.write(msg[0]); //A5

}
