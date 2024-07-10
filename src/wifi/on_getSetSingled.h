String on_getSetSingled(AsyncWebServerRequest *request){
    String ledString;
    int lednr;
    String veldString;
    int veldnr;
    String answertoSend;
    String waardeString;
    bool doeVerder;
    // get parameter string & veld & waarde http://192.168.68.205/maintain_strip?string=1&veld=pin1&waarde=56
    if (request->hasParam("string")) {
      ledString = request->getParam("string")->value();
      lednr = ledString.toInt();
    }
    else {
      lednr = 255;
    }
    if (request->hasParam("veld")) {
      veldString = request->getParam("veld")->value();
      veldnr = veldString.toInt();
      doeVerder = true;
    }
    else {
      answertoSend += "Error: veld mist";
    }
    if (request->hasParam("waarde")) {
      waardeString = request->getParam("waarde")->value();
      doeVerder = true;
    }
    else {
      answertoSend += "Error: waardeparameter mist";
    }

    // verwerk de input
    if (doeVerder) {
      switch (veldnr)
      {
      case 1:  //we beginnen bij 1, zodat 0 een fout geeft
        ledsingle[lednr].desc     = waardeString;
        answertoSend = waardeString;
        break;
      case 2:
        ledsingle[lednr].pin1     = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 3:
        ledsingle[lednr].pin2     = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 4:
        ledsingle[lednr].pwm_channel = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 5:
        ledsingle[lednr].bri      = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 6:
        ledsingle[lednr].timeon   = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 7:
        ledsingle[lednr].timeoff  = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 8:
        ledsingle[lednr].timeeffect = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 9:
        ledsingle[lednr].effect   = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 10:
        ledsingle[lednr].image = waardeString;
        answertoSend = waardeString;
        break;
      default:
        answertoSend = "error";
        break;
      }
    }
    return answertoSend;
}