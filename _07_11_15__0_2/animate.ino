
void animate()
{
  for (int j = 0; j <= PATTERN_LENGTH; j++)
  {
    leds[patternIndex + j] = CRGB::White;
    leds[(patternIndex + PATTERN_LENGTH) + j] = CRGB::Black;
  }
  FastLED.show();
}


// This function increments the index of the

void increment()
{
  digitalWrite(13, HIGH);
  
  if (patternIndex <= -PATTERN_LENGTH)
  {
    patternIndex = NUMBER_PIXELS; //  + patternLength;
  }
  else
  {
    patternIndex -= PATTERN_LENGTH;
  }
 
  digitalWrite(13, LOW);
}


