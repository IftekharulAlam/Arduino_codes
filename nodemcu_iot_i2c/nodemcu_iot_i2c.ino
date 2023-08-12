#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <PolledTimeout.h>
const char* ssid = "dhong";
const char* password = "01521439838";
#define SDA_PIN D1
#define SCL_PIN D2
const int16_t I2C_MASTER = 0x42;
const int16_t I2C_SLAVE = 0x08;
int x;
void setup () {
  Serial.begin(115200);
  delay(10);

  Serial.println("Connecting ");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");

  Serial.println(WiFi.localIP());
  Wire.begin(D1, D2); // join i2c bus (address optional for master)

}

void loop() {

 typedef struct dat {
    int obj[9] = {0, 0, 0, 0, 0, 0, 0, 0};
  };
  dat m;

  // Verfiy WiFi is connected:
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http1;  // Object of the class HTTPClient.
    HTTPClient http2;  // Object of the class HTTPClient.
    HTTPClient http3;  // Object of the class HTTPClient.
    HTTPClient http4;  // Object of the class HTTPClient.
    HTTPClient http5;  // Object of the class HTTPClient.
    HTTPClient http6;  // Object of the class HTTPClient.
    HTTPClient http7;  // Object of the class HTTPClient.
    HTTPClient http8;  // Object of the class HTTPClient.


    http1.begin("http://iftekharulalam.me/data1.txt");  // Request destination.
    http2.begin("http://iftekharulalam.me/data2.txt");  // Request destination.
    http3.begin("http://iftekharulalam.me/data3.txt");  // Request destination.
    http4.begin("http://iftekharulalam.me/data4.txt");  // Request destination.
    http5.begin("http://iftekharulalam.me/data5.txt");  // Request destination.
    http6.begin("http://iftekharulalam.me/data6.txt");  // Request destination.
    http7.begin("http://iftekharulalam.me/data7.txt");  // Request destination.
    http8.begin("http://iftekharulalam.me/data8.txt");  // Request destination.




    int httpCode1 = http1.GET(); // Send the request.
    int httpCode2 = http2.GET(); // Send the request.
    int httpCode3 = http3.GET(); // Send the request.
    int httpCode4 = http4.GET(); // Send the request.
    int httpCode5 = http5.GET(); // Send the request.
    int httpCode6 = http6.GET(); // Send the request.
    int httpCode7 = http7.GET(); // Send the request.
    int httpCode8 = http8.GET(); // Send the request.




    if (httpCode1 > 0) { //Check the returning code


      m.obj[0] = http1.getString().toInt();   // Get the text from the destination (1 or 0).



    }
    if (httpCode2 > 0) { //Check the returning code


      m.obj[1] = http2.getString().toInt();   // Get the text from the destination (1 or 0).


    }
    if (httpCode3 > 0) { //Check the returning code


      m.obj[2] = http3.getString().toInt();   // Get the text from the destination (1 or 0).

    }
    if (httpCode4 > 0) { //Check the returning code


      m.obj[3] = http4.getString().toInt();   // Get the text from the destination (1 or 0).

    }
    if (httpCode5 > 0) { //Check the mreturni.g code


      m.obj[4] = http5.getString().toInt();   // Get the text from the destination (1 or 0).

    }
    if (httpCode6 > 0) { //Check the returning code


      m.obj[5] = http6.getString().toInt();   // Get the text from the destination (1 or 0).

    }
    if (httpCode7 > 0) { //Check the returning code

      m.obj[6] = http7.getString().toInt();   // Get the text from the destination (1 or 0).

    }
    if (httpCode8 > 0) { //Check the returning code


      m.obj[7] = http8.getString().toInt();  // Get the text from the destination (1 or 0).

    }

    else {

      Serial.println("Something baaaaaaad happened!");

    }


    http1.end();
    http2.end();
    http3.end();
    http4.end();
    http5.end();
    http6.end();
    http7.end();
    http8.end();
    char *s="HELLO";
//    s[0] = char(m.obj[0]);
//    s[1] = char(m.obj[1]);
//    s[2] = char(m.obj[2]);
//    s[3] = char(m.obj[3]);
//    s[4] = char(m.obj[4]);
//    s[5] = char(m.obj[5]);
//    s[6] = char(m.obj[6]);
//    s[7] = char(m.obj[7]);

    

    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(s);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }



  //Send a request every 30 seconds

}
