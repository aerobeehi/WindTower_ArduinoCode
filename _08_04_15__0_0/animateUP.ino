
void animate()
{
//  strip.clear();
  
  for (int j = 0; j <= LENGTH; j++)
  {
    strip.setPixelColor((patternIndex + j), ON);
    strip.setPixelColor(((patternIndex- LENGTH) + j), OFF);
  }

  strip.show();
}


// This function increments the index of the

void increment()
{
  if (patternIndex >= NUMBER_PIXELS - 1)
  {
    patternIndex = -LENGTH; //  + LENGTH;
//    animate();
  }
  else
  {
    patternIndex += LENGTH;
    animate();
  }
}


