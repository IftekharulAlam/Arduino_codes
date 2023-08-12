#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

int mainLight =  D1;
int algieLight =  D2;
int foodservo =  D3;

const char *ssid     = "dhong";
const char *password = "01521439838";

const long utcOffsetInSeconds = 21600;

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  //Serial.begin(115200);
  pinMode(mainLight, OUTPUT);
  pinMode(algieLight, OUTPUT);
  pinMode(foodservo, OUTPUT);
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );

  }

  timeClient.begin();
  digitalWrite(mainLight, HIGH);
  digitalWrite(algieLight, HIGH);
  digitalWrite(foodservo, LOW);
}

void loop() {
  timeClient.update();
  int hour = timeClient.getHours();
  int minute = timeClient.getMinutes();
  int second = timeClient.getSeconds();
  if (hour == 11 || hour == 12 || hour == 13 || hour == 14 || hour == 15 || hour == 16 || hour == 17 || hour == 18 || hour == 19 || hour == 20 || hour == 21 || hour == 22 ) {
    if (minute == 1) {
      if (second == 1) {
        digitalWrite(foodservo, HIGH);
        delay(10);
      }
      else {
        digitalWrite(foodservo, LOW);

      }

    }
    else {
      digitalWrite(foodservo, LOW);
    }
  }

  else {
    digitalWrite(foodservo, LOW);
  }


  if (hour >= 1 && hour <= 11) {
    digitalWrite(mainLight, HIGH);

  }
  if (hour >= 11 ) {
    digitalWrite(mainLight, LOW);

  }
  if (hour >= 11 && hour <= 15) {
    digitalWrite(algieLight, LOW);

  }
  else {
    digitalWrite(algieLight, HIGH);

  }



}
