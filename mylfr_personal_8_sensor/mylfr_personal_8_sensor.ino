
#define ena 11
#define inA 10
#define inB 9
#define stdnby 8
#define inC 6
#define inD 7
#define enb 5
#define wall_sonar_trigPin 13
#define wall_sonar_echoPin 12
#define obstacle_sonar_trigPin 2
#define obstacle_sonar_echoPin 3

int wall_set_point = 5;
//sensor analog value should be taken before placing it to th[] array
int uturn = 200;
int th[8] = {467, 485, 448, 406, 382, 492, 451, 429};//for pena track
int sen_pins[8] = {A7, A6, A5, A4, A3, A2, A1, A0};
void wheel(int lm, int rm);
int distance_from_sonar(int trigPin_for_sonar, int echoPin_for_sonar);

int i, sen[8], s[8], lastSensor, lastError;
int base_L = 255;
int base_R = 255;
float kp_sonar = 5;
float kd_sonar = 20;
float ki_sonar = 1;
unsigned long myTime;

float kp = 4;
float kd = 20;
float ki = 1;
int incomingByte;

void setup()
{
  Serial.begin(9600);
  mot_init();
  other_init();
  sonar_init();
}
void loop()
{

  //wheel(255, 255);
  line_follow();
  // int obstacle_sonar_distance =  distance_from_sonar( obstacle_sonar_trigPin,  obstacle_sonar_echoPin);

  //int wall_sonar_distance =  distance_from_sonar( wall_sonar_trigPin,  wall_sonar_echoPin);
  //  if (obstacle_sonar_distance == 5) {
  //    obstacle_avoid();
  //  }
  //  else if (wall_sonar_distance < 12) {
  // wall_follow();
  //  }
  //  else {
  //    line_follow();
  //  }

  //  if (Serial.available() > 0) {
  //    // read the incoming byte:
  //    wheel(0, 0);
  //    delay(1000);
  //    kp_sonar = Serial.parseInt();
  //    kd_sonar = Serial.parseInt();
  //    ki_sonar = Serial.parseInt();
  //    wheel(0, 0);
  //    delay(1000);
  //
  //
  //  }
  //  Serial.print(kp);
  //  Serial.print(" ");
  //  Serial.print(kd);
  //  Serial.print(" ");
  //  Serial.print(ki);
  //  Serial.println(" ");
  //  Serial.print(wall_sonar_distance);
  //  Serial.println(" ");



}
void obstacle_avoid() {


}

void other_init()
{
  lastSensor = 0;
  lastError = 0;
  //Serial.begin(9600);
}
void sonar_init() {
  pinMode(obstacle_sonar_trigPin, OUTPUT);
  pinMode(obstacle_sonar_echoPin, INPUT);
  pinMode(wall_sonar_trigPin, OUTPUT);
  pinMode(wall_sonar_echoPin, INPUT);

}

int distance_from_sonar(int trigPin_for_sonar, int echoPin_for_sonar) {
  long duration;
  int distance;
  digitalWrite(trigPin_for_sonar, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_for_sonar, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_for_sonar, LOW);
  duration = pulseIn(echoPin_for_sonar, HIGH);
  distance = duration * 0.034 / 2;
  return distance;

}
void mot_init()
{
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(stdnby, OUTPUT);
  digitalWrite(stdnby, HIGH);
  digitalWrite(inA, HIGH);
  digitalWrite(inB, HIGH);
  digitalWrite(inC, HIGH);
  digitalWrite(inD, HIGH);

}

void wheel(int lm, int rm)
{
  if (lm == 0)
  {
    digitalWrite(inC, HIGH);
    digitalWrite(inD, HIGH);
  }
  if (lm > 0)
  {
    digitalWrite(inC, LOW);
    digitalWrite(inD, HIGH);
  }
  else if (lm < 0)
  {
    digitalWrite(inC, HIGH);
    digitalWrite(inD, LOW);
  }


  if (rm == 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, HIGH);
  }
  if (rm > 0)
  {
    digitalWrite(inA, LOW);
    digitalWrite(inB, HIGH);
  }
  else if (rm < 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
  }
  if (lm > 254) lm = 254;
  if (lm < -254) lm = -254;
  if (rm > 254) rm = 254;
  if (rm < -254) rm = -254;

  analogWrite(ena, abs(rm));
  analogWrite(enb, abs(lm));

}

int readSensor()
{
  for (i = 0; i < 8; i++)
  {
    sen[i] = analogRead(sen_pins[i]);
    if (sen[i] < th[i])
    {
      s[i] = 1;
    }
    else {
      s[i] = 0;
    }
  }
  //  for (i = 0; i < 8; i++)
  //  {
  //
  //    Serial.print(s[i]);
  //    Serial.print(" ");
  //
  //  }
  //  Serial.println(" ");

  int error, sum;
  sum = s[0] + s[1] + s[2] + s[3] + s[4] + s[5] + s[6] + s[7];

  if (sum != 0)
  {
    error = (s[0] * 10 + s[1] * 20 + s[2] * 30 + s[3] * 40 + s[4] * 50 + s[5] * 60 + s[6] * 70 + s[7] * 80) / sum - 40;
  }
  else
  {
    error = 420;
  }

  if (s[0] == 1) lastSensor = 1;
  else if (s[7] == 1) lastSensor = 2;
  else if (s[4] == 1) lastSensor = 3;
  Serial.print(0);
  Serial.print(" ");
  Serial.print(error);
  Serial.print(" ");
  return error;
}


void line_follow()
{
  int error, corr, final_l, final_r;
  float p, d, I = 0;
  error = readSensor();
  if (error == 420)
  {
    if (lastSensor == 1) {
      wheel(-uturn, uturn);
    }
    else if (lastSensor == 2) {
      wheel(uturn, -uturn);
    }
    else if (lastSensor == 3) {
      wheel(uturn, uturn);
    }
  }
  else
  {
    p = kp * error;
    d = kd * (error - lastError);
    I = ki * (I + error);
    corr = p + d + I;
    Serial.println(corr);
    final_l = base_L + corr;
    final_r = base_R - corr;
    if (final_l < 0)final_l = 0;
    if (final_r < 0) final_r = 0;


    wheel(final_l, final_r );
    if ((error - lastError) != 0) delay(5);
    lastError = error;
  }

}
void wall_follow()
{
  int error, corr, final_l, final_r;
  float p, d, I = 0;
  int dat = distance_from_sonar( wall_sonar_trigPin,  wall_sonar_echoPin);
  error =  dat - wall_set_point;


  p = kp_sonar * error;
  d = kd_sonar * (error - lastError);
  I = ki_sonar * (I + error);
  corr = p + d + I;
  //Serial.println(corr);
  final_l = base_L + corr;
  final_r = base_R - corr;
  if (final_l < 0)final_l = 0;
  if (final_r < 0) final_r = 0;


  wheel(final_l, final_r );
  if ((error - lastError) != 0) delay(5);
  lastError = error;


}
