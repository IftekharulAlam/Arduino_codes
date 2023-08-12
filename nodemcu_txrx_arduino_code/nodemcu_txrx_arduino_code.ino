
#include <SoftwareSerial.h>
#include <SPI.h>

SoftwareSerial mySerial(2, 3); // RX, TX
String my;
char arr[9];

void setup() {
  Serial.begin(115200);

  //  Wire.begin(); // join i2c bus (address optional for master)
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)

  mySerial.begin(115200);


}

void loop() { // run over and over
  if (mySerial.available()) {
    my = mySerial.readString();
    //Serial.println(my);
    my.toCharArray(arr, 9);
    digitalWrite(SS, LOW); // enable Slave Select

    for (int i = 0; i < sizeof arr; i++) {
      SPI.transfer(arr[i]);
      Serial.print(arr[i]);

    }
    SPI.transfer('C');
    Serial.println('C');
    digitalWrite(SS, HIGH); // enable Slave Select


  }

delay(1000);


}
