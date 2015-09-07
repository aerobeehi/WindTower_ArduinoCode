
void anemo()
{
  Serial.println("hey");
  anemoCounter++;
  animate();
}

int animate()
{
  c->turnOff();
  c->getPrev()->turnOn();
  c = c->getNext();
  Serial.println("yo");
}

