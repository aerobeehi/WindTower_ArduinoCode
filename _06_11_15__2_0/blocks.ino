// This function increments the index of the 

void increment()
{
  if (M >= (NUMPIXELS - 1))
  {
    M =-A;
    refresh();
  }
  else
  {
    refresh();
  }
}



void refresh()
{
  M += A;
  animate();

}



void systemSetup()
{
  Serial.end();
  Serial.begin(BAUDRATE);

  dht.begin();

  FastLED.addLeds<DOTSTAR,  DATAPIN_A, CLOCKPIN_A>(leds, NUMPIXELS);
  FastLED.addLeds<DOTSTAR,  DATAPIN_B, CLOCKPIN_B>(leds, NUMPIXELS);

  attachInterrupt(0, anemo, RISING);

  anemo_counter = 0;

  currentPalette = Colors_p;
}

