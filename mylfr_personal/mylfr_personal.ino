//after setting pins for motor driver it should be checked that the motor is working
//forward or reverse
#define ena 11
#define inA 10
#define inB 9
#define stdnby 8
#define inC 7
#define inD 6
#define enb 5
#define trigPin_for_sonar1 13
#define echoPin_for_sonar1 12

//sensor analog value should be taken before placing it to th[] array
int uturn = 150;
int th[5] = {160, 230, 160, 220, 170 };
int sen_pins[5] = {A4, A3, A2, A1, A0};
void wheel(int lm, int rm);
int i, sen[5], s[5], lastSensor, lastError;
int base_L = 100;
int base_R = 100;
float kp = 1;
float kd = 0;
float ki = 0;
void setup()
{
  mot_init();
  other_init();
  sonar_init();
}
void loop()
{

  line_follow();
  //wheel(200, 200);

  //  int my_dis = distance_from_sonar(trigPin_for_sonar1, echoPin_for_sonar1);
  //  if (my_dis == 6 ) {
  //    wheel(0, 0);//stop
  //    delay(500);
  //    wheel(100, -100);//right
  //    delay(400);
  //    wheel(100, 100);//forward
  //    delay(500);
  //    wheel(-100, 100);//left
  //    delay(300);
  //    wheel(100, 100);//forward
  //    delay(500);
  //    wheel(-100, 100);//left
  //    delay(300);
  //
  //
  //  }
  //  else {
  //   wheel(90, 80);
  //   // line_follow();
  //  }





}

void other_init()
{
  lastSensor = 0;
  lastError = 0;
  Serial.begin(9600);
}
void sonar_init() {
  pinMode(trigPin_for_sonar1, OUTPUT);
  pinMode(echoPin_for_sonar1, INPUT);
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
    digitalWrite(inC, HIGH);
    digitalWrite(inD, LOW);
  }
  else if (lm < 0)
  {
    digitalWrite(inC, LOW);
    digitalWrite(inD, HIGH);
  }


  if (rm == 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, HIGH);
  }
  if (rm > 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
  }
  else if (rm < 0)
  {
    digitalWrite(inA, LOW);
    digitalWrite(inB, HIGH);
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
  for (i = 0; i < 5; i++)
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
  for (i = 0; i < 5; i++)
  {

    Serial.print(s[i]);
    Serial.print(" ");

  }
  Serial.println(" ");

  int error, sum;
  sum = s[0] + s[1] + s[2] + s[3] + s[4];

  if (sum != 0)
  {
    error = (s[0] * 10 + s[1] * 20 + s[2] * 30 + s[3] * 40 + s[4] * 50) / sum - 30;
  }
  else
  {
    error = 420;
  }

  if (s[0] == 1) lastSensor = 1;
  else if (s[4] == 1) lastSensor = 2;
  Serial.print(error);
  Serial.print(",");
  return error;
}
int read_sensor_quad() {

}


void line_follow()
{
  int error, corr, final_l, final_r;
  float p, d, I;
  error = readSensor();
  if (error == 420)
  {
    if (lastSensor == 1) {
      wheel(-uturn, uturn);
    }
    else if (lastSensor == 2) {
      wheel(uturn, -uturn);
    }
  }
  else
  {
    p = kp * error;
    d = kd * (error - lastError);
    I = ki * (I + error);
    corr = p + d + I;
    Serial.print(corr);
    final_l = base_L + corr;
    final_r = base_R - corr;
    if (final_l < 0)final_l = 0;
    if (final_r < 0) final_r = 0;
    Serial.print(" ");
    Serial.print(final_l);
    Serial.print(" ");
    Serial.println(final_r);

    wheel(final_l, final_r );
    if ((error - lastError) != 0) delay(5);
    lastError = error;
  }

}
