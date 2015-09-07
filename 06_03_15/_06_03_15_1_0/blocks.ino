void systemSetup()
{
  Serial.end();
  Serial.begin(BAUDRATE);

  strip.begin();
  strip.clear();
  strip.show();

  Timer1.initialize(TIMER);
  Timer1.attachInterrupt(timer_Period);

  stopped = false;
  time = false;

  index_i.head = 0;
  index_i.tail = -2;

  anemo_counter = 0;
  pulses = 0;
}


void animate()
{
  strip.setPixelColor(index_f.head, 1, 1, 1);
  strip.setPixelColor(index_f.tail, 0);
  strip.show();

  get_Delay();

  index_f.plength = index_f.tail - index_f.head;
}
