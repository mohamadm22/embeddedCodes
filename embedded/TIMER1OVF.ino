#define greenLed 3

uint8_t counter=0;

ISR(TIMER1_OVF_vect)
{
  TCNT1 = 40535; // Timer Preloading
  // Handle The 100ms Timer Interrupt
  counter++;
}
void setup() {
  
  pinMode(greenLed, OUTPUT);
  TCCR1A = 0;           // Init Timer1
  TCCR1B = 0;           // Init Timer1
  TCCR1B |= B00000011;  // Prescalar = 64
  TCNT1 = 40535;        // Timer Preloading
  TIMSK1 |= B00000001;  // Enable Timer Overflow Interrupt  
}

void loop() {
  if(counter==30)
  {
    digitalWrite(greenLed, HIGH);     
  }
}
