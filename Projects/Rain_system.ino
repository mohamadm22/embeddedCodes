#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

#define buzzPin  37
#define RainPin  A8
#define servoPin 28

#define minRead 5
#define maxRead 60

int timer;
LiquidCrystal_I2C Lcd ( 0x27, 20, 4 );
Servo WindowServo;

void setup ( ) 
{
  pinMode(buzzPin,OUTPUT);
  Lcd.init ( );
  Lcd.backlight ( );
  WindowServo.attach(servoPin);
  // Display "System Loading" on LCD
  Lcd.setCursor(3, 0);
  Lcd.print("System Loading");
  for (int a = 0; a < 20; a++) {
    Lcd.setCursor(a, 1);
    Lcd.print(".");
    delay(100);
  }
  Lcd.clear();
  timer=millis();
}
void loop ( ) 
{
  Lcd.clear();
  Lcd.setCursor (0,0);
  Lcd.print("Rain Intensity:");
  
  Lcd.setCursor (0,1);
  if(analogRead (RainPin)<minRead)
  {
    Lcd.print("0%");
  }
  else if(analogRead (RainPin)>minRead)
  {
    if(analogRead (RainPin)>maxRead)
    {
      Lcd.print("100%");
    }
    else
    {
      Lcd.print(map(analogRead (RainPin),minRead,maxRead,0,100));
      Lcd.print("%");
    }
  }
  Lcd.setCursor(0,3);
  if ( analogRead (RainPin) <minRead )
  {
  WindowServo.write (90);
  Lcd.print("There is no Rain");
  timer=millis();
  digitalWrite(buzzPin,LOW);
  }
  else
  {
  WindowServo.write (0);
  Lcd.print("There is Rain");
  if(millis()-timer<3000)
  {
    digitalWrite(buzzPin,HIGH);
  }
  else{
    digitalWrite(buzzPin,LOW);
  }
  }
  delay(100);
}