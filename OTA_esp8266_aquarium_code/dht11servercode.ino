void getTempHumidityData() {

  h = dht.readHumidity();

  t =  dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    // Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
//    if (WiFi.status() == WL_CONNECTED) {
//      WiFiClient client;
//      HTTPClient http;
//      String serverPath = serverName + "?temperature=" + t + "&" + "humidity=" + h;
//  
//  
//      http.begin(client, serverPath.c_str());
//  
//  
//      int httpResponseCode = http.GET();
//  
//      if (httpResponseCode > 0) {
//        //Serial.print("HTTP Response code: ");
//        //  Serial.println(httpResponseCode);
//        String payload = http.getString();
//        // Serial.println(payload);
//      }
//      else {
//        //      Serial.print("Error code: ");
//        //      Serial.println(httpResponseCode);
//      }
//      // Free resources
//      http.end();
//    }
//    else {
//      //  Serial.println("WiFi Disconnected");
//    }

}
