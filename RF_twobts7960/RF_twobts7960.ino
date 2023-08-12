#define L_1 2
#define L_2 3
#define R_1 4
#define R_2 5

int ch_1 = 9;
int ch_2 = 10;
int ch_3 = 11;
float wspeed= 0 ;
   
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  pinMode(ch_1 , INPUT);
  pinMode(ch_2 , INPUT);
  pinMode(ch_3 , INPUT);
}

void loop() {
  int v_1 =  pulseIn(ch_1 ,HIGH);
  int v_2 =  pulseIn(ch_2 ,HIGH);
int v_3 =  pulseIn(ch_3 ,HIGH);
wspeed = (v_3 - 1000)*0.255;
  if(v_2<1250){
    down();
  }
  else if(v_2>1750){
    up();
  }

  else if(v_1>1750){
    left();
  }
  else if(v_1<1250){
    right();
  }
  else{
    Stop();
  }
    
}

void left(){
  analogWrite(L_1, 0);
  digitalWrite(L_2, wspeed);
  digitalWrite(R_1, wspeed);
  digitalWrite(R_2, 0);
}

void right(){
  analogWrite(L_1, wspeed);
  analogWrite(L_2, 0);
  analogWrite(R_1, 0);
  analogWrite(R_2, wspeed);
}

void up(){
  analogWrite(L_1, wspeed);
  analogWrite(L_2, 0);
  analogWrite(R_1, wspeed);
  analogWrite(R_2, 0);
}

void down(){
  analogWrite(L_1, 0);
  analogWrite(L_2, wspeed);
  analogWrite(R_1, 0);
  analogWrite(R_2, wspeed);
}

void Stop(){
  analogWrite(L_1, 0);
  analogWrite(L_2, 0);
  analogWrite(R_1, 0);
  analogWrite(R_2, 0);
}
