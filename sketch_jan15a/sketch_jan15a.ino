int high =11;
int low = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(high, OUTPUT);
  pinMode(low, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(high, HIGH);
  digitalWrite(low, HIGH);
  delay(100);
  digitalWrite(high, LOW);
  digitalWrite(low, LOW);
  delay(100);

}
