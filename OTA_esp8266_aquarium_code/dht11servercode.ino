void getTempHumidityData() {

  h = dht.readHumidity();

  t =  dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    // Serial.println(F("Failed to read from DHT sensor!"));
    //return;
  }


}
