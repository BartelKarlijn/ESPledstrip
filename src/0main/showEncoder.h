#pragma once
void showEncoder(unsigned long value) {
//  long newPosition = encoder.getCount() / 2;
  Print("Encoder: ");
  Println(value);
  ledsingle[0].bri = value;
}
