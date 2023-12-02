int sizeOFArray = 800;
int pinMyArr[5] = {A0, A1, A2, A3, A4};
int myarr[900];
int num, x, y, temp;

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  for (int i = 0; i < sizeOFArray; i++) {
    pinMode(pinMyArr[i], INPUT);

  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeOFArray ; i++) {
    myarr[i] = analogRead(A0);

  }
  for (int i = 0; i < sizeOFArray ; i++) {

    Serial.print(myarr[i]);
    Serial.print(",");

  }
  for (x = 0; x < sizeOFArray - 1; x++) {
    for (y = 0; y < sizeOFArray - x - 1; y++) {
      if (myarr[y] > myarr[y + 1]) {
        temp = myarr[y];
        myarr[y] = myarr[y + 1];
        myarr[y + 1] = temp;
      }
    }
  }
   Serial.print("-------");
  for (int i = 0; i < sizeOFArray ; i++) {

    Serial.print(myarr[i]);
    Serial.print(",");

  }
  Serial.println();

}
