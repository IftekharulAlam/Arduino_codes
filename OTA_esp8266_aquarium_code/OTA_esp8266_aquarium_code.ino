#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <NTPClient.h>
#include "DHT.h"
#include <ESP8266HTTPClient.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

int mainLight =  D1; // Digital pin connected to aquarium main Light
int algieLight =  D2;// Digital pin connected to aquarium algie Light
int foodservo =  D3; // Digital pin connected to aquarium fish food servo motor

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

AsyncWebServer server(80);
float t = 0.0;
float h = 0.0;

void otainit();
void wifiinit();
void serverinit();
String processor(const String& var);
void aquariumLightsCode();
void aquariumLightsInitCode();
void setup() {
  wifiinit();
  otainit();
  timeClient.begin();
  dht.begin();
  serverinit();
  aquariumLightsInitCode();

}

void loop() {
  ArduinoOTA.handle();
  getTempHumidityData();
  aquariumLightsCode();

}
