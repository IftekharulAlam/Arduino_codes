/*
  Basic ESP8266 MQTT publish client example
*/
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
const char* ssid = "dhong";
const char* password = "01521439838";
const char* mqtt_server = "192.168.0.103";
const char* mqtt_user = "iftekharulalam";
const char* mqtt_pass = "01521439838As";



WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  // Connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //    Serial.print(".");
  }
  //  Serial.println("WiFi connected");
  //  Serial.println("IP address: ");
  //  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  //Serial.println("In reconnect...");
  while (!client.connected()) {
    //  Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("Arduino_Gas", mqtt_user, mqtt_pass)) {
      //  Serial.println("connected");
    } else {
      //      Serial.print("failed, rc=");
      //      Serial.print(client.state());
      //      Serial.println(" try again in 5 seconds");
      // delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  char msg[8];
  if (!client.connected()) {
    reconnect();
  }

  sprintf(msg, "%i", 10);
  client.publish("mq2_mqtt", msg);
  //  Serial.print("MQ2 gas value:");
  //  Serial.println(msg);


}
