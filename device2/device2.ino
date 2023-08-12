#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8); // RX, TX
int packet_Count = 0;
void setup() {

  mySerial.begin(9600);
}

void loop() {
  //  if (Serial.available()) {      // If anything comes in Serial (USB),
  //    mySerial.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  //  }
  
  packet_Count = packet_Count + 1;
  String packet_Count_String = String(packet_Count);

  String m = "1040,13:14:02.22," + packet_Count_String + ",F,LAUNCH_WAIT,12.1,P,C,M,30.1,4.5,13:14:02.22,12.1,24.0001,23.0001,4,12.01,23.01,CXON";
  mySerial.println(m);
  delay(1000);


}
