#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}


void loop() {
  if (mySerial.available()) {      // If anything comes in Serial (USB),
    Serial.write(mySerial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }
  if (Serial.available()) {      // If anything comes in Serial (USB),
    mySerial.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }

}
