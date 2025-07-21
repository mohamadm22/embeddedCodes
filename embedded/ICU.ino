bool MeasEnd = 0;
uint16_t T1, T2, T1OVF_Counter = 0;
unsigned long T, Freq = 0;
 
ISR(TIMER1_OVF_vect)
{
  T1OVF_Counter++;
}
 
ISR(TIMER1_CAPT_vect)
{
  if(MeasEnd==0)
  {
    T1 = ICR1;
    MeasEnd = 1;
    // TCCR1B &= ~(_BV(ICES1));     //ICU Pin FALLING
  }
  else
  {
    T2 = ICR1;
    T = T2 + (65536 * T1OVF_Counter) - T1;
    T1OVF_Counter = 0;
    MeasEnd = 0;
    TCCR1B |= B11000001;  // Internal Clock, Prescaler = 1, ICU Filter EN, ICU Pin RISING
  }
}
 
void setup()
{
  TCCR1A = 0;           // Init Timer1A
  TCCR1B = 0;           // Init Timer1B
  TCCR1B |= B11000001;  // Internal Clock, Prescaler = 1, ICU Filter EN, ICU Pin RISING
  TIMSK1 |= B00100001;  // Enable Timer OVF & CAPT Interrupts
}
 
void loop()
{}