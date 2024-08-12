void setup_ConnectKnownWifi(){

  Serial.println();
  Serial.println("Disconnecting current wifi to connect again");
  delay(200);
//  WiFi.useStaticBuffers(true);
//  Serial.println("Buffers");
  WiFi.mode(WIFI_STA);    // connect to network
  delay(3000);
  Serial.println("wifi Station mode");
  WiFi.setHostname(HOST_NAME);
  delay(3000);
  WiFi.begin(wifi_ssid.c_str(), wifi_pwd.c_str());
  delay(5000);
  Serial.println("Begin wifi");

  // Dit houden we zo'n 10 sec vol, als het dan niet lukt AP opzetten.
  Serial.println("Connecting to wifi");
  delay(100);
  for (int i = 0; i < 10; i++) {
//    if ((WiFi.waitForConnectResult(1000) == WL_CONNECTED)) {
    if ((WiFi.status() != WL_CONNECTED)) {
      delay(1000);
      Serial.print(".");
    }
    else {
      delay(100);
      Serial.println(".!");
      Serial.print("Connected successfully to ");
      Serial.println(wifi_ssid);
      Serial.print("Local IP: ");
      Serial.println(WiFi.localIP());
      break;
    }
  }
  delay(1000);
  Serial.println(" ");
  Serial.println("Wifi search over");
}
