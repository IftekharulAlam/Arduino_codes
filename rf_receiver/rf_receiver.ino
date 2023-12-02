
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>
RF24 radio(8, 9); // CE, CSN

const byte address[6] = "172065";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate( RF24_2MBPS );
 // radio.setChannel(100);

  radio.startListening();


}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
