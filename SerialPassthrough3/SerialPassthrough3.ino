
#include <SoftwareSerial.h>

const byte rxPin = 2;
const byte txPin = 3;
String str = "";
int byteFromSerial1;
// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() {
  //  if (mySerial.available()) {
  //    byteFromSerial = mySerial.read();
  //    byte buff[1] = {byteFromSerial};
  //    str = (char*)buff;
  //    Serial.println(str);
  //  }
  if (mySerial.available()) {
    byteFromSerial1 = mySerial.read();
    //    byte buff[1] = {byteFromSerial};
    //    str = (char*)buff;
    Serial.println(byteFromSerial1);
  }

}
