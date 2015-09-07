void increment()
{
  if (M > (_NUMPIXELS - 1 ))
  {
    t_f = dht.readTemperature(true);
    t = t_f;
    startIndex = map(t, 5, 95, 0, 255);
    getPaletteColor((255 - startIndex));

    M = -A;
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

  strip.begin();
  strip.clear();
  strip.show();

  attachInterrupt(0, anemo, RISING);

  anemo_counter = 0;

  currentPalette = Colors_p;

}

