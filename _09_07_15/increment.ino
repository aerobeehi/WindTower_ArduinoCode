
void anemo()
{
  anemoCounter++;
  darkChase();
}

int darkChase()
{
  c->turnOff();
  c->getPrev()->turnOn();
  c = c->getNext();
}


int lightChase()
{
  c->turnOn();
  c->getPrev()->turnOff();
  c = c->getNext();
}

