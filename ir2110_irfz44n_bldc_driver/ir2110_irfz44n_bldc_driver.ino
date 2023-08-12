const int HallApin = 14;
const int HallBpin = 15;
const int HallCpin = 16;
int pin1 = 3;
int pin2 = 5;
int pin3 = 6;
int pin4 = 9;
int pin5 = 10;
int pin6 = 11;

int valo = 255;
int del = 100;
int HallAState = 0;
int HallBState = 0;
int HallCState = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(HallApin, INPUT);
  pinMode(HallBpin, INPUT);
  pinMode(HallCpin, INPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  HallAState = digitalRead(HallApin);
  HallBState = digitalRead(HallBpin);
  HallCState = digitalRead(HallCpin);
  Serial.print(HallAState);
  Serial.print(" ");
  Serial.print(HallBState);
  Serial.print(" ");
  Serial.print(HallCState);
  Serial.println(" ");
  //


  if (HallAState == HIGH && HallBState == HIGH && HallCState == LOW) {//first
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
    analogWrite(pin3, valo);
    analogWrite(pin4, 0);
    analogWrite(pin5, 0);
    analogWrite(pin6, valo);
  }

  else if (HallAState == LOW && HallBState == HIGH && HallCState == LOW) {//second
    analogWrite(pin1, 0);
    analogWrite(pin2, valo);
    analogWrite(pin3, valo);
    analogWrite(pin4, 0);
    analogWrite(pin5, 0);
    analogWrite(pin6, 0);
  }
  else if (HallAState == LOW && HallBState == HIGH && HallCState == HIGH) {//third
    analogWrite(pin1, 0);
    analogWrite(pin2, valo);
    analogWrite(pin3, 0);
    analogWrite(pin4, 0);
    analogWrite(pin5, valo);
    analogWrite(pin6, 0);
  }
  else if (HallAState == LOW && HallBState == LOW && HallCState == HIGH) {//forth
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
    analogWrite(pin3, 0);
    analogWrite(pin4, valo);
    analogWrite(pin5, valo);
    analogWrite(pin6, 0);
  }
  else if (HallAState == HIGH && HallBState == LOW && HallCState == HIGH) {//5
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
    analogWrite(pin3, valo);
    analogWrite(pin4, valo);
    analogWrite(pin5, valo);
    analogWrite(pin6, valo);
  }  else if (HallAState == HIGH && HallBState == LOW && HallCState == LOW) {
    analogWrite(pin1, valo);
    analogWrite(pin2, 0);
    analogWrite(pin3, 0);
    analogWrite(pin4, 0);
    analogWrite(pin5, 0);
    analogWrite(pin6, valo);
  }

}
