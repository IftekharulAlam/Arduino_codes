#include "DHT.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);


const char* ssid = "dhong";
const char* password = "01521439838";

//Your Domain name with URL path or IP address with path
String serverName = "https://192.168.0.100:8000/sendTempHumData";
const char fingerprint[] PROGMEM = "django-insecure-^=!xqb)lg(v@a@n$+5e=_seuzi(v2ns8kq7)vw+9t3o@eva=c*";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {
  // put your main code here, to run repeatedly:
  //  float h = dht.readHumidity();
  //  // Read temperature as Celsius (the default)
  //  float t = dht.readTemperature();
  float h = 30.0;
  // Read temperature as Celsius (the default)
  float t = 30.0;
  //  if (isnan(h) || isnan(t)) {
  //    Serial.println(F("Failed to read from DHT sensor!"));
  //    return;
  //  }
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;


    HTTPClient http;

    String serverPath = serverName + "?temperature=" + t + "&" + "humidity=" + h;

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverPath.c_str());

    // Send HTTP GET request
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }

}
