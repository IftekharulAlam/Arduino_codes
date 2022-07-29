

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const byte address[6] = "00001";
RF24 radio(6, 5); // CE, CSN

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  //radio.setChannel(108);

  radio.startListening();

}

void loop() {

   struct myData {
    double T, P, a;


    double gpsT;
    double timeo;
    float volS;



  };
  myData data;

  if (radio.available())   {

    radio.read(&data, sizeof(data));


  }
  String fin = String(data.timeo) + "," + String(data.a) + "," + String(data.P) + "," + String(data.T) + "," + String(data.volS) + "," +  String(data.gpsT);
  Serial.println(fin);


}
