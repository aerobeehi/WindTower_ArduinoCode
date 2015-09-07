

void systemSetup()
{
  Serial.end();
  Serial.begin(BAUD_RATE);

  FastLED.addLeds<DOTSTAR,  DATA_PIN_A, CLOCK_PIN_A>(leds, NUMBER_PIXELS);
  FastLED.addLeds<DOTSTAR,  DATA_PIN_B, CLOCK_PIN_B>(leds, NUMBER_PIXELS);

  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.
}

