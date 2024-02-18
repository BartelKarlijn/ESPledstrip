String on_getfileLoad2Singled(AsyncWebServerRequest *request){
    String ledString;
    int lednr;
    // get parameter string & veld  http://192.168.68.205/getfileLoad2Kring?string=1
    if (request->hasParam("string")) {
      ledString = request->getParam("string")->value();
      lednr = ledString.toInt();
    }
    else {
      lednr = 99;
    }
    return fileLoad2Single(lednr);
}