// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to


#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  //Serial.println("DHTxx test!");
  pinMode(LED_BUILTIN, OUTPUT);

  dht.begin();
 // pinMode(3,OUTPUT);
}

void loop() {
  
  float t = dht.readTemperature();
  
//  if(t<26.00){
//    digitalWrite(3,LOW);
//   // digitalWrite(LED_BUILTIN, LOW);
//  }
//    if(t>30.00){
//          digitalWrite(3,HIGH);
//         // digitalWrite(LED_BUILTIN, HIGH);
//      }
 
  Serial.print("Temperature: ");
  Serial.println(t);
  //delay(1000);
}
