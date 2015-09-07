
void animate()
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

