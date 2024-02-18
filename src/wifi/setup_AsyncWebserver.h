void setup_AsyncWebserver(){
  // Voordat we de webserver starten, moet je OTA opstarten, hier zonder user/pw
  ElegantOTA.begin(&webserver);
  // ElegantOTA callbacks
  ElegantOTA.onStart(onOTAStart);
  ElegantOTA.onProgress(onOTAProgress);
  ElegantOTA.onEnd(onOTAEnd);
  
  // Analoog gaan we de WebSerial opstarten, zodat je kan zien wat er gebeurt
  WebSerial.begin(&webserver);

  // if url isn't found
  webserver.onNotFound([](AsyncWebServerRequest *request) {
    Println("Wifi page not found");
    //Println(String(request));
    request->send(404, "text/plain", "Not found");
  });
  // run handleUpload function when any file is uploaded
  webserver.onFileUpload(on_fileUpload);

  // Route for root / web page (controller)
  webserver.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Root requested");
    request->send(SPIFFS, "/page_root.html", "text/html");
  });
  // static files
  webserver.on("/file_favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/file_favicon.ico", "image/png");
  });
  webserver.on("/file_img_1.png", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/file_img_1.png", "image/png");
  });
  webserver.on("/file_img_2.png", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/file_img_2.png", "image/png");
  });
  webserver.on("/file_img_3.png", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/file_img_3.png", "image/png");
  });
  webserver.on("/file_img_4.png", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/file_img_4.png", "image/png");
  });
  webserver.on("/file_img_5.png", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/file_img_5.png", "image/png");
  });
  webserver.on("/file_jquery-3.7.0.min.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/file_jquery-3.7.0.min.js", "text/javascript");
  });
  webserver.on("/file_style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("/stylesheet opgevraagd");
    request->send(SPIFFS, "/file_style.css", "text/css");
  });
  // dynamic actions
  webserver.on("/getfile", HTTP_GET, [](AsyncWebServerRequest * request){
    Println("file requested");
    on_file(request);
  });
  webserver.on("/getfileList", HTTP_GET, [](AsyncWebServerRequest * request){
    Println("fileList requested");
    request->send(200, "text/plain", listFiles(true));
  });
  webserver.on("/getfileStorage", HTTP_GET, [](AsyncWebServerRequest * request){
    Println("fileStorage requested");
    request->send(200, "text/plain", listStorage(true));
  });
  // webpages
  webserver.on("/page_fileManagement", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("FileManagement requested");
    request->send(SPIFFS, "/page_fileManagement.html", "text/html");
  });
  webserver.on("/page_huisje", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Huisje requested");
    request->send(SPIFFS, "/page_huisje.html", "text/html");
  });
  webserver.on("/page_maintainSingle", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("strip configuratie opgeroepen");
    request->send(SPIFFS, "/page_maintainSingle.html", "text/html");
  });
  webserver.on("/page_wificfg", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Wifi config pagina");
    request->send(SPIFFS, "/page_wificfg.html", "text/html");
  });
  webserver.on("/restart", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Restarting ESP32 in 2sec");
    request->send(200, "text/plain", "Restarting ESP32 in 2sec");
    delay(2000);
    ESP.restart();
  });
  webserver.on("/wifisave", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Wifi connection parameters");
    on_wifisave(request);
    request->send(SPIFFS, "/page_wificfg.html", "text/html");
  });

  // Start server
  webserver.begin();
}