int ENA = 6;
int INA = 7;
int INB = 8;
int INC = 4;
int IND = 9;
int ENB = 5;

char incomingByte; // for incoming serial data
int speed_min = 135; //the minimum "speed" the motors will turn - take it lower and motors don't turn
int speed_max = 180; //

int speed_left = speed_max; // set both motors to maximum speed
int speed_right = speed_max;

void left();
void right();
void forward();
void backward();
void forward_left();
void forward_right();
void back_left();
void back_right();
void setup() {
  Serial.begin(38400);
  //Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(INC, OUTPUT);
  pinMode(IND, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
}

void loop() {

  if (Serial.available() > 0) {
    incomingByte = Serial.read();
  }
  switch (incomingByte)
  {
    case 'S':
      {
        stopo();
        //Serial.println("Stop\n");
        incomingByte = '*';
      }
      break;

    case 'F':

      { forward();

        // Serial.println("Forward\n");
        incomingByte = '*';
      }
      break;

    case 'B':

      { backward();
        // Serial.println("Backward\n");
        incomingByte = '*';
      }
      break;

    case 'R':
      // turn right
      {
        right();
        // Serial.println("Rotate Right\n");
        incomingByte = '*';
      }
      break;
    case 'L':
      {
        left();
        //Serial.println("Rotate Left\n");
        incomingByte = '*';
      }
      break;
    case '1':

      { speed_left = 20;
        speed_right = 20;
        //Serial.println("Speed 1\n");
        incomingByte = '*';
      }
      break;
    case '2':
      {
        speed_left = 40;
        speed_right = 40;
        //Serial.println("Speed 2 \n");
        incomingByte = '*';
      }
      break;
    case '3':
      {
        speed_left = 80;
        speed_right = 80;
        //Serial.println("Speed 3 \n");
        incomingByte = '*';
      }
      break;
    case '4':
      {
        speed_left = 100;
        speed_right = 100;
        //Serial.println("Speed 4 \n");
        incomingByte = '*';
      }
      break;
    case '5':
      {
        speed_left = 120;
        speed_right = 120;
        //Serial.println("Speed 5 \n");
        incomingByte = '*';
      }
      break;
    case '6':
      {
        speed_left = 140;
        speed_right = 140;
        //Serial.println("Speed 6 \n");
        incomingByte = '*';
      }
      break;
    case '7':
      {
        speed_left = 180;
        speed_right = 180;
        // Serial.println("Speed 7 \n");
        incomingByte = '*';
      }
      break;
    case '8':
      {
        speed_left = 200;
        speed_right = 200;
        //Serial.println("Speed 8 \n");
        incomingByte = '*';
      }
      break;
    case '9':
      {
        speed_left = 220;
        speed_right = 220;
        //Serial.println("Speed 9 \n");
        incomingByte = '*';
      }
      break;
    case 'q':
      {
        speed_left = 255;
        speed_right = 255;
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;
    case 'I':
      {
        forward_left();
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;
    case 'G':
      {
        forward_right();
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;
    case 'H':
      {
        back_left();
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;
    case 'J':
      {
        back_right();
        Serial.println("Speed full \n");
        incomingByte = '*';
      }
      break;
  }


}
void left() {
  analogWrite(ENA, speed_left);
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  digitalWrite(INC, HIGH);
  digitalWrite(IND, LOW);
  analogWrite(ENB, speed_right);

};
void right() {
  analogWrite(ENA, speed_left);
  digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  digitalWrite(INC, LOW);
  digitalWrite(IND, HIGH);
  analogWrite(ENB, speed_right);
};
void forward() {
  analogWrite(ENA, speed_left);
  digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  digitalWrite(INC, HIGH);
  digitalWrite(IND, LOW);
  analogWrite(ENB, speed_right);
};
void backward() {
  analogWrite(ENA, speed_left);
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  digitalWrite(INC, LOW);
  digitalWrite(IND, HIGH);
  analogWrite(ENB, speed_right);

};
void stopo() {
  analogWrite(ENA, speed_left);
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  digitalWrite(INC, LOW);
  digitalWrite(IND, LOW);
  analogWrite(ENB, speed_right);

};
void forward_left() {
  analogWrite(ENA, speed_left);
  digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  digitalWrite(INC, LOW);
  digitalWrite(IND, LOW);
  analogWrite(ENB, speed_right);

};
void forward_right() {
  analogWrite(ENA, speed_left);
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  digitalWrite(INC, HIGH);
  digitalWrite(IND, LOW);
  analogWrite(ENB, speed_right);
};
void back_left() {
  analogWrite(ENA, speed_left);
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  digitalWrite(INC, LOW);
  digitalWrite(IND, HIGH);
  analogWrite(ENB, speed_right);

};
void back_right() {
  analogWrite(ENA, speed_left);
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  digitalWrite(INC, LOW);
  digitalWrite(IND, LOW);
  analogWrite(ENB, speed_right);
};
