// This function increments the index of the 

void increment()
{
  if (M > (NUMPIXELS - 1))
  {
    t_f = dht.readTemperature(true);
    t = t_f;
    paletteIndex = map(t, 0, 110, 0, 255);
    getPaletteColor(paletteIndex);

    Serial.println(t);
    Serial.println(paletteIndex);

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

  strip.begin();
//  strip_B.begin();
  strip.clear();
 // strip_B.clear();
  strip.show();
 // strip_B.show();

  attachInterrupt(0, anemo, RISING);

  anemo_counter = 0;

  Palette = Colors_p;
}

