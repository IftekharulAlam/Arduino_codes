
#include <SPI.h>
//~ #include <TMRh20nRF24L01.h>
//~ #include <TMRh20RF24.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN  8
#define CSN_PIN 9

// NOTE: the "LL" at the end of the constant is "LongLong" type

const uint64_t   deviceID = 0xE8E8F0F0E1LL; // Define the ID for this slave

int valChange = 1;

RF24 radio(CE_PIN, CSN_PIN);

int dataReceived[2];
int ackData[2] = {12, 23};
void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("Hand Controller Starting");
  radio.begin();
  radio.setDataRate( RF24_250KBPS );
  radio.openReadingPipe(1, deviceID);
  radio.enableAckPayload();
  radio.writeAckPayload(1, ackData, sizeof(ackData));
  radio.startListening();
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
    radio.writeAckPayload(1, ackData, sizeof(ackData));
    ackData[0] += valChange;
  }
}
