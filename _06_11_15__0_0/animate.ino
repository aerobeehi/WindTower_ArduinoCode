
void animate()
{
  int j, k;

  for (j = A; j > 0; j--)
  {
    strip_A.setPixelColor((M + j), Color.red, Color.green, Color.blue);
    strip_B.setPixelColor((M + j), Color.red, Color.green, Color.blue);
    strip_A.setPixelColor(((M - A) + j), OFF);
    strip_B.setPixelColor(((M - A) + j), OFF);
  }

  strip_A.show();
  strip_B.show();
  strip_A.clear();
  strip_B.clear();
}

