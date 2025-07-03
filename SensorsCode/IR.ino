int IRPin = 2 ; 
int Ledpin = 8; 
int readvalue ; 
void setup()
{ 
  pinMode ( IRPin , INPUT )  ; 
  pinMode ( LedPin , OUTPUT )  ; 
{ 
void loop() 
{
  if ( digitalRead ( IRPin ) ==LOW ) 
  {
    digitalWrite ( LedPin , HIGH )  ; 
  }
  else  
  {
    digitalWrite ( LedPin , LOW )   ; 
  } 
}