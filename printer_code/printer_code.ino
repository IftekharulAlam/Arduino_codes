#define stepsPerRevolution 500
#define EN_plus 13
#define CW_plus 3
#define CLK_plus 5
char incomingByte;
void ForwardMotor(int stepPin, int dirPin);
void ReverseMotor(int stepPin, int dirPin);
void stopMotor(int Enable_pin);
void setup() {
  Serial.begin(9600);
  pinMode(EN_plus, OUTPUT);
  pinMode(CW_plus, OUTPUT);
  pinMode(CLK_plus, OUTPUT);


}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    //Serial.println(incomingByte);
  }
  switch (incomingByte)
  {
    case 'S':
      {
        stopMotor(EN_plus);
        //Serial.println("Stop\n");
        incomingByte = '*';
      }
      break;

    case 'F':

      { ForwardMotor(CLK_plus, CW_plus, EN_plus);

        // Serial.println("Forward\n");
        incomingByte = '*';
      }
      break;

    case 'B':

      { ReverseMotor(CLK_plus, CW_plus, EN_plus);

        // Serial.println("Backward\n");
        incomingByte = '*';
      }
      break;
  }


}
void ForwardMotor(int stepPin, int dirPin, int Enable_pin) {
  digitalWrite(Enable_pin, LOW);
  digitalWrite(dirPin, LOW);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
};
void ReverseMotor(int stepPin, int dirPin, int Enable_pin) {
  digitalWrite(Enable_pin, LOW);
  digitalWrite(dirPin, HIGH);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
};
void stopMotor(int Enable_pin) {
  digitalWrite(Enable_pin, HIGH);

};
