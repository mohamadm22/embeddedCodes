#include <Wire.h>
#define led 3

void setup()
{
  Wire.begin(0x50);                // join i2c bus with address #4
  pinMode(led,OUTPUT);
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
}

void loop()
{
  
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  if(Wire.read()==5)    // receive byte as an integer
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }    
}

void requestEvent() 
{
  Wire.write(6);         // respond with message of 6 bytes as expected by master
}