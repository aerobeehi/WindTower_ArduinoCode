// This function increments the index of the 

void increment()
{
  if (M < A)
  {
    t_f = dht.readTemperature(true);
    t = t_f;
    paletteIndex = map(t, 0, 110, 0, 255);
    getPaletteColor(paletteIndex);

    Serial.println(t);
    Serial.println(startIndex);

    M = _NUMPIXELS + A;
    refresh();
  }
  else
  {
    refresh();
  }
}



void refresh()
{
  M -= A;
  animate();
}



void systemSetup()
{
  Serial.end();
  Serial.begin(BAUDRATE);

  dht.begin();

  strip_A.begin();
  strip_B.begin();
  strip_A.clear();
  strip_B.clear();
  strip_A.show();
  strip_B.show();

  attachInterrupt(0, anemo, RISING);

  anemo_counter = 0;

  Palette = Colors_p;
}

