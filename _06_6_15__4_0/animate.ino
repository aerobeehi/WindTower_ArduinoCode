
void animate()
{
  int j, k;

  for (j = 0; j < A; j++)
  {
    strip.setPixelColor((M + j), ON);
    strip.setPixelColor(((M - A) + j), 0);
  }

  strip.show();
  strip.clear();
}

