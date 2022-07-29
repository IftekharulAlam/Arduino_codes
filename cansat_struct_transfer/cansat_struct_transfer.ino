#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Adafruit_BMP085.h>

static const int RXPin = 2, TXPin = 3;
static const uint32_t GPSBaud = 9600;



RF24 radio(8, 10); // CE, CSN
TinyGPSPlus gps;
Adafruit_BMP085 bmp;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

const byte address[6] = "00001";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ss.begin(GPSBaud);
  bmp.begin();
  Wire.begin();
  radio.begin();

  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
}

void loop() {

  typedef struct myData {
    double T, P, p0, a;


    double gpsT;
    double timeo ;
    double volS;



  };
  myData data;
  data.T = bmp.readTemperature();
  data.P = bmp.readPressure();
  data.a = bmp.readAltitude();
  data.timeo = millis() / 1000;
  data.gpsT = 12.00;
  data.volS  = 5.00;

  radio.write(&data, sizeof(data));


}
