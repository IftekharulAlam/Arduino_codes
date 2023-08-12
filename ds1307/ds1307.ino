int RPWM=5;
int LPWM=6;
// timer 0
int L_EN=7;
int R_EN=8;

void setup() {
  // put your setup code here, to run once:
  for(int i=5;i<9;i++){
   pinMode(i,OUTPUT);
  }
 //  for(int i=5;i<9;i++){
   //digitalWrite(i,LOW);
  //}
   //delay(1000);
    Serial.begin(9600);
  }



void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("EN High");
  digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
delay(500);
for(int i=0;i<256;i++){
  analogWrite(RPWM,i);
//analogWrite(LPWM,i);
  delay(100);
}
digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
delay(500);
for(int i=0;i<256;i++){
 // analogWrite(RPWM,i);
  analogWrite(LPWM,i);
  delay(100);
}
delay(500);

}
