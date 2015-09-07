
void animate()
{
  int j, k;

  for (j = A; j > 0; j--)
  {
    strip.setPixelColor((M + j), Color.red, Color.green, Color.blue);
 //   strip_B.setPixelColor((M + j), Color.red, Color.green, Color.blue);
    strip.setPixelColor(((M - A) + j), OFF);
 //   strip_B.setPixelColor(((M - A) + j), OFF);
  }

  strip.show();
 // strip_B.show();
  strip.clear();
 // strip_B.clear();
}

