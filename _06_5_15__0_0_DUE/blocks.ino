

void systemSetup()
{
  Serial.end();
  Serial.begin(BAUDRATE);
}

void increment()
{
  int k;
  if ((_N_PULSES += 2) < 80)
  {
    for (k = 0; k < _N_PULSES + 20; k++)
    {
      digitalWrite(8, HIGH);
      digitalWrite(13, HIGH);
      delayMicroseconds(1000000 / (_N_PULSES * 2));
      digitalWrite(8, LOW);
      digitalWrite(13, LOW);
      delayMicroseconds(1000000 / (_N_PULSES * 2));
    }
  }
  else
  {
    _N_PULSES = 0;
  }
}


void constant()
{
      digitalWrite(8, HIGH);
      digitalWrite(13, HIGH);
      delayMicroseconds(1000000 / (N_PULSES * 2));
      digitalWrite(8, LOW);
      digitalWrite(13, LOW);
      delayMicroseconds(1000000 / (N_PULSES * 2));
}
