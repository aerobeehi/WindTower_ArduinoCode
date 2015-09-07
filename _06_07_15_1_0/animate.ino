void animate_B()
{
 
  int i, j, k;

  strip.clear();

  for ( i = 0; i < NUMPIXELS; i += B)
  {
    for (j = 0; j < B; j++)
    {
      strip.setPixelColor((i + j + 1), 0);
      strip.setPixelColor((i + j), ColorFromPalette(OR_Palette, index, 255, BLEND));
      strip.setPixelColor(((i - B) + j), 0);
    }

    strip.show();
    delay(D);

    index++;
  }
}





