#include "Wire.h"
#include "I2C.h"
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include "cstring"
#include <TinyGPSPlus.h>
#include "BluetoothSerial.h"

String device_name = "ESP32-BT-Slave";

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif
BluetoothSerial SerialBT;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
#define MPU9250_IMU_ADDRESS_For_1 0x68
#define MPU9250_IMU_ADDRESS_For_2 0x69
#define MPU9250_MAG_ADDRESS 0x0C

#define GYRO_FULL_SCALE_250_DPS 0x00
#define GYRO_FULL_SCALE_500_DPS 0x08
#define GYRO_FULL_SCALE_1000_DPS 0x10
#define GYRO_FULL_SCALE_2000_DPS 0x18

#define ACC_FULL_SCALE_2G 0x00
#define ACC_FULL_SCALE_4G 0x08
#define ACC_FULL_SCALE_8G 0x10
#define ACC_FULL_SCALE_16G 0x18

#define TEMPERATURE_OFFSET 21  // As defined in documentation

#define INTERVAL_MS_PRINT 1000

#define G 9.80665
#define RXD2 16
#define TXD2 17
struct gyroscope_raw_For1 {
  int16_t x, y, z;
} gyroscope_F1;

struct accelerometer_raw_For1 {
  int16_t x, y, z;
} accelerometer_F1;


struct {
  struct {
    float x, y, z;
  } accelerometer_F1, gyroscope_F1;

} normalized_F1;

struct gyroscope_raw_For2 {
  int16_t x, y, z;
} gyroscope_F2;

struct accelerometer_raw_For2 {
  int16_t x, y, z;
} accelerometer_F2;


struct {
  struct {
    float x, y, z;
  } accelerometer_F2, gyroscope_F2;

} normalized_F2;
void writeFile(fs::FS &fs, const char *path, const char *message) {
  SerialBT.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file) {
    SerialBT.println("Failed to open file for writing");
    return;
  }
  if (file.print(message)) {
    SerialBT.println("File written");
  } else {
    SerialBT.println("Write failed");
  }
  file.close();
}

void appendFile(fs::FS &fs, const char *path, const char *message) {
  SerialBT.printf("Appending to file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if (!file) {
    SerialBT.println("Failed to open file for appending");
    return;
  }
  if (file.println(message)) {

    SerialBT.println("Message appended");


  } else {
    SerialBT.println("Append failed");
  }
  file.close();
}

void setup() {
  // put your setup code here, to run once:
  SerialBT.begin(device_name);
  Serial2.begin(GPSBaud, SERIAL_8N1, RXD2, TXD2);



#ifdef REASSIGN_PINS
  SPI.begin(sck, miso, mosi, cs);
  if (!SD.begin(cs)) {
#else
  if (!SD.begin()) {
#endif
    SerialBT.println("Card Mount Failed");
    return;
  }
  // writeFile(SD, "/data.txt", "Start ");

  Wire.begin();

  //For 1
  I2CwriteByte(MPU9250_IMU_ADDRESS_For_1, 27, GYRO_FULL_SCALE_1000_DPS);  // Configure gyroscope range
  I2CwriteByte(MPU9250_IMU_ADDRESS_For_1, 28, ACC_FULL_SCALE_2G);         // Configure accelerometer range

  I2CwriteByte(MPU9250_IMU_ADDRESS_For_1, 55, 0x02);  // Set by pass mode for the magnetometers
  I2CwriteByte(MPU9250_IMU_ADDRESS_For_1, 56, 0x01);  // Enable interrupt pin for raw data



  //For 2
  I2CwriteByte(MPU9250_IMU_ADDRESS_For_2, 27, GYRO_FULL_SCALE_1000_DPS);  // Configure gyroscope range
  I2CwriteByte(MPU9250_IMU_ADDRESS_For_2, 28, ACC_FULL_SCALE_2G);         // Configure accelerometer range

  I2CwriteByte(MPU9250_IMU_ADDRESS_For_2, 55, 0x02);  // Set by pass mode for the magnetometers
  I2CwriteByte(MPU9250_IMU_ADDRESS_For_2, 56, 0x01);  // Enable interrupt pin for raw data
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (isImuReady_For1()) {
    readRawImu_For1();

    normalize_For1(gyroscope_F1);
    normalize_For1(accelerometer_F1);
  }
  if (isImuReady_For2()) {
    readRawImu_For2();

    normalize_For2(gyroscope_F2);
    normalize_For2(accelerometer_F2);
  }

  float gyro_x = (normalized_F1.gyroscope_F1.x + normalized_F2.gyroscope_F2.x) / 2;
  float gyro_y = (normalized_F1.gyroscope_F1.y + normalized_F2.gyroscope_F2.y) / 2;
  float gyro_z = (normalized_F1.gyroscope_F1.z + normalized_F2.gyroscope_F2.z) / 2;

  float accel_x = (normalized_F1.accelerometer_F1.x + normalized_F2.accelerometer_F2.x) / 2;
  float accel_y = (normalized_F1.accelerometer_F1.y + normalized_F2.accelerometer_F2.y) / 2;
  float accel_z = (normalized_F1.accelerometer_F1.z + normalized_F2.accelerometer_F2.z) / 2;
  while (Serial2.available() > 0)
    gps.encode(Serial2.read());
  String gpsLat = String(gps.location.lat(), 6);
  String gpsLng = String(gps.location.lng(), 6);

  String s = String(gps.time.hour()) + ":";
  if (gps.time.minute() < 10) s += "0";
  s += String(gps.time.minute());
  s += ":";
  if (gps.time.second() < 10) s += "0";
  s += String(gps.time.second());



  String d = String(accel_x) + "," + String(accel_y) + "," + String(accel_z) + "," + String(gyro_x) + "," + String(gyro_y) + "," + String(gyro_z) + "," + gpsLat + "," + gpsLng + "," + s;
  SerialBT.println(d);
  char *cstr = new char[d.length() + 1];
  strcpy(cstr, d.c_str());
  appendFile(SD, "/data.txt", cstr);

  delay(1000);
}
