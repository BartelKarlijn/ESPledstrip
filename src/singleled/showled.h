#pragma once

void showled() {
  for (size_t i = 0; i < LED_NR_ITEMS; i++) {
    switch (ledsingle[i].effect)
    {
    case EFFLED_UIT:
        led_uit(i);
        break;
    case EFFLED_AAN:
        led_aan(i);
        break;
    case EFFLED_GLOW:
        led_glow(i);
        break;
    case EFFLED_RAMP:
        led_ramp(i);
        break;
    case EFFLED_RAND:
        led_rand(i);
        break;
    default:
        break;
    }
  }
}