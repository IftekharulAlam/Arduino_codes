
//LEFT
int ENA_L =6;
int IN1_L =38;
int IN2_L =39; 
int IN3_L =40; 
int IN4_L =41;
int ENB_L =7;


//RIGHT
int ENA_R= 8;
int IN1_R =42;
int IN2_R =43; 
int IN3_R =44; 
int IN4_R =45;
int ENB_R =9;

char incomingByte=0; // for incoming serial data
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

const int trigPin_for_sonar1 = 22;
const int echoPin_for_sonar1 = 23;

const int trigPin_for_sonar2 = 24;
const int echoPin_for_sonar2 = 25;

const int trigPin_for_sonar3 = 26;
const int echoPin_for_sonar3 = 27;

const int trigPin_for_sonar4 = 28;
const int echoPin_for_sonar4 = 29;

const int trigPin_for_sonar5 =30;
const int echoPin_for_sonar5 =31;

const int trigPin_for_sonar6 = 32;
const int echoPin_for_sonar6 = 33;

const int trigPin_for_sonar7 = 34;
const int echoPin_for_sonar7 = 35;

const int trigPin_for_sonar8 = 36;
const int echoPin_for_sonar8 = 37;

// defines variables
long duration1;
int distance1;

long duration2;
int distance2;

long duration3;
int distance3;

long duration4;
int distance4;

long duration5;
int distance5;

long duration6;
int distance6;

long duration7;
int distance7;

long duration8;
int distance8;


void setup() {

 Serial1.begin(9600);//Serial1 is for BTcar
 Serial2.begin(9600);//Serial2 is for BTData
  // put your setup code here, to run once:
pinMode(ENA_L,OUTPUT);
pinMode(IN1_L,OUTPUT);
pinMode(IN2_L,OUTPUT);
pinMode(IN3_L,OUTPUT);
pinMode(IN4_L,OUTPUT);
pinMode(ENB_L,OUTPUT);
  // put your setup code here, to run once:
pinMode(ENA_R,OUTPUT);
pinMode(IN1_R,OUTPUT);
pinMode(IN2_R,OUTPUT);
pinMode(IN3_R,OUTPUT);
pinMode(IN4_R,OUTPUT);
pinMode(ENB_R,OUTPUT);

  
pinMode(trigPin_for_sonar1, OUTPUT);
pinMode(echoPin_for_sonar1, INPUT); 

pinMode(trigPin_for_sonar2, OUTPUT);
pinMode(echoPin_for_sonar2, INPUT); 

pinMode(trigPin_for_sonar3, OUTPUT);
pinMode(echoPin_for_sonar3, INPUT); 

pinMode(trigPin_for_sonar4, OUTPUT);
pinMode(echoPin_for_sonar4, INPUT); 

pinMode(trigPin_for_sonar5, OUTPUT);
pinMode(echoPin_for_sonar5, INPUT); 

pinMode(trigPin_for_sonar6, OUTPUT);
pinMode(echoPin_for_sonar6, INPUT); 

pinMode(trigPin_for_sonar7, OUTPUT);
pinMode(echoPin_for_sonar7, INPUT); 

pinMode(trigPin_for_sonar8, OUTPUT);
pinMode(echoPin_for_sonar8, INPUT); 


}
void loop() {
if (Serial1.available() > 0) {
    incomingByte = Serial1.read();
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
     case '1':
        
      { speed_left = 20; 
       speed_right = 20;
       //Serial.println("Speed 1\n");
       incomingByte='*';}
     break;
    case '2':
      { 
        speed_left = 40; 
       speed_right = 40;
       //Serial.println("Speed 2 \n");
       incomingByte='*';}
     break;
    case '3':
      { 
        speed_left = 60; 
       speed_right = 60;
       //Serial.println("Speed 3 \n");
       incomingByte='*';}
     break; 
        case '4':
      { 
        speed_left = 80; 
       speed_right = 80;
       //Serial.println("Speed 4 \n");
       incomingByte='*';}
     break; 
        case '5':
      { 
        speed_left = 100; 
       speed_right = 100;
       //Serial.println("Speed 5 \n");
       incomingByte='*';}
     break; 
        case '6':
      { 
        speed_left = 120; 
       speed_right = 120;
       //Serial.println("Speed 6 \n");
       incomingByte='*';}
     break; 
        case '7':
      { 
        speed_left = 140; 
       speed_right = 140;
      // Serial.println("Speed 7 \n");
       incomingByte='*';}
     break; 
        case '8':
      { 
        speed_left = 160; 
       speed_right = 160;
       //Serial.println("Speed 8 \n");
       incomingByte='*';}
     break; 
        case '9':
      { 
        speed_left = 200; 
       speed_right = 200;
       //Serial.println("Speed 9 \n");
       incomingByte='*';}
     break; 
        case 'q':
      { 
        speed_left = 255; 
       speed_right = 255;
       Serial.println("Speed full \n");
       incomingByte='*';}
     break; 
        case 'J':
      { 
       back_right();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'H':
      { 
       back_left();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'I':
      { 
       forward_right();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'G':
      { 
      forward_left();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;      
  }







  
int value1 = sensor1();
int value2 = sensor2();
int value3 = sensor3();
int value4 = sensor4();
int value5 = sensor5();
int value6 = sensor6();
int value7 = sensor7();
int value8 = sensor8();

Serial2.print(value1);
Serial2.print(" ");

Serial2.print(value2);
Serial2.print(" ");

Serial2.print(value3);
Serial2.print(" ");

Serial2.print(value4);
Serial2.print(" ");

Serial2.print(value5);
Serial2.print(" ");

Serial2.print(value6);
Serial2.print(" ");

Serial2.print(value7);
Serial2.print(" ");

Serial2.print(value8);
Serial2.print(" ");


Serial2.println();


}
int sensor1(){
  digitalWrite(trigPin_for_sonar1, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin_for_sonar1, HIGH);
delayMicroseconds(10);

  digitalWrite(trigPin_for_sonar1, LOW);
duration1 = pulseIn(echoPin_for_sonar1, HIGH);
distance1= duration1*0.034/2;
return distance1;

  
  }

int sensor2(){
  digitalWrite(trigPin_for_sonar2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_for_sonar2, HIGH);
delayMicroseconds(10);
  digitalWrite(trigPin_for_sonar2, LOW);
duration2 = pulseIn(echoPin_for_sonar2, HIGH);
distance2= duration2*0.034/2;
return distance2;

  
  }

int sensor3(){
  digitalWrite(trigPin_for_sonar3, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin_for_sonar3, HIGH);
delayMicroseconds(10);

  digitalWrite(trigPin_for_sonar3, LOW);
duration3 = pulseIn(echoPin_for_sonar3, HIGH);
distance3= duration3*0.034/2;
return distance3;

  
  }


  int sensor4(){
  digitalWrite(trigPin_for_sonar4, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin_for_sonar4, HIGH);
delayMicroseconds(10);

  digitalWrite(trigPin_for_sonar4, LOW);
duration4 = pulseIn(echoPin_for_sonar4, HIGH);
distance4= duration4*0.034/2;
return distance4;

  
  }
  int sensor5(){
  digitalWrite(trigPin_for_sonar5, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin_for_sonar5, HIGH);
delayMicroseconds(10);

  digitalWrite(trigPin_for_sonar5, LOW);
duration5 = pulseIn(echoPin_for_sonar5, HIGH);
distance5= duration5*0.034/2;
return distance5;

  
  }

int sensor6(){
  digitalWrite(trigPin_for_sonar6, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_for_sonar6, HIGH);
delayMicroseconds(10);
  digitalWrite(trigPin_for_sonar6, LOW);
duration6 = pulseIn(echoPin_for_sonar6, HIGH);
distance6= duration6*0.034/2;
return distance6;

  
  }

int sensor7(){
  digitalWrite(trigPin_for_sonar7, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin_for_sonar7, HIGH);
delayMicroseconds(10);

  digitalWrite(trigPin_for_sonar7, LOW);
duration7 = pulseIn(echoPin_for_sonar7, HIGH);
distance7= duration7*0.034/2;
return distance7;

  
  }


  int sensor8(){
  digitalWrite(trigPin_for_sonar8, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin_for_sonar8, HIGH);
delayMicroseconds(10);

  digitalWrite(trigPin_for_sonar8, LOW);
duration8 = pulseIn(echoPin_for_sonar8, HIGH);
distance8= duration8*0.034/2;
return distance8;

  
  }

void left(){
  //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,HIGH);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,HIGH);
  analogWrite(ENB_L,speed_left);
  //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,HIGH);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,HIGH);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,speed_right);

  
  };
void right(){
   //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,HIGH);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,HIGH);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,speed_left);
  //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,HIGH);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,HIGH);
  analogWrite(ENB_R,speed_right);
  
  };
void forward_left(){
  //left
  analogWrite(ENA_L,0);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,0);
  
  //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,HIGH);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,HIGH);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,speed_right);
  
  };
void forward_right(){
   //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,HIGH);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,HIGH);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,speed_left);

 //right
  analogWrite(ENA_R,0);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,0);
 
  };
void back_left(){
   //left
  analogWrite(ENA_L,0);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,0);
   //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,HIGH);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,HIGH);
  analogWrite(ENB_R,speed_right);

  
  };
void back_right(){
  
  //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,HIGH);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,HIGH);
  analogWrite(ENB_L,speed_left);

 //right
  analogWrite(ENA_R,0);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,0);
  
  
  };
void forward(){
 //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,HIGH);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,HIGH);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,speed_left);

 //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,HIGH);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,HIGH);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,speed_right);


  
  };
void backward(){
 //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,HIGH);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,HIGH);
  analogWrite(ENB_L,speed_left);

 //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,HIGH);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,HIGH);
  analogWrite(ENB_R,speed_right);


  };

void stopy(){
  //
    analogWrite(ENA_L,0);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,0);
  
  analogWrite(ENA_R,0);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,0);

  
  };
  

  
