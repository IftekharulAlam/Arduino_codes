
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";


int IN1 =2;
int IN2 =3; 
int IN3 =4; 
int IN4 =5;



    char incomingByte=0;
int speed_min = 135; //the minimum "speed" the motors will turn - take it lower and motors don't turn
int speed_max = 255; //

int speed_left =speed_max; // set both motors to maximum speed
int speed_right = speed_max;

void left();
void right();
void forward();
void backward();
void stopy();
void setup() {
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
    radio.setChannel(1);

  radio.startListening();

  
  // put your setup code here, to run once:
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

 if (radio.available()) {
    radio.read(&incomingByte, sizeof(incomingByte));

 }
  switch(incomingByte)
  {
     case 'S':
      {
        stopy();
       //Serial.println("Stop\n"); 
       incomingByte='*';}
     break;
     
     case 'B':
      
     {  backward();
       
      // Serial.println("Forward\n");
       incomingByte='*';}
     break;
    
      case 'F':
       
    {   forward();
      // Serial.println("Backward\n");
       incomingByte='*';}
     break;
     
     case 'R':
     // turn right
     {  
       right(); 
      // Serial.println("Rotate Right\n");
       incomingByte='*';}
     break;
       case 'L':
      { 
       left();     
       //Serial.println("Rotate Left\n");
       incomingByte='*';}
     break;

     case 'G':
      
     {  rightForward();
       
      // Serial.println("Right Forward\n");
       incomingByte='*';}
     break;
    
      case 'LF':
       
    {   leftForward();
      // Serial.println("Left Forward\n");
       incomingByte='*';}
     break;
     
     case 'RB':
     {  
       rightBackward(); 
      // Serial.println("Right Backward\n");
       incomingByte='*';}
     break;
       case 'LB':
      { 
       leftBackward();     
       //Serial.println("Left Backward\n");
       incomingByte='*';}
     break;
}
}
void left(){
 //left
  analogWrite(IN1,0);

  analogWrite(IN2,speed_left);
  //right
  analogWrite(IN3,speed_left);

  analogWrite(IN4,0);

  
  };
void right(){
 //left
  analogWrite(IN1,speed_left);

  analogWrite(IN2,0);
  //right
  analogWrite(IN3,0);

  analogWrite(IN4,speed_left);

  
  };


void forward(){
analogWrite(IN1,speed_left);

  analogWrite(IN2,0);
  //right
  analogWrite(IN3,speed_left);

  analogWrite(IN4,0);
  
  };
void backward(){

 //left
  analogWrite(IN1,0);

  analogWrite(IN2,speed_left);
  //right
  analogWrite(IN3,0);

  analogWrite(IN4,speed_left);

  };


  
void leftForward(){
 //left
  analogWrite(IN1,0);

  analogWrite(IN2,0);
  //right
  analogWrite(IN3,speed_left);

  analogWrite(IN4,0);

  
  };
void rightForward(){
 //left
  analogWrite(IN1,0);

  analogWrite(IN2,0);
  //right
  analogWrite(IN3,speed_left);

  analogWrite(IN4,0);

  
  };


void rightBackward(){
analogWrite(IN1,speed_left);

  analogWrite(IN2,0);
  //right
  analogWrite(IN3,0);

  analogWrite(IN4,0);
  
  };
void leftBackward(){

 //left
  analogWrite(IN1,0);

  analogWrite(IN2,speed_left);
  //right
  analogWrite(IN3,0);

  analogWrite(IN4,0);

  };

void stopy(){
 //left
  analogWrite(IN1,0);

  analogWrite(IN2,0);
  //right
  analogWrite(IN3,0);

  analogWrite(IN4,0);

  
  };
