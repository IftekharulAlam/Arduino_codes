#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

#define SSerialRX        4  //Serial Receive pin
#define SSerialTX        5  //Serial Transmit pin

#define SSerialTxControl 8   //RS485 Direction control

#define RS485Transmit    HIGH
#define RS485Receive     LOW

#define Pin13LED         13

SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SSerialTxControl, OUTPUT);
  digitalWrite(SSerialTxControl, RS485Transmit);  // Init Transceiver   
  RS485Serial.begin(9600);   // set the data rate 

}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
    RS485Serial.write(t);          // Send byte to Remote Arduino
//delay(1000);
}
