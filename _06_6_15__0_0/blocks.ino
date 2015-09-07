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
  Serial.println(anemo_counter);
  if (anemo_counter < 40)
  {
    M += A;
    animate_A();
  }
  else
  {
    M += A;
    animate_A();
    delayMicroseconds(6000);
    M += A;
    animate_A();
  }
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

  time = false;

  wind_i = 0;

  anemo_counter = 0;
  pulses = 0;
}
