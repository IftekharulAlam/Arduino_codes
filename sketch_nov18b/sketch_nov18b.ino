#define in1 D1
#define in2 D2
#define in3 D3
#define in4 D4

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void loop(){
  right_forward(255);
//  delay(3000);

 // right_back(255);
 // delay(3000);
  
 // left_forward(255);
 // delay(3000);
  //left_Back(255);
  //delay(3000);
   
}

void right_forward(int pwm)
{
  analogWrite(in1, 0);
  analogWrite(in2, pwm);
}
void right_back(int pwm)
{
  analogWrite(in1, pwm);
  analogWrite(in2, 0);
  
}
void left_forward(int pwm)
{
  analogWrite(in3, 0);
  analogWrite(in4, pwm);
}
void left_Back(int pwm)
{
  analogWrite(in3, pwm);
  analogWrite(in4, 0);
}
