void increment()
{
  if (M > (_NUMPIXELS - 1 ))
  {
    if (--t < 5)
    {
      startIndex = map(t, 5, 95, 0, 255);
      getPaletteColor(startIndex);

      M = -A;
      refresh();
    }
    else
    {
      t = 95;
    }
  }
  else
  {
    refresh();
  }
}



void refresh()
{
  M += A;
  animate_L();
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

  fillAll();
}


void fillAll()
{
  int j, k;

  for (j = 0; j < _NUMPIXELS; j++)
  {
    strip.setPixelColor(((M - A) + j), ON);
  }

  strip.show();
  strip.clear();
}

