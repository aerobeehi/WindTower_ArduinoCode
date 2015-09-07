
void animate()
{
  for (int j = 0; j <= patternLength; j++)
  {
    leds[patternIndex + j] = ColorFromPalette(currentPalette, paletteIndex, 50, BLEND);
    leds[(patternIndex + patternLength) + j] = CRGB::Black;
  }

  FastLED.show();
}


// This function increments the index of the

void increment()
{
  if (patternIndex <= -patternLength)
  {
    patternIndex = NUMBER_PIXELS; //  + patternLength;
  }
  else
  {
    patternIndex -= patternLength;
  }
}


