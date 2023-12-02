#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT22  // DHT 22
DHT dht(DHTPIN, DHTTYPE);
RF24 radio(8, 9); // CE, CSN
Adafruit_MPU6050 mpu;
Adafruit_BMP085 bmp;

// The serial connection to the GPS device


const byte address[6] = "iubcs";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  dht.begin();
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  bmp.begin();
  Wire.begin();
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate( RF24_2MBPS );
  radio.stopListening();
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  typedef struct myData {
    double T, P, a;
    double AccelerationX, AccelerationY, AccelerationZ;
    double RotationX, RotationY, RotationZ;


  };
  myData datao;
  datao.T = dht.readTemperature();
  datao.P = bmp.readPressure();
  datao.a = bmp.readAltitude(101500);
  datao.AccelerationX = a.acceleration.x;
  datao.AccelerationY = a.acceleration.y;
  datao.AccelerationZ = a.acceleration.z;
  datao.RotationX = g.gyro.x;
  datao.RotationY = g.gyro.y;
  datao.RotationZ = g.gyro.z;
  radio.write(&datao, sizeof(datao));
//  String fin = "Temp :" + String(datao.T) + "," + "Pressure: " + String(datao.P) + "," + "Altitude: " + String(datao.a) + "," + "Acceleration X: " + String(datao.AccelerationX) + "," + "Acceleration Y: " + String(datao.AccelerationY) + "," + "Acceleration Z: " + String(datao.AccelerationZ) + "," + "Rotation X: " + String(datao.RotationX) + "," + "Rotation Y: " + String(datao.RotationY) + "," + "Rotation Z: " + String(datao.RotationZ);
//  Serial.println(fin);
}
