void increment()
{
  if (M > (_NUMPIXELS - A))
  {
    if (--t < 5)
    {
      startIndex = map(t, 5, 95, 0, 245);
      getPaletteColor(startIndex);
      
      M = -A;
    }
    else
    {
      t = 95;
    }
  }
  else
  {
    animate();
    strip.show();
    M += A;
  }
  
  Serial.println(M);
}



void systemSetup()
{
  Serial.end();
  Serial.begin(BAUDRATE);

  dht.begin();

  strip.begin();
  strip.clear();
  strip.show();

  attachInterrupt(0, anemo, RISING);

  anemo_counter = 0;

  currentPalette = Colors_p;

}

