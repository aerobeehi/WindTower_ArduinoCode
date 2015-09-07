
void anemo()
{
 // Serial.println("hey");
//  anemoCounter++;
  darkChase();
}

int darkChase()
{
  c->turnOff();
  c->getPrev()->turnOn();
//  c = c->getNext();
  Serial.println("yo");
}


int lightChase()
{
  c->turnOn();
  c->getPrev()->turnOff();
  c = c->getNext();
  Serial.println("yo");
}

