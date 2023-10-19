void wifiinit() {
  WiFi.mode(WIFI_STA);
  WiFi.hostname("AquariumESP32");
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    //Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

}
