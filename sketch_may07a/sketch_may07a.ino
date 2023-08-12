#define ena 11
#define inA 10
#define inB 9
#define dif 8
#define inC 7
#define inD 6
#define enb 5
void setup() {
  // put your setup code here, to run once:
  pinMode(dif, OUTPUT);
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(inA, LOW);
  digitalWrite(inB, HIGH);
  analogWrite(ena, 20);
  digitalWrite(dif, HIGH);
  digitalWrite(inC, HIGH);
  digitalWrite(inD, LOW);
  analogWrite(enb, 20);
}
