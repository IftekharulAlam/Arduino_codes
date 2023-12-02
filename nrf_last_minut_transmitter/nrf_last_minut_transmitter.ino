#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>
RF24 radio(8, 9); // CE, CSN

const byte address[6] = "1720650";

void setup() {
  radio.begin();
  Serial.begin(9600);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate( RF24_2MBPS );
 // radio.setChannel(100);
  radio.stopListening();

}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  //delay(1000);
}
