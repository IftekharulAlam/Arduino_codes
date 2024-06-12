// -------------------------------------------------
// Copyright (c) 2022 HiBit <https://www.hibit.dev>
// -------------------------------------------------

void normalize_For1(gyroscope_raw_For1 gyroscope_F1)
{
  // Sensitivity Scale Factor (MPU datasheet page 8)
  normalized_F1.gyroscope_F1.x = gyroscope_F1.x / 32.8;
  normalized_F1.gyroscope_F1.y = gyroscope_F1.y / 32.8;
  normalized_F1.gyroscope_F1.z = gyroscope_F1.z / 32.8;
}

void normalize_For1(accelerometer_raw_For1 accelerometer_F1)
{
  // Sensitivity Scale Factor (MPU datasheet page 9)
  normalized_F1.accelerometer_F1.x = accelerometer_F1.x * G / 16384;
  normalized_F1.accelerometer_F1.y = accelerometer_F1.y * G / 16384;
  normalized_F1.accelerometer_F1.z = accelerometer_F1.z * G / 16384;
}

void normalize_For2(gyroscope_raw_For2 gyroscope_F2)
{
  // Sensitivity Scale Factor (MPU datasheet page 8)
  normalized_F2.gyroscope_F2.x = gyroscope_F2.x / 32.8;
  normalized_F2.gyroscope_F2.y = gyroscope_F2.y / 32.8;
  normalized_F2.gyroscope_F2.z = gyroscope_F2.z / 32.8;
}

void normalize_For2(accelerometer_raw_For2 accelerometer_F2)
{
  // Sensitivity Scale Factor (MPU datasheet page 9)
  normalized_F2.accelerometer_F2.x = accelerometer_F2.x * G / 16384;
  normalized_F2.accelerometer_F2.y = accelerometer_F2.y * G / 16384;
  normalized_F2.accelerometer_F2.z = accelerometer_F2.z * G / 16384;
}


