void animate_B()
{
  int i;
  int j; 

  strip.clear();

  for ( i = 0; i < NUMPIXELS; i += B)
  {
    for (j = 0; j < B; j++)
    {
      strip.setPixelColor((i + j + 1), 0);
      strip.setPixelColor((i + j), ON);
      strip.setPixelColor(((i - B) + j), 0);
    }

    strip.setPixelColor(i + 1, 0);
    strip.setPixelColor(i, 0);

    strip.show();
    get_Delay();
  }
}

void animate_A()
{
  int i;
  int j;

  strip.clear();

  for ( i = 0; i < NUMPIXELS; i += A)
  {
    for (j = 0; j < A; j++)
    {
      strip.setPixelColor((i + j), ON);
      strip.setPixelColor(((i - A) + j), 0);
    }
    strip.show();
    get_Delay();
  }
}



