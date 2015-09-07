
void animate_A()
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

void animate_B()
{
  int j, k;

  for (j = 0; j < A + 2; j++)
  {
    strip.setPixelColor((M + j), ON);
    strip.setPixelColor(((M - A) + j), 0);
  }

  strip.setPixelColor((M + 1), 0);
  strip.setPixelColor(M, 0);

  strip.show();
  strip.clear();
}
