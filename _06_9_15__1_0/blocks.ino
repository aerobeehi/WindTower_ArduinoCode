void increment()
{
  if (M > (_NUMPIXELS - 1 ))
  {
    t_f = dht.readTemperature(true);
    t = t_f;
    startIndex = map(t, 0, 110, 0, 255);
    getPaletteColor(startIndex);

    Serial.println(t);
    Serial.println(startIndex);

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

