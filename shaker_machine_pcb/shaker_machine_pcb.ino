int in1 = 5;
int in2 = 6;
int speedo = 255;
void forward();
void reverse();
void stopy();
void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  stopy();
  forward();
  delay(200);
  stopy();
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(600);
  reverse();
  delay(600);



}
void forward() {
  analogWrite(in1, speedo);
  analogWrite(in2, 0);

}
void reverse() {
  analogWrite(in1, 0);
  analogWrite(in2, speedo);
}
void stopy() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);


}
