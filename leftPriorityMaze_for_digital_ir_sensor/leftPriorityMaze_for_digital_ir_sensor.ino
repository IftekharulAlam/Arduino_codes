/*
Code Written by:
Abir Ahsan Akib
BUET ExCOM
*/     

#define inA 2
#define inB 3
#define inC 4
#define inD 7


const int irPins[5] = {A4,A3,A2,A1,A0};
int s[5] = {0,0,0,0,0}; 

void wheel(int rm, int lm);
int path[100];
int p;
int i,lastSensor,lastError;

int base_L=180;
int base_R=180;
float kp=15;
float kd=8;
void setup()
{
  mot_init();
  other_init();
}
void loop()
{
//  line_follow();
//wheel(100,100);
//maze_solve();
maze();
}
