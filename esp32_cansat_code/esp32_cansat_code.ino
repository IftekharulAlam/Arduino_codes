#include <Wire.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <DHT.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
const char* ssid = "dhong";
const char* password = "01521439838";

WebServer server(80);
DHT dht(26, DHT22);
Adafruit_MPU6050 mpu;
Adafruit_BMP085 bmp;
void handleRoot() {
  char msg[2000];

  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  snprintf(msg, 2000,
           "<html>\
  <head>\
    <meta http-equiv='refresh' content='1'/>\
    <meta name='viewport' content='width=device-width, initial-scale=1'>\
    <link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.7.2/css/all.css' integrity='sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr' crossorigin='anonymous'>\
    <title>ESP32 Sensor Server</title>\
    <style>\
    html { font-family: Arial; display: inline-block; margin: 0px auto; text-align: center;}\
    h2 { font-size: 3.0rem; }\
    p { font-size: 3.0rem; }\
    .units { font-size: 1.2rem; }\
    .dht-labels { font-size: 1.5rem; vertical-align: middle; padding-bottom: 15px;}\
    </style>\
  </head>\
  <body>\
      <h2>ESP32 Sensor Server!</h2>\
      <p>\
        <i class='fas fa-thermometer-half' style='color:#ca3517;'></i>\
        <span class='dht-labels'>Temperature</span>\
        <span>%.2f</span>\
        <sup class='units'>&deg;C</sup>\
      </p>\
      <p>\
        <i class='fas fa-tint' style='color:#00add6;'></i>\
        <span class='dht-labels'>Humidity</span>\
        <span>%.2f</span>\
        <sup class='units'>&percnt;</sup>\
      </p>\
       <p>\
        <i class='fa-solid fa-air-conditioner' style='color:#00add6;'></i>\
        <span class='dht-labels'>Air Pressure</span>\
        <span>%.2f</span>\
        <sup class='units'>Pa;</sup>\
      </p>\
       <p>\
        <i class='fa-thin fa-line-height' style='color:#00add6;'></i>\
        <span class='dht-labels'>Altitude</span>\
        <span>%.2f</span>\
        <sup class='units'>meters;</sup>\
      </p>\
      <p>\
        <i class='fas fa-chart-line' style='color:#e58f20;'></i>\
        <span class='dht-labels'>Acceleration</span>\
        <br>X: %.2f m/s²<br>Y: %.2f m/s²<br>Z: %.2f m/s²\
      </p>\
      <p>\
        <i class='fas fa-sync-alt' style='color:#1e87f0;'></i>\
        <span class='dht-labels'>Gyroscope</span>\
        <br>X: %.2f &deg;/s<br>Y: %.2f &deg;/s<br>Z: %.2f &deg;/s\
      </p>\
  </body>\
</html>",
           readDHTTemperature(), readDHTHumidity(),
           readPressure(),readAltitude(),
           accel.acceleration.x, accel.acceleration.y, accel.acceleration.z,
           gyro.gyro.x, gyro.gyro.y, gyro.gyro.z
          );
  server.send(200, "text/html", msg);
}

void setup(void) {
  Serial.begin(115200);
  bmp.begin();
  dht.begin();
  mpu.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(2);
}

float readDHTTemperature() {
  float t = dht.readTemperature();
  if (isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    return -1;
  } else {
    Serial.println(t);
    return t;
  }
}

float readDHTHumidity() {
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return -1;
  } else {
    Serial.println(h);
    return h;
  }
}
float readPressure(){
  float p = bmp.readPressure();
  return p;
  }
float readAltitude(){
    float al = bmp.readAltitude(101500);
  return al;
  }
