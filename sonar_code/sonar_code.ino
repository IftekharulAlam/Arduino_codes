const int trigPin_for_sonar1 =2;
const int echoPin_for_sonar1 = 3;
long duration1;
int distance1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin_for_sonar1, OUTPUT);
  pinMode(echoPin_for_sonar1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin_for_sonar1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_for_sonar1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_for_sonar1, LOW);
  duration1 = pulseIn(echoPin_for_sonar1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  Serial.println(distance1);
}
