int pin1 = 3;
int pin2 = 5;
int pin3 = 6;
int pin4 = 9;
int pin5 = 10;
int pin6 = 11;
int valo = 100;
int del = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


  analogWrite(pin1, valo);
  analogWrite(pin2, 0);
  analogWrite(pin3, 0);
  analogWrite(pin4, valo);
  analogWrite(pin5, 0);
  analogWrite(pin6, 0);
  delay(del);//1
  analogWrite(pin1, valo);
  analogWrite(pin2, 0);
  analogWrite(pin3, 0);
  analogWrite(pin4, 0);
  analogWrite(pin5, 0);
  analogWrite(pin6, valo);
  delay(del);//2
  analogWrite(pin1, 0);
  analogWrite(pin2, valo);
  analogWrite(pin3, 0);
  analogWrite(pin4, 0);
  analogWrite(pin5, 0);
  analogWrite(pin6, valo);
  delay(del);//3
  analogWrite(pin1, 0);
  analogWrite(pin2, valo);
  analogWrite(pin3, valo);
  analogWrite(pin4, 0);
  analogWrite(pin5, 0);
  analogWrite(pin6, 0);
  delay(del);//4
  analogWrite(pin1, 0);
  analogWrite(pin2, valo);
  analogWrite(pin3, 0);
  analogWrite(pin4, 0);
  analogWrite(pin5, valo);
  analogWrite(pin6, 0);
  delay(del);//5
  analogWrite(pin1, 0);
  analogWrite(pin2, 0);
  analogWrite(pin3, 0);
  analogWrite(pin4, valo);
  analogWrite(pin5, valo);
  analogWrite(pin6, 0);
  delay(del);//6
}
