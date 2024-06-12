// -------------------------------------------------
// Copyright (c) 2022 HiBit <https://www.hibit.dev>
// -------------------------------------------------

bool isImuReady_For1()
{
  uint8_t isReady; // Interruption flag

  I2Cread(MPU9250_IMU_ADDRESS_For_1, 58, 1, &isReady);

  return isReady & 0x01; // Read register and wait for the RAW_DATA_RDY_INT
}

void readRawImu_For1()
{
  uint8_t buff[14];

  // Read output registers:
  // [59-64] Accelerometer
  // [65-66] Temperature
  // [67-72] Gyroscope
  I2Cread(MPU9250_IMU_ADDRESS_For_1, 59, 14, buff);

  // Accelerometer, create 16 bits values from 8 bits data
  accelerometer_F1.x = (buff[0] << 8 | buff[1]);
  accelerometer_F1.y = (buff[2] << 8 | buff[3]);
  accelerometer_F1.z = (buff[4] << 8 | buff[5]);



  // Gyroscope, create 16 bits values from 8 bits data
  gyroscope_F1.x = (buff[8] << 8 | buff[9]);
  gyroscope_F1.y = (buff[10] << 8 | buff[11]);
  gyroscope_F1.z = (buff[12] << 8 | buff[13]);
}

bool isImuReady_For2()
{
  uint8_t isReady; // Interruption flag

  I2Cread(MPU9250_IMU_ADDRESS_For_2, 58, 1, &isReady);

  return isReady & 0x01; // Read register and wait for the RAW_DATA_RDY_INT
}

void readRawImu_For2()
{
  uint8_t buff[14];

  // Read output registers:
  // [59-64] Accelerometer
  // [65-66] Temperature
  // [67-72] Gyroscope
  I2Cread(MPU9250_IMU_ADDRESS_For_2, 59, 14, buff);

  // Accelerometer, create 16 bits values from 8 bits data
  accelerometer_F2.x = (buff[0] << 8 | buff[1]);
  accelerometer_F2.y = (buff[2] << 8 | buff[3]);
  accelerometer_F2.z = (buff[4] << 8 | buff[5]);


  // Gyroscope, create 16 bits values from 8 bits data
  gyroscope_F2.x = (buff[8] << 8 | buff[9]);
  gyroscope_F2.y = (buff[10] << 8 | buff[11]);
  gyroscope_F2.z = (buff[12] << 8 | buff[13]);
}
