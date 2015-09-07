

// Every time there is a rising edge on pin 2,
// the value of i increases by one until it reaches 100,000.
void anemo()
{
  anemo_counter++;
  increment();
}


// Every time that the timer reaches 1 second,
// time becomes true and the counter value from anemo
// used for calculateing windspeed is updated.
//
void timer_Period()
{
  time = true;
  pulses = anemo_counter;
  anemo_counter = 0;
}





