#include <SoftwareSerial.h>
#define SSerialRX        11  //Serial Receive pin
#define SSerialTX        10  //Serial Transmit pin

#define SSerialTxControl 8   //RS485 Direction control

#define RS485Transmit    HIGH
#define RS485Receive     LOW


int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
#define LEDPin 13 // Onboard LED

const int trigPin = 2;
const int echoPin =4;
long duration;
int distance;
SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX

void setup() {
 pinMode(SSerialTxControl, OUTPUT);
digitalWrite(SSerialTxControl, RS485Transmit);
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
RS485Serial.begin(9600);
}

void loop() {

  int dis = data();
  RS485Serial.write(dis);
  
  

}
int data(){
  digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
   /* Send a negative number to computer and Turn LED ON 
   to indicate "out of range" */
   return -1;
   //digitalWrite(LEDPin, HIGH); 
 } else {
   /* Send the distance to the computer using Serial protocol, and
   turn LED OFF to indicate successful reading. */
   return distance;
  // digitalWrite(LEDPin, LOW); 
 }
 
 //Delay 50ms before next reading.
 delay(50);
  
  }
