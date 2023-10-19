#include <ESPmDNS.h>
#include <ArduinoOTA.h>
#include "DHT.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
//#include <ESPAsyncTCP.h>
//#include <ESPAsyncWebServer.h>
//#include <ArduinoJson.h>


const char* ssid = "dhong";
const char* password = "01521439838";
int mainLight =  12; // Digital pin connected to aquarium main Light
int algieLight =  13;// Digital pin connected to aquarium algie Light
int foodservo =  14; // Digital pin connected to aquarium fish food servo motor
#define DHTPIN 15     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
const long utcOffsetInSeconds = 21600;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
String serverName = "http://192.168.0.100:8080/sendTempHumData";
//AsyncWebServer server(80);
float t = 0.0;
float h = 0.0;
void getTempHumidityData();
void OTAinit();
void wifiinit();
void serverinit();
String processor(const String& var);
void aquariumLightsCode();
void aquariumLightsInitCode();
void setup() {
  // put your setup code here, to run once:
  wifiinit();
  OTAinit();
  timeClient.begin();
  dht.begin();
 // serverinit();
  aquariumLightsInitCode();

}

void loop() {
  // put your main code here, to run repeatedly:
  ArduinoOTA.handle();
 // getTempHumidityData();
  aquariumLightsCode();
}
