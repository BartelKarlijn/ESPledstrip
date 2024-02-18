String on_getfileDefault2Singled(AsyncWebServerRequest *request){
    String ledString;
    int lednr;
    // get parameter Singled & veld  http://192.168.68.205/getfileLoad2Singled?string=1
    if (request->hasParam("string")) {
      ledString = request->getParam("string")->value();
      lednr = ledString.toInt();
    }
    else {
      lednr = 99;
    }
    return fileDefault2Single(lednr);
}