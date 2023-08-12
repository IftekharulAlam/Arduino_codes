
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>

const char* ssid = "dhong";
const char* password = "01521439838";

//Your Domain name with URL path or IP address with path
const char* serverName = "http://192.168.0.100:8000/readStatus";

String sensorReadings;
float sensorReadingsArr[3];
WiFiClient client;
HTTPClient http;
void setup() {
  Serial.begin(115200);

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
  // Send an HTTP POST request depending on timerDelay
  //Check WiFi connection status
  if (WiFi.status() == WL_CONNECTED) {

    sensorReadings = httpGETRequest(serverName);

    JSONVar myObject = JSON.parse(sensorReadings);

    if (JSON.typeof(myObject) == "undefined") {
      Serial.println("Parsing input failed!");
      return;
    }

    Serial.print("JSON object = ");
    Serial.println(myObject);

    // myObject.keys() can be used to get an array of all the keys in the object
    JSONVar keys = myObject.keys();
    Serial.print("JSON Keys = ");
    Serial.println(keys);

    for (int i = 0; i < keys.length(); i++) {
      JSONVar value = myObject[keys[i]];
      Serial.println(keys[i]);
      Serial.println(" = ");
      Serial.println(value);
 
    }
 
  }
  else {
    Serial.println("WiFi Disconnected");
  }

}

String httpGETRequest(const char* serverName) {


  // Your IP address with path or Domain name with URL path
  http.begin(client, serverName);

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "{}";

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
