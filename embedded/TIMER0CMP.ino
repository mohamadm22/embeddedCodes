#define greenLed 3

int timer=0;

ISR(TIMER0_COMPA_vect){    //This  is the interrupt request
  timer++;
}

void setup() {
  pinMode(greenLed,OUTPUT);
    
  TCCR0A=(1<<WGM01);    //Set the CTC mode   
  OCR0A=0xF9; //Value for ORC0A for 1ms 
  
  TIMSK0|=(1<<OCIE0A);   //Set  the interrupt request
  sei(); //Enable interrupt
  
  TCCR0B|=(1<<CS01);    //Set the prescale 1/64 clock
  TCCR0B|=(1<<CS00); 
}

void  loop() {
  //in this way you can count 1 second because the nterrupt request  is each 1ms
  if(timer>=1000){
    digitalWrite(greenLed,HIGH);
    timer=0;
  } 
}

