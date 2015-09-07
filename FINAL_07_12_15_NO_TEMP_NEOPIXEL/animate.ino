
void animate()
{
  for (int j = 0; j <= PATTERN_LENGTH; j++)
  {
    leds[patternIndex + j] = CRGB::Yellow;
    leds[(patternIndex + PATTERN_LENGTH) + j] = CRGB::Black;
   //   Serial.println("he");
  }
  FastLED.show();
}



void increment()
{
  if (patternIndex <= 0)
  {
    patternIndex = NUMBER_PIXELS + PATTERN_LENGTH;
 //   Serial.println("no");
    FastLED.clear();
  }
  else
  {
 //   Serial.println("yo");
    patternIndex -= PATTERN_LENGTH;
    animate();
  }
}


