/*
Exercise Monster Motor Shield
Uses Serial Monitor window to issue commands for controlling the DC motors 
connected to the shield
S = Stop
F = Forward
R = Reverse
C = Returns the current reading of the motors
Pxxx (P0 - P255) sets the PWM speed value
P? = Returns the current PWM value
*/
const int MOTOR_1 = 0;
const int MOTOR_2 = 1;
const int BRAKE = 0;
const int CW = 1;
const int CCW = 2;
const int CS_THRESHOLD = 15;
/*
Note:  the pin definitions below are set by the shield pinout. If using
the board as a shield, these pins must remain as specified below.
If wiring the board rather than using as a shield, these can be changed. */
const int MOTOR_A1_PIN = 7; //Motor 1 control inputs
const int MOTOR_A2_PIN = 4;
const int MOTOR_B1_PIN = 8; // Motor 2 control inputs
const int MOTOR_B2_PIN = 9;

const int PWM_MOTOR_1 = 5;
const int PWM_MOTOR_2 = 6;
const int CURRENT_SENSE_1 = A2;
const int CURRENT_SENSE_2 = A3;
const int EN_PIN_1 = A0;
const int EN_PIN_2 = A1;

int motor_Speed = 150;  //default motor speed
int motor_State = BRAKE;
int mot1_current = 0;
int mot2_current = 0;

char readString[4];  // String array to hold PWM value typed in on keyboard
//===============================================================================
//  Initialization
//===============================================================================
void setup() {
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);
  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);
  //pinMode(EN_PIN_1, OUTPUT);      // Uncomment these 4 lines to use the Enable pins
  //pinMode(EN_PIN_2, OUTPUT);      // to enable/disable the device.  
                                    // To monitor for fault conditions instead, they 
                                    // would be defined as inputs
 // digitalWrite(EN_PIN_1, HIGH);  // Set EN pins high to enable drivers
 // digitalWrite(EN_PIN_2, HIGH); 
  
  Serial.begin(9600);           // Initialize serial monitor
  Serial.println("Enter command:");    // Printout commands
  Serial.println("S = STOP");
  Serial.println("F = FORWARD");
  Serial.println("R = REVERSE");
  Serial.println("C = READ MOTOR CURRENT");
  Serial.println("Pxxx = PWM SPEED (P000 - P254)");
  Serial.println("P? = RETURNS CURRENT PWM SPEED");
}
//===============================================================================
//  Main
//===============================================================================
void loop() {
// Just loop while monitoring the serial port and then jump to DoSerial to
// handle incoming characters and act on them
if (Serial.available()) DoSerial();
}
//===============================================================================
//  Subroutine to handle characters typed via Serial Monitor Window
//===============================================================================
void DoSerial()
{
  int index = 0;
  int pwm_Value = 0;
  int mot1_ADC = 0;
  int mot2_ADC = 0;
  float mot1_voltage = 0.0;
  float mot2_voltage = 0.0;
  
  char ch = Serial.read();  // Read the character we know we have
  Serial.println(ch);       // Echo character typed to show we got it

  // Use Switch/Case statement to handle the different commands
  switch (ch) {
  case 'f':   // Motor FORWARD command
  case 'F':   // This fall-through case statement accepts upper and lower case
    motor_State = CW;
    Motor_Cmd(MOTOR_1, motor_State, motor_Speed);
    Motor_Cmd(MOTOR_2, motor_State, motor_Speed);
    Serial.println("Motors Forward");
    break;

  case 'r':   // Motor REVERSE command
  case 'R':
    motor_State = CCW;
    Motor_Cmd(MOTOR_1, motor_State, motor_Speed);
    Motor_Cmd(MOTOR_2, motor_State, motor_Speed);
    Serial.println("Motors Reverse");
    break;

   case 's':   // Motor STOP command
   case 'S':
    motor_State = BRAKE;
    Motor_Cmd(MOTOR_1, motor_State, 0);
    Motor_Cmd(MOTOR_2, motor_State, 0);
    Serial.println("Motors Stop");
    break;
      
   case 'c':   // Motor Current command
   case 'C':
    mot1_ADC = analogRead(CURRENT_SENSE_1);
    mot2_ADC = analogRead(CURRENT_SENSE_2);
    mot1_voltage = mot1_ADC * (5.0 / 1024);
    mot2_voltage = mot2_ADC * (5.0 / 1024);
    Serial.print("Motor 1 Current: ");
    Serial.print (mot1_voltage * 26*100);
    Serial.println (" mA");
    Serial.print("Motor 2 Current: ");
    Serial.print (mot2_voltage * 26*100);
    Serial.println (" mA");
    break;

  case 'p':  // Motor SPEED command
  case 'P':
    // This command is a little trickier.  We are looking for a number from 0-255
    // to follow this command so we can set the PWM speed.  If we see a '?'
    // we will report our current speed setting, otherwise we start collecting chars
    // into the readString array.
    delay(2);  // Give time for more characters to arrive.
    for (int i; i<4; i++) readString[i] = ' ';  // Clear string array
    while (Serial.available())  // Read what we get and put into the string array
    {
      char c = Serial.read();
      readString[index] = c;
      index++;
      delay(2);
    }
    readString[3] = ""; // Append null to end of string array to make it a valid string
    index = 0;            // Reset our index back to the start of the string
    if (readString[index] == '?')   // ? means report our current speed setting and exit.
    {
      Serial.print("Current PWM Setting: ");
      Serial.println(motor_Speed);
      break;
    }
    pwm_Value = atoi(readString);  // Try to convert string into integer
    // We assume a 0 value is because of a non-valid input and ignore the command
    if(pwm_Value!=0) {   
      if (pwm_Value > 255) pwm_Value = 255;     // Cap WPM setting at 255
      Serial.println(pwm_Value);        // Echo what we end up with to confirm we got it
      motor_Speed = pwm_Value;
      Motor_Cmd(MOTOR_1, motor_State, motor_Speed);
      Motor_Cmd(MOTOR_2, motor_State, motor_Speed);  
    }
    break;
  
  default:
    break;
  }
}
void Motor_Cmd(int motor, int direct, int pwm)     //Function that writes to the motors
{
  if(motor == MOTOR_1)
  {
    if(direct == CW)    {
      digitalWrite(MOTOR_A1_PIN, LOW); 
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }
    else if(direct == CCW)    {
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);      
    }
    else    {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);            
    }
    analogWrite(PWM_MOTOR_1, pwm); 
  }
  else if(motor == MOTOR_2)
  {
    if(direct == CW)    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, HIGH);
    }
    else if(direct == CCW)    {
      digitalWrite(MOTOR_A2_PIN, HIGH);
      digitalWrite(MOTOR_B2_PIN, LOW);      
    }
    else    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, LOW);            
    } 
    analogWrite(PWM_MOTOR_2, pwm);
  }
}
