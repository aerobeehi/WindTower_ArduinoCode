
void animate()
{
  for (int j = 0; j <= PATTERN_LENGTH; j++)
  {
    leds[patternIndex + j] = ColorFromPalette(currentPalette, paletteIndex, 50, BLEND);
    leds[patternIndex + PATTERN_LENGTH + j] = CRGB::Black;
  }
  FastLED.show();
}



void increment()
{
  if (patternIndex <= 0)
  {
    patternIndex = NUMBER_PIXELS + PATTERN_LENGTH;
    FastLED.clear();
  }
  else
  {
    patternIndex -= PATTERN_LENGTH;
    animate();
  }
}


