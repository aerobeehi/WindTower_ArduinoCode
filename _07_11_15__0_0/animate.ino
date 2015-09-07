
void animate()
{
  int j;

  for (j = 0; j <= patternLength; j++)
  {
    leds[patternIndex + j] = ColorFromPalette(currentPalette, paletteIndex, 50, BLEND);
    leds[(patternIndex + patternLength) + j] = CRGB::Black;

    Serial.print("index + j -> ");
    Serial.println(patternIndex + j);
    Serial.print("index + length + j -> ");
    Serial.println((patternIndex + patternLength) + j);
  }

  FastLED.show();
}


void bottom()
{
  for (int j = 0; j <= patternLength; j++)
  {
    leds[j] = CRGB::Black;
  }
}


// This function increments the index of the

void increment()
{
  if (patternIndex <= 0)
  {
    patternIndex = NUMBER_PIXELS + patternLength;
    FastLED.clear();
  }
  else
  {
    patternIndex -= patternLength;
    animate();
  }
  Serial.println("--------------------");
  Serial.print("index -> ");
  Serial.println(patternIndex);
  Serial.println("--------------------");
}


