

void systemSetup()
{
  FastLED.addLeds<LED_TYPE,  DATA_PIN, CLOCK_PIN>(leds, NUMBER_PIXELS);
  
  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.

  anemoCounter = 0;
}

