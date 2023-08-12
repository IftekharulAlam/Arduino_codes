#include<MFRC522.h>
#include<SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define RST_PIN         D2          // Configurable, see typical pin layout above
#define SS_PIN          D8
#define node_pin        D4
const char* ssid = "dhong";
const char* password = "01521439838";

//Your Domain name with URL path or IP address with path
String serverName = "https://192.168.0.100:8000/sendTempHumData";
MFRC522 mfrc522(SS_PIN, RST_PIN);
void setup()
{
  WiFi.begin(ssid, password);
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
  Serial.begin(115200);
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
        //Serial.println("1");
        digitalWrite(node_pin, LOW);
      }
      if (uid == "6B86CC21")
      {
        // Serial.println("2");
        digitalWrite(node_pin, LOW);
      }
      if (uid == "3AFA8A07")
      {
        //Serial.println("3");
        digitalWrite(node_pin, LOW);

      }
      if (uid == "2B2BB821")
      {
        //Serial.println("4");
        digitalWrite(node_pin, LOW);
      }
    }
  }
  else {
    digitalWrite(node_pin, HIGH);
  }





}
