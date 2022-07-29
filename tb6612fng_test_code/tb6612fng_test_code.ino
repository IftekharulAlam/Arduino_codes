#define ena 5
#define inA 6
#define inB 7
#define stdnby 8
#define inC 9
#define inD 10
#define enb 11

void setup() {
  // put your setup code here, to run once:
  pinMode(inA, OUTPUT);
  pinMode(stdnby, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  digitalWrite(stdnby,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
    analogWrite(ena, 255);
    digitalWrite(inC, HIGH);
    digitalWrite(inD, LOW);
    analogWrite(enb, 255);
}
