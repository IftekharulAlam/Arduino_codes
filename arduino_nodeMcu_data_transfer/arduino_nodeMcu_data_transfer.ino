#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int a  = analogRead(A0);
mySerial.println(a);
}
