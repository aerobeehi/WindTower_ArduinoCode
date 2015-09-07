

void systemSetup()
{
  Serial.begin(BAUD_RATE);

  attachInterrupt(0, anemo, RISING); // Interrupt 0 => Pin 2.

  anemoCounter = 0;
}

