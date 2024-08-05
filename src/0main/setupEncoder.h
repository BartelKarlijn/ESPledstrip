void setupEncoder(){
  // This tells the library that the encoder has its own pull-up resistors
  rotaryEncoder.setEncoderType( EncoderType::FLOATING );

  // Range of values to be returned by the encoder: minimum is 1, maximum is 10
  // The third argument specifies whether turning past the minimum/maximum will
  // wrap around to the other side:
  //  - true  = turn past 10, wrap to 1; turn past 1, wrap to 10
  //  - false = turn past 10, stay on 10; turn past 1, stay on 1
  rotaryEncoder.setBoundaries( 0, 255, false );
  rotaryEncoder.setStepValue(ENCODER_STEPS);
  rotaryEncoder.setEncoderValue(ledsingle[0].bri );

  // The function specified here will be called every time the knob is turned
  // and the current value will be passed to it
  rotaryEncoder.onTurned( &showEncoder );

  // The function specified here will be called every time the button is pushed and
  // the duration (in milliseconds) that the button was down will be passed to it
  rotaryEncoder.onPressed( &showButton );

  // This is where the inputs are configured and the interrupts get attached
  rotaryEncoder.begin();

  Println("Encoder setup finished");
}