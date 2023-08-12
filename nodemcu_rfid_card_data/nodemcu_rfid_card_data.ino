#include<MFRC522.h>
#include<SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>
#define RST_PIN         D2          // Configurable, see typical pin layout above
#define SS_PIN          D8
#define node_pin        D4
const char* ssid = "dhong";
const char* password = "01521439838";

//Your Domain name with URL path or IP address with path
String servername = "https://192.168.0.100:8000/writelocation";
MFRC522 mfrc522(SS_PIN, RST_PIN);
String serverReturn;
const char* returnserverName = "http://192.168.0.100:8000/readStatus";
WiFiClient client;
HTTPClient http;
void setup()
{
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  pinMode(node_pin, OUTPUT);
  SPI.begin();

  mfrc522.PCD_Init();
  digitalWrite(node_pin, HIGH);

}
void loop()
{

  if (mfrc522.PICC_IsNewCardPresent())
  {
    if (mfrc522.PICC_ReadCardSerial())
    {
      String uid = "";

      for (int i = 0; i < mfrc522.uid.size; i++)
      {
        uid.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
        uid.concat(String(mfrc522.uid.uidByte[i], HEX));
      }
      uid.toUpperCase();

      if (uid == "6A758407")
      {
        digitalWrite(node_pin, LOW);
        Serial.println("1");
        String statuso = "Stop";
        String locationo = "1";

        serverDatasend(servername, locationo, statuso);


      }
      if (uid == "6B86CC21")
      {
        digitalWrite(node_pin, LOW);
        Serial.println("2");
        String statuso = "Stop";
        String locationo = "2";

        serverDatasend(servername, locationo, statuso);


      }
      if (uid == "3AFA8A07")
      {
        digitalWrite(node_pin, LOW);
        String statuso = "Stop";
        String locationo = "3";

        serverDatasend(servername, locationo, statuso);


      }
      if (uid == "2B2BB821")
      {
        digitalWrite(node_pin, LOW);
        Serial.println("4");
        String statuso = "Stop";
        String locationo = "4";

        serverDatasend(servername, locationo, statuso);


      }
    }
  }

  httpGETRequest(returnserverName);




}

void serverDatasend(String serverName, String locationo, String statuso) {
  if (WiFi.status() == WL_CONNECTED) {

    String serverPath = serverName + "?Locationo=" + locationo + "&" + "Status=" + statuso;
    http.begin(client, serverPath.c_str());


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
    http.end();
  }
}
void httpGETRequest(const char* serverName) {

  if (WiFi.status() == WL_CONNECTED) {
    // Your IP address with path or Domain name with URL path
    http.begin(client, serverName);

    // Send HTTP POST request
    int httpResponseCode = http.GET();

    String payload = "{}";

    if (httpResponseCode > 0) {
      // Serial.print("HTTP Response code: ");
      // Serial.println(httpResponseCode);
      payload = http.getString();
      JSONVar myObject = JSON.parse(payload);

      if (JSON.typeof(myObject) == "undefined") {
        // Serial.println("Parsing input failed!");
        return;
      }

      String m = myObject["result"];
      if (m == "Start") {
        digitalWrite(node_pin, HIGH);

      }
       if (m == "Stop") {
        digitalWrite(node_pin, LOW);

      }


    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();


  }
}
