void setupLed(){
  // leds initialiseren met default
  for (size_t lednr = 0; lednr < LED_NR_ITEMS; lednr++) {
    
    ledsingle[lednr] = LED_DEFAULT[lednr];
    pinMode(ledsingle[lednr].pin, OUTPUT);
    ledcSetup(ledsingle[lednr].pwm_channel, PWM_FREQUENCY, PWM_RESOLUTION);  //eenmalig frequentie opzetten
    ledcAttachPin(ledsingle[lednr].pin, ledsingle[lednr].pwm_channel);       //pin aan pwm channel hangen
  }

  Println("Pins defined as output");
}