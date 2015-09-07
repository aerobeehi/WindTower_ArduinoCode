void increment()
{
  if (M > (_NUMPIXELS - 1 ))
  {
    h = dht.readHumidity();
    f = dht.readTemperature(true);

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
  M += A;
  animate();
}




void systemSetup()
{
  Serial.end();
  Serial.begin(BAUDRATE);

  dht.begin();

  strip.begin();
  strip.clear();
  strip.show();

  Timer1.initialize(TIMER);
  Timer1.attachInterrupt(timer_Period);
  attachInterrupt(0, anemo, RISING);

  time = false;

  anemo_counter = 0;
  pulses = 0;
}
