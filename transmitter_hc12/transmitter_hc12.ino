
#include <SoftwareSerial.h>

SoftwareSerial HC12(4, 5);

void setup() {
  //Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12

}

void loop() {
 //if (HC12.available()) { 

   HC12.write("Hello");
// }
 
}
