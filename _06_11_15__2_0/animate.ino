
void animate()
{
  int j, k;

  for (j = 0; j < A; j++)
  {
    leds[M + j] = ColorFromPalette(currentPalette, paletteIndex, 255, BLEND);
    leds[(M - A) + j] = CRGB::Black;
  }

  FastLED.show();
}

