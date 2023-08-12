void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = 200;
  int b =600;
  Serial.println(-a-b);

}
