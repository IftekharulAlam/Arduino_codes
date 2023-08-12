#define inA 8
#define inB 9
#define inC 10
#define inD 11


//sensor analog value should be taken before placing it to th[] array
int uturn = 150;
int th[6] = {730, 744, 722, 701, 642, 695}; //for pena track
int sen_pins[6] = {A0, A1, A2, A3, A4, A5};
void wheel(int lm, int rm);
int i, sen[6], s[6], lastSensor, lastError;
int base_L = 100;
int base_R = 100;
float kp = 5;
float kd = 50;
float ki = 0;
int incomingByte;

void setup()
{
  Serial1.begin(115200);

  mot_init();
  other_init();

}
void loop()
{
  if (Serial1.available() > 0) {
    // read the incoming byte:
    wheel(0, 0);
    delay(1000);
    kp = Serial1.parseInt();
    kd = Serial1.parseInt();
    ki = Serial1.parseInt();
    wheel(0, 0);
    delay(1000);
  }
  Serial1.print(kp);
  Serial1.print(" ");
  Serial1.print(kd);
  Serial1.print(" ");
  Serial1.print(ki);
  Serial1.println(" ");


  line_follow();


  // wheel(100, 100);
}
void other_init()
{
  lastSensor = 0;
  lastError = 0;
  //Serial1.begin(9600);
}


void mot_init()
{
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);


  //  analogWrite(inA, 0);
  //  analogWrite(inB, 0);
  //  analogWrite(inC, 0);
  //  analogWrite(inD, 0);

}

void wheel(int lm, int rm)
{
  if (lm == 0)
  {
    analogWrite(inC, 0);
    analogWrite(inD, 0);
  }
  if (lm > 0)
  {
    analogWrite(inC, lm);
    analogWrite(inD, 0);
  }
  else if (lm < 0)
  {
    analogWrite(inC, 0);
    analogWrite(inD, lm);
  }


  if (rm == 0)
  {
    analogWrite(inA, 0);
    analogWrite(inB, 0);
  }
  if (rm > 0)
  {
    analogWrite(inA, 0);
    analogWrite(inB, rm);
  }
  else if (rm < 0)
  {
    analogWrite(inA, rm);
    analogWrite(inB, 0);
  }
  if (lm > 255) lm = 255;
  if (lm < -255) lm = -255;
  if (rm > 255) rm = 255;
  if (rm < -255) rm = -255;
}

int readSensor()
{
  for (i = 0; i < 6; i++)
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
  s[0] = 1 - s[0];
  s[1] = 1 - s[1];
  s[2] = 1 - s[2];
  s[3] = 1 - s[3];
  s[4] = 1 - s[4];
  s[5] = 1 - s[5];


  int error, sum;
  sum = s[0] + s[1] + s[2] + s[3] + s[4] + s[5];

  if (sum != 0)
  {
    error = (s[0] * 10 + s[1] * 20 + s[2] * 30 + s[3] * 40 + s[4] * 50 + s[5] * 60) / sum - 35;
  }
  else
  {
    error = 420;
  }

  if (s[0] == 1) lastSensor = 1;
  else if (s[5] == 1) lastSensor = 2;
  //else if (s[4] == 1) lastSensor = 3;
  //  Serial1.print(0);
  //  Serial1.print(" ");
  //  Serial1.print(error);
  //  Serial1.print(" ");
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
    //Serial1.println(corr);
    final_l = base_L + corr;
    final_r = base_R - corr;
    if (final_l < 0)final_l = 0;
    if (final_r < 0) final_r = 0;


    wheel(final_l, final_r );
    if ((error - lastError) != 0) delay(5);
    lastError = error;
  }

}
