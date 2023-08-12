#include <EEPROM.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  pinMode(13, OUTPUT);
//  for (int i = 0 ; i < EEPROM.length() ; i++) {
//    EEPROM.write(i, 5);
//  }
//  digitalWrite(13, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println( EEPROM.read(0));
}
