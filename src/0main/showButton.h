#pragma once
void showButton(unsigned long value) {
//  long newPosition = encoder.getCount() / 2;
  if (value > BUTTON_DEBOUNCE ) {
    Print("Button press duration: ");
    Println(value);
    fileSaveSingle(0);
  }
}
