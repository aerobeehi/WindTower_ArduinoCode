
// Wind Speed = ( N_PULSES / 8 ) * 2.5
#define   N_PULSES       2
#define   BAUDRATE       9600

int _N_PULSES;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(BAUDRATE);
}


void loop()
{
increment();
}

