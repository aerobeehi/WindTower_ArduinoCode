void animate()
{
  int i, j, k;

  strip.clear();

  for ( i = 0; i < NUMPIXELS; i += B)
  {
    for (j = 0; j < B; j++)
    {
      strip.setPixelColor((i + j + 1), 0);
      strip.setPixelColor((i + j), Color.red, Color.blue, Color.green);
      strip.setPixelColor(((i - B) + j), 0);
    }
   
    strip.show();
    delay(D);
  }
}





