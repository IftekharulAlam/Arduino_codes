

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const byte address[6] = "iubcs";
RF24 radio(8, 9); // CE, CSN

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate( RF24_2MBPS );
  radio.startListening();

}

void loop() {

  struct myData {
    double T, P, a;
    double AccelerationX, AccelerationY, AccelerationZ;
    double RotationX, RotationY, RotationZ;
  };
  myData datao;

  if (radio.available())   {

    radio.read(&datao, sizeof(datao));
    String fin = "Temp :" + String(datao.T) + "," + "Pressure: " + String(datao.P) + "," + "Altitude: " + String(datao.a) + "," + "Acceleration X: " + String(datao.AccelerationX) + "," + "Acceleration Y: " + String(datao.AccelerationY) + "," + "Acceleration Z: " + String(datao.AccelerationZ) + "," + "Rotation X: " + String(datao.RotationX) + "," + "Rotation Y: " + String(datao.RotationY) + "," + "Rotation Z: " + String(datao.RotationZ);
    Serial.println(fin);


  }


}
