void increment()
{
  if (M > (_NUMPIXELS - 1 ))
  {
    M = -A;
    refresh();
  }
  else
  {
    refresh();
  }
}



void refresh()
{
  int i, j;

  M += A;
  animate_A();

}




void systemSetup()
{
  Serial.end();
  Serial.begin(BAUDRATE);

  strip.begin();
  strip.clear();
  strip.show();

  Timer1.initialize(TIMER);
  Timer1.attachInterrupt(timer_Period);
  attachInterrupt(0, anemo, RISING);

  analogReference(EXTERNAL);

  time = false;

  wind_i = 0;

  anemo_counter = 0;
  pulses = 0;
}
