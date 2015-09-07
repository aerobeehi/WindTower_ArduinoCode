

void systemSetup()
{
  Serial.end();
  Serial.begin(BAUD_RATE);
  
  strip.begin(); 
  strip.show();  

  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.

  anemoCounter = 0;

  patternIndex = NUMBER_PIXELS;
  
  Serial.println("Hey");
}

