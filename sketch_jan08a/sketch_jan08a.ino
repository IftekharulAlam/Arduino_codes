int led1 = 3;
int led2 = 11;
int led3 = 6;
int led4 = 5;
int led5 = 10;
int led6 = 9;

int potpin = A0;
int potval;



void setup() {
pinMode(led1, INPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
}

void loop() {
  potval =200;

  digitalWrite(led5, LOW);
  digitalWrite(led1, HIGH);
  delay(potval);
  digitalWrite(led6, LOW);
  digitalWrite(led2, HIGH);
  delay(potval);
  digitalWrite(led1, LOW);
  digitalWrite(led3, HIGH);
  delay(potval);
  digitalWrite(led2, LOW);
  digitalWrite(led4, HIGH);
  delay(potval);
  digitalWrite(led3, LOW);
  digitalWrite(led5, HIGH);
  delay(potval);
  digitalWrite(led4, LOW);
  digitalWrite(led6, HIGH);
  delay(potval);
}
