#include<SPI.h>
#define led 3

ISR (SPI_STC_vect)        //Inerrrput routine function 
{
  if(SPDR==5)   // Get the received data from SPDR register
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  SPDR=0;
}

void setup()
{
  pinMode(MISO,OUTPUT);   //Sets MISO as OUTPUT
  pinMode(led,OUTPUT);   
  SPCR |= _BV(SPE);       //Turn on SPI in Slave Mode
  SPI.attachInterrupt();  //Activate SPI Interuupt 
}


void loop()
{ 
  
}