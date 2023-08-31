#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <NTPClient.h>
#include "DHT.h"
#include <ESP8266HTTPClient.h>
int mainLight =  D1;
int algieLight =  D2;
int foodservo =  D3;

#define DHTPIN D5     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

#ifndef STASSID
#define STASSID "dhong"
#define STAPSK "01521439838"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
const long utcOffsetInSeconds = 21600;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
String serverName = "https://192.168.0.103:8080/sendTempHumData";

void wifiinit() {
  WiFi.mode(WIFI_STA);
  WiFi.hostname("AquariumESP8266");
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    //Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

}
void otainit() {
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else {  // U_FS
      type = "filesystem";
    }

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    //Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    //Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    // Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    // Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      // Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      // Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      // Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      //  Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      //  Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();




}
void getTempHumidityData() {

  float h = dht.readHumidity();

  float t =  dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    // Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;
    String serverPath = serverName + "?temperature=" + t + "&" + "humidity=" + h;


    http.begin(client, serverPath.c_str());


    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      //Serial.print("HTTP Response code: ");
      //  Serial.println(httpResponseCode);
      String payload = http.getString();
      // Serial.println(payload);
    }
    else {
      //      Serial.print("Error code: ");
      //      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    //  Serial.println("WiFi Disconnected");
  }

}
void setup() {
  pinMode(mainLight, OUTPUT);
  pinMode(algieLight, OUTPUT);
  pinMode(foodservo, OUTPUT);


  digitalWrite(mainLight, HIGH);
  digitalWrite(algieLight, HIGH);
  digitalWrite(foodservo, LOW);

  wifiinit();


  otainit();
  timeClient.begin();
 // dht.begin();

}

void loop() {
  ArduinoOTA.handle();
  timeClient.update();
  //getTempHumidityData();
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
