String on_getSingled(AsyncWebServerRequest *request){
    String ledString;
    int lednr;
    String veldString;
    int veldnr;
    String answertoSend;
    // get parameter string & veld  http://192.168.68.205/maintain_strip?string=1?veld=pin1
    if (request->hasParam("string")) {
      ledString = request->getParam("string")->value();
      lednr = ledString.toInt();
    }
    else {
      lednr = 99;
    }
    if (request->hasParam("veld")) {
      veldString = request->getParam("veld")->value();
      veldnr = veldString.toInt();

      switch (veldnr)
      {
      case 1:  //we beginnen bij 1, zodat 0 een fout geeft
        answertoSend = ledsingle[lednr].desc;
        break;
      case 2:
        answertoSend = ledsingle[lednr].pin1;
        break;
      case 3:
        answertoSend = ledsingle[lednr].pin2;
        break;
      case 4:
        answertoSend = ledsingle[lednr].pwm_channel;
        break;
      case 5:
        answertoSend = ledsingle[lednr].bri;
        break;
      case 6:
        answertoSend = ledsingle[lednr].timeon;
        break;
      case 7:
        answertoSend = ledsingle[lednr].timeoff;
        break;
      case 8:
        answertoSend = ledsingle[lednr].timeeffect;
        break;
      case 9:
        answertoSend = ledsingle[lednr].effect;
        break;
      case 10:
        answertoSend = ledsingle[lednr].image;
        break;
      default:
        answertoSend = "error";
        break;
      }
    }
    else {
      answertoSend = "error";
    }
    return answertoSend;
}