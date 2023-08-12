#include <SoftwareSerial.h>
int pin1 = 13;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
const byte rxPin = 2;
const byte txPin = 3;
String str = "";
byte byteFromSerial;
// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

void loop() {
  if (mySerial.available()) {
    byteFromSerial = mySerial.read();
    byte buff[1] = {byteFromSerial};
    str = (char*)buff;
    Serial.println(str);
  }
  if (str == "1") {
    digitalWrite(pin1, HIGH);

  }
  if (str == "2") {
    digitalWrite(pin1, LOW);

  }
  if (str == "3") {
    digitalWrite(pin2, HIGH);

  }
  if (str == "4") {
    digitalWrite(pin2, LOW);

  } if (str == "5") {
    digitalWrite(pin3, HIGH);

  }
  if (str == "6") {
    digitalWrite(pin3, LOW);

  } if (str == "7") {
    digitalWrite(pin4, HIGH);

  }
  if (str == "8") {
    digitalWrite(pin4, LOW);

  }

}
