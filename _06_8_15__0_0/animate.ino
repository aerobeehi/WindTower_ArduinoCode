
void animate()
{
  int j, k;

  for (j = 0; j < A; j++)
  {
    strip.setPixelColor(((_NUMPIXELS - M) + j), Color.red, Color.blue, Color.green);
    strip.setPixelColor((M + j), OFF);
    strip.setPixelColor(((M - A) + j), Color.red, Color.blue, Color.green);
    strip.show();
  }
}



