String str = "";
uint8_t byteFromSerial;
void setup() {
  Serial.begin(9600);



}

void loop() {

  if (Serial.available() > 0) {
    byteFromSerial = Serial.read();
    uint8_t buff[5] = {byteFromSerial};
    str = (char*)buff;
    Serial.println(str);
  }
  Serial.println(str);

}
