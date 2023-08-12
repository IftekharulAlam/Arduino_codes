#include <SoftwareSerial.h>
#define SSerialRX        4  //Serial Receive pin
#define SSerialTX        5 
SoftwareSerial Bluetooth(SSerialRX, SSerialTX); // RX, TX


int msg[5]; //Total number of data to be sent (data package)

//define the flex sensor input pins
int flex_5 = A1;
int flex_4 = A2;
int flex_3 = A3;
int flex_2 = A4;
int flex_1 = A5;

//define variables for flex sensor values
int flex_5_val;
int flex_4_val;
int flex_3_val;
int flex_2_val;
int flex_1_val;

void setup() {
  // put your setup code here, to run once:
Bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  flex_5_val = analogRead(flex_5); 
  flex_5_val = map(flex_5_val, 860, 761, 180, 110);
  
  flex_4_val = analogRead(flex_4);
  flex_4_val = map(flex_4_val, 655, 611, 120, 20);
 
  flex_3_val = analogRead(flex_3);
  flex_3_val = map(flex_3_val, 613, 580, 0, 150);
 
  flex_2_val = analogRead(flex_2);
  flex_2_val = map(flex_2_val, 694, 529, 0, 160);
  
  flex_1_val = analogRead(flex_1);
  flex_1_val = map(flex_1_val, 833, 771, 50, 130);

  
  msg[4] = flex_5_val;
  msg[3] = flex_4_val;
  msg[2] = flex_3_val;
  msg[1] = flex_2_val;
  msg[0] = flex_1_val;
  Bluetooth.write(msg);
}
