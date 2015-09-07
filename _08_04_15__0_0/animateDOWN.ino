
void animateDown()
{
  for (int j = 0; j <= LENGTH; j++)
  {
    strip.setPixelColor((patternIndex + j), ON);
    strip.setPixelColor((patternIndex+ LENGTH + j), OFF);
  }

  strip.show();
}


// This function increments the index of the

void incrementDown()
{
  if (patternIndex <= 0)
  {
    patternIndex = NUMBER_PIXELS + LENGTH;
 //   animateDown();
    strip.clear();
  }
  else
  {
    patternIndex -= LENGTH;
    animateDown();
  }
}


