#pragma once
void loadAnimatie() {
  String msgReceive;  // variabele is enkel nodig omdat functie String teruggeeft
  // Eerst ini file lezen, en terugvallen op default als niet gelukt.
  for (size_t i = 0; i < LED_NR_ITEMS; i++) {
    if (fileLoad2Single(i) == "File does not exist") {
      Println("default voor " + String(i)); delay(5);
      msgReceive = fileDefault2Single(i);
    };
  }
}