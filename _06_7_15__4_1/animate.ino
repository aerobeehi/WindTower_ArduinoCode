
void animate_D()
{
  int j, k;

  for (j = 0; j < A; j++)
  {
    strip.setPixelColor((M + j), Color.red, Color.blue, Color.green);
    strip.setPixelColor(((M - A) + j), OFF);
  }

  strip.show();
  strip.clear();
}


void animate_L()
{
  int j, k;

  for (j = 0; j < A; j++)
  {
    strip.setPixelColor((M + j), OFF);
    strip.setPixelColor(((M - A) + j), Color.red, Color.blue, Color.green);
  }

  strip.show();
  strip.clear();
}

