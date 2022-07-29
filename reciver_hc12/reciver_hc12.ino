/*    Arduino Long Range Wireless Communication using HC-12
                      Example 01
   by Dejan Nedelkovski, www.HowToMechatronics.com
*/

#include <SoftwareSerial.h>

SoftwareSerial HC12(4, 5); // HC-12 TX Pin, HC-12 RX Pin


void setup() {
         Serial.begin(9600);             // Serial port to computer
        // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
}

void loop() {
if (HC12.available()) { 
   // String a = HC12.readLine();
    // If HC-12 has data
    Serial.println(HC12.readString());      // Send the data to Serial monitor
 
  }
}
