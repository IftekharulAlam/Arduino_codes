void aquariumLightsInitCode() {
  pinMode(mainLight, OUTPUT);
  pinMode(algieLight, OUTPUT);
  pinMode(foodservo, OUTPUT);


  digitalWrite(mainLight, HIGH);
  digitalWrite(algieLight, HIGH);
  digitalWrite(foodservo, LOW);

}
void aquariumLightsCode() {
  timeClient.update();
  int hour = timeClient.getHours();
  int minute = timeClient.getMinutes();
  int second = timeClient.getSeconds();
  if (hour == 11 || hour == 12 || hour == 13 || hour == 14 || hour == 15 || hour == 16 || hour == 17 || hour == 18 || hour == 19 || hour == 20 || hour == 21 || hour == 22 ) {
    if (minute == 1) {
      if (second == 1) {
        digitalWrite(foodservo, HIGH);
        delay(10);
      }
      else {
        digitalWrite(foodservo, LOW);

      }

    }
    else {
      digitalWrite(foodservo, LOW);
    }
  }

  else {
    digitalWrite(foodservo, LOW);
  }


  if (hour >= 1 && hour <= 11) {
    digitalWrite(mainLight, HIGH);

  }
  if (hour >= 11 ) {
    digitalWrite(mainLight, LOW);

  }
  if (hour >= 11 && hour <= 15) {
    digitalWrite(algieLight, LOW);

  }
  else {
    digitalWrite(algieLight, HIGH);

  }

}
