// ISR for anemometer.
void anemo()
{
  anemoCounter++;
  darkChase();
}

// Turn off the current block, turn on the previous block,
// then set the current block to the next block. 
int darkChase()
{
  c->turnOff();
  c->getPrev()->turnOn();
  c = c->getNext();
}

// Turn on the current block, turn off the previous block,
// then set the current block to the next block. 
int lightChase()
{
  c->turnOn();
  c->getPrev()->turnOff();
  c = c->getNext();
}

