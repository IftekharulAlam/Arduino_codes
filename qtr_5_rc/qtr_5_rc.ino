5RC has a 5-channel infrared probe. Unlike the traditional infrared tracking sensor, it is necessary to give a corresponding high-level pulse to a corresponding channel before using it. Set the pin to the input mode, start the timer inside the microcontroller, and calculate the time of the high level. Next, the sensor will be used to make an intelligent tracing robot.
Technical Parameters: 
Working voltage: 3.3V-5V
Working current: less than 70mA
Sensing distance: 7mm (max); 4mm (best)
Dimensions: 6.9*1.2cm
   Before use, please fix the sensor to the front lower position of the trolley. The position of the ground is 3-5MM. It should be avoided in the strong light environment when using it. It may generate interference signals. The probe reflects the objects of different colors. The intensity is different, the most sensitive to white, and no reflection on black, so it is very suitable for tracing cars. When wiring, pay attention to the positive and negative poles of the power supply, GND is connected to the negative pole of the power supply, VCC is connected to the positive pole of the power supply, and IN1-IN5 are the output terminals of the 5th sensor from left to right respectively, which are connected to the single-chip microcomputer to detect the tracking signal. The EN port is used to control the on/off of the 5-way sensor. When the high level, the sensor board works, the low level does not work. By default, the pull-up resistor is connected to the high level. The user can also use the IO port of the microcontroller to control it. 
   QTR-5RC library file:   QTRSensors.zip (15.2 KB, Downloads: 181) 
   Please download the above attachments and extract them to the "Libraries" folder in the Arduino installation directory for normal use. The library is from Pololu! Here are a few commonly used functions: 
* QTRSensorsRC qtrrc((unsigned char[]) {14, 15, 16, 17, 18}, NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
This function is used to set the connection IO port, the sensor used Quantity, sensor detection overflow time, EN pin interface, for example 14-18 corresponds to the A0-A4 pin of arduino, can also be detected using digital pin 2-13. 
* qtrrc.calibrate(); The 
sensor is initially checked for value and the sensor needs to be verified before use. During calibration, it must be ensured that the sensor can move completely from the left to the right. If the calibration link is wrong, it will affect the following usage. You can refer to the code given below, the program completes the calibration of the sensor by the positive and negative rotation of the motor. 
* qtrrc.readLine(sensorValues); 
Read the value of the sensor. This does not need to be explained. It should be noted that the sensorValues ​​here are arrays, not variables, and the array is used to store the detected values. 
The tracing code is as follows: 
[code=ObjC width=720px]#include <QTRSensors.h> 

// This example is designed for use with eight QTR-1RC sensors or the eight sensors of a
// QTR-8RC module.  These reflectance sensors should be connected to digital inputs 3 to 10.
// The QTR-8RC's emitter control pin (LEDON) can optionally be connected to digital pin 2, 
// or you can leave it disconnected and change the EMITTER_PIN #define below from 2 to 
// QTR_NO_EMITTER_PIN.

// The setup phase of this example calibrates the sensor for ten seconds and turns on
// the LED built in to the Arduino on pin 13 while calibration is going on.
// During this phase, you should expose each reflectance sensor to the lightest and 
// darkest readings they will encounter.
// For example, if you are making a line follower, you should slide the sensors across the
// line during the calibration phase so that each sensor can get a reading of how dark the
// line is and how light the ground is.  Improper calibration will result in poor readings.
// If you want to skip the calibration phase, you can get the raw sensor readings
// (pulse times from 0 to 2500 us) by calling qtrrc.read(sensorValues) instead of
// qtrrc.readLine(sensorValues).

// The main loop of the example reads the calibrated sensor values and uses them to
// estimate the position of a line.  You can test this by taping a piece of 3/4" black
// electrical tape to a piece of white paper and sliding the sensor across it.  It
// prints the sensor values to the serial monitor as numbers from 0 (maximum reflectance) 
// to 1000 (minimum reflectance) followed by the estimated location of the line as a number
// from 0 to 5000.  1000 means the line is directly under sensor 1, 2000 means directly
// under sensor 2, etc.  0 means the line is directly under sensor 0 or was last seen by
// sensor 0 before being lost.  5000 means the line is directly under sensor 5 or was
// last seen by sensor 5 before being lost.

#define NUM_SENSORS   5     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2

// sensors 1 through 5 are connected to analog pins a0 through a
QTRSensorsRC qtrrc((unsigned char[]) {14, 15, 16, 17, 18},  
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];//store the value of QTRSensor
int AIN1 = 6;  //DIRA1
int AIN2 = 5;  //DIRA2
int BIN1 = 10;  //DIRB1 
int BIN2 = 9;  //DIRB2
int melody[]={330,330,330,262,392,200,280};
int noteDurations[]={8,4,4,8,4,4,2};
void setup(){
  delay(500);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);    // turn on Arduino's LED to indicate we are in calibration mode
  for (int i = 0; i < 80; i++)  // make the calibration take about 10 seconds
  {
    qtrrc.calibrate();       // reads all sensors 10 times at 2500 us per read (i.e. ~25 ms per call)
    if(i<20||i>=60)
       setMotor(80,-80);
    else
       setMotor(-80,80);//            */
  }
  digitalWrite(13, LOW);     // turn off Arduino's LED to indicate we are through with calibration
  setMotor(0,0);
  delay(500);
  for(int thisNote = 0;thisNote < 7;thisNote ++){
    tone(12,melody[thisNote],1000/noteDurations[thisNote]);
    delay(1300/noteDurations[thisNote]);
    noTone(12);
  }
// delay(2000);
  // print the calibration minimum values measured when emitters were on
  Serial.begin(9600);
}
void setMotor(int MOTORA,int MOTORB)
{
  if(MOTORA>=0)
  {
    digitalWrite(AIN2,HIGH);
    analogWrite(AIN1,255-MOTORA);
  }
  else
  {
   digitalWrite(AIN1,HIGH);
    analogWrite(AIN2,MOTORA+255);
  }
  if(MOTORB>0)
  {
    digitalWrite(BIN2,HIGH);
    analogWrite(BIN1,255-MOTORB);
  }
  else
  {
    digitalWrite(BIN1,HIGH);
    analogWrite(BIN2,255+MOTORB); 
  }
}
void loop()
{
  // read calibrated sensor values and obtain a measure of the line position from 0 to 4000
  // To get raw sensor values, call:
  //  qtrrc.read(sensorValues); instead of unsigned int position = qtrrc.readLine(sensorValues);
  unsigned int last_proportional=0;
  long integral=0;
  unsigned int position =qtrrc.readLine(sensorValues);
  int proportional = ((int)position)-2000;
  int derivative = proportional-last_proportional;
  integral+=proportional;
  //setMotor(50,50);
  last_proportional = proportional;
  //int power_difference = proportional/12 ;// only P adjustment  
  int power_difference = proportional/15+integral/3000 + derivative*3/400;
  const int maxcount = 110;
  if(power_difference > maxcount)
        power_difference = maxcount;
  if(power_difference < -maxcount)
        power_difference = -maxcount;

  if(power_difference < 0)
       setMotor(maxcount+power_difference,maxcount);
  else
       setMotor(maxcount, maxcount-power_difference);
  // print the sensor values as numbers from 0 to 1000, where 0 means maximum reflectance and
  // 1000 means minimum reflectance, followed by the line position*/
/*  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues);
    Serial.print('\t');
  }
  //Serial.println(); // uncomment this line if you are using raw values 
  Serial.println(position); // comment this line out if you are using raw values*/ 
// delay(250); 
}[/ Code] The 
above code contains the code of the motor drive part. Because the slow decay mode (with brake function) driven by the DRV8833 motor is used, the motor drive part is written differently. If you use L298N, you can change it to the following: 
[code=ObjC width=720px]void setMotor(int MOTORA, int MOTORB) 
{ 
  if(MOTORA>=0) 
  { 
    digitalWrite(AIN2,LOW); 
    analogWrite (the AIN1, MOTORA); 
  } 
  the else 
  { 
   digitalWrite (the AIN1, HIGH); 
    to analogWrite (AIN2, -MOTORA); 
  } 
  IF (MOTORB> 0) 
  { 
    digitalWrite (a BIN2, the LOW); 
    to analogWrite (BINl, MOTORB); 
  }
  else
  {
    digitalWrite(BIN1,LOW);
    analogWrite(BIN2,-MOTORB); 
  }
}[/code]

