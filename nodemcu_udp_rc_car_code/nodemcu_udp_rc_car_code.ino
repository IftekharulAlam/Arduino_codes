#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// Set WiFi credentials
#define WIFI_SSID "dhong"
#define WIFI_PASS "01521439838"
#define UDP_PORT 8888

// UDP
WiFiUDP UDP;
char incomingByte;
//LEFT
int IN1_L = D1;
int IN2_L = D2;
int IN3_L = D3;
int IN4_L = D4;

int speed_min = 135; //the minimum "speed" the motors will turn - take it lower and motors don't turn
int speed_max = 255; //

int speed_left = speed_max; // set both motors to maximum speed
int speed_right = speed_max;

void left();
void right();
void forward();
void backward();
void forward_left();
void forward_right();
void back_left();
void back_right();
void setup() {
  Serial.begin(115200);
  Serial.println();


  WiFi.begin(WIFI_SSID, WIFI_PASS);


  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }

  // Connected to WiFi
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  // Begin listening to UDP port
  UDP.begin(UDP_PORT);
  Serial.print("Listening on UDP port ");
  Serial.println(UDP_PORT);
  pinMode(IN1_L, OUTPUT);
  pinMode(IN2_L, OUTPUT);
  pinMode(IN3_L, OUTPUT);
  pinMode(IN4_L, OUTPUT);
  analogWrite(IN1_L, 0);
  analogWrite(IN2_L, 0);
  analogWrite(IN3_L, 0);
  analogWrite(IN4_L, 0);
}

void loop() {

  // If packet received...
  int packetSize = UDP.parsePacket();
  if (packetSize) {

    incomingByte = UDP.read();

    switch (incomingByte)
    {
      case 'S':
        {
          stopy();
          Serial.println("Stop\n");
          incomingByte = '*';
        }
        break;

      case 'F':

        { left();

          Serial.println("Forward\n");
          incomingByte = '*';
        }
        break;

      case 'B':

        { right();
           Serial.println("Backward\n");
          incomingByte = '*';
        }
        break;

      case 'R':
        // turn right
        {
          forward();
          Serial.println("Rotate Right\n");
          incomingByte = '*';
        }
        break;
      case 'L':
        {
          backward();
          Serial.println("Rotate Left\n");
          incomingByte = '*';
        }
        break;
    }

  }

}
void forward() {
  //left
  analogWrite(IN1_L, speed_left);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, speed_left);


};
void backward() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, speed_left);

  analogWrite(IN3_L, speed_left);

  analogWrite(IN4_L, 0);

};
void forward_left() {
  //left
  analogWrite(IN1_L, speed_left);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, 0);

};
void forward_right() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, speed_left);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, 0);

};
void back_right() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, speed_left);


};
void back_left() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, speed_left);

  analogWrite(IN4_L, 0);



};
void right() {
  //left
  analogWrite(IN1_L, speed_left);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, speed_left);

  analogWrite(IN4_L, 0);



};
void left() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, speed_left);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, speed_left);


};

void stopy() {
  //left
  analogWrite(IN1_L, 0);

  analogWrite(IN2_L, 0);

  analogWrite(IN3_L, 0);

  analogWrite(IN4_L, 0);


};
