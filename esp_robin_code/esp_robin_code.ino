#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>


char auth[] = "MKpWch0GWUG5UwkYwzzMs8pY-UOy-qu2";


char ssid[] = "dhong";  //Enter your WIFI Name
char pass[] = "01521439838";  //Enter your WIFI Password

#define DHTPIN 14          // Digital pin 5
int Relay_1 = 16;
int Relay_2 = 5;
int Relay_3 = 4;
int Relay_4 = 0;

int Mq_2_pin = A0;
int Motion_Sensor_pin = 2 ;
WidgetLED led1(V7);


// Uncomment whatever type you're using!
#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  //float h = 23.0;
  //float t = 28.0; // or dht.readTemperature(true) for Fahrenheit
  int mq_data = analogRead(Mq_2_pin);
  if (mq_data > 500) {
    Blynk.notify("FIre! Smoke Detected !!!");

  }

  if (digitalRead(Motion_Sensor_pin) == 1) {
    Blynk.notify("!!!Motion Detected!!!");

                 led1.on();
               }
                 else {
                 led1.off();
               }
                 //
                 //    if (isnan(h) || isnan(t)) {
                 //      Serial.println("Failed to read from DHT sensor!");
                 //      return;
                 //    }
                 // You can send any value at any time.
                 // Please don't send more that 10 values per second.
                 Blynk.virtualWrite(V4, mq_data);  //V4 is for MQ2 Sensor
                 Blynk.virtualWrite(V5, h);  //V5 is for Humidity
                 Blynk.virtualWrite(V6, t);  //V6 is for Temperature

               }
                 BLYNK_WRITE(V1)
               {
                 int pinValue = param.asInt();
                 if (pinValue == 1) {
                 digitalWrite(Relay_1, HIGH);
               }
                 else {
                 digitalWrite(Relay_1, LOW);

               }

               }
                 BLYNK_WRITE(V2)
               {
                 int pinValue = param.asInt();
                 if (pinValue == 1) {
                 digitalWrite(Relay_2, HIGH);
               }
                 else {
                 digitalWrite(Relay_2, LOW);

               }

               }
                 BLYNK_WRITE(V3)
               {
                 int pinValue = param.asInt();
                 if (pinValue == 1) {
                 digitalWrite(Relay_3, HIGH);
               }
                 else {
                 digitalWrite(Relay_3, LOW);

               }

               }
                 BLYNK_WRITE(V0)
               {
                 int pinValue = param.asInt();
                 if (pinValue == 1) {
                 digitalWrite(Relay_4, HIGH);
               }
                 else {
                 digitalWrite(Relay_4, LOW);

               }

               }


                 void setup()
               {
                 Serial.begin(9600); // See the connection status in Serial Monitor
                 Blynk.begin(auth, ssid, pass);

                 dht.begin();

                 // Setup a function to be called every second
                 pinMode(Relay_1, OUTPUT);
                 pinMode(Relay_2, OUTPUT);
                 pinMode(Relay_3, OUTPUT);
                 pinMode(Relay_4, OUTPUT);
                 pinMode(Mq_2_pin, INPUT);
                 pinMode(Motion_Sensor_pin, INPUT);



                 timer.setInterval(1000L, sendSensor);
               }

                 void loop()
               {
                 Blynk.run(); // Initiates Blynk
                 timer.run(); // Initiates SimpleTimer
               }
