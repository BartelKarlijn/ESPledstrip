#pragma once
String  fileLoad2Single(int lednr) {
// Load ledSingle settings from file
  char filename[18];
  String msgAnswer;

  sprintf(filename, "/cfg_string%02d.ini", lednr);

  Print(String(filename));

  if (!SPIFFS.exists(filename)) {
    Println(" does not exist");
    msgAnswer = "File does not exist";
  }
  else {
    String file_content = readFile(SPIFFS, filename);
    int config_file_size = file_content.length();
    Println(" size: " + String(config_file_size));

    if(config_file_size > 1024) {
      Println(" too large");
      msgAnswer ="Config file too large";
    }

    JsonDocument doc;
    auto error = deserializeJson(doc, file_content);
    if ( error ) { 
      Println("Error interpreting config file");
      msgAnswer ="Error interpreting config file";
    }

    // get variables from JSON file
    const str_ledsingle _ledsingle = {
      doc["desc"],
      doc["pin1"],
      doc["pin2"],
      doc["pwm_channel"],
      doc["bri"],
      doc["timeon"],
      doc["timeoff"],
      doc["timeeffect"],
      doc["effect"],
      doc["image"]
    };

    ledsingle[lednr]     = _ledsingle;
   
    msgAnswer = ("Data opgehaald voor " + ledsingle[lednr].desc);
    Print("  Desc: " + _ledsingle.desc + ", img: " + _ledsingle.image + ", eff: " + String(_ledsingle.effect)); delay(10);
  }
  return msgAnswer;
}
