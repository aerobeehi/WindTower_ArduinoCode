

void systemSetup()
{
  // Establish serial communications. 
  Serial.end();
  Serial.begin(BAUD_RATE);

  dht.begin();

  FastLED.addLeds<DOTSTAR,  DATA_PIN_A, CLOCK_PIN_A>(leds, NUMBER_PIXELS);
  FastLED.addLeds<DOTSTAR,  DATA_PIN_B, CLOCK_PIN_B>(leds, NUMBER_PIXELS);

  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.

  anemoCounter = 0;

  currentPalette = temperaturePalette;
}

