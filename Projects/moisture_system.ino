#include<LiquidCrystal_I2C.h>
#include<Wire.h>

#define pump 15
#define moisture A0
#define buzz 18
#define markeb 25

LiquidCrystal_I2C lcd(0x27,20,4);
int timer;

void setup() {
  // put your setup code here, to run once:
  pinMode(pump,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(markeb,INPUT_PULLUP);
  lcd.init();
  lcd.backlight(); // Turn on the backlight
  // Display "System Loading" on LCD
  lcd.setCursor(3, 0);
  lcd.print("System Loading");
  for (int a = 0; a < 20; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(100);
  }
  lcd.clear();
  timer=millis();
}

void loop() {
 // put your main code here, to run repeatedly:
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Moisture: ");
 lcd.print(map(analogRead(moisture),0,1023,0,100));
 lcd.print("%");
 if(digitalRead(markeb)==HIGH)
 {
 if(analogRead(moisture)>=400){
  lcd.setCursor(0,1);
  lcd.print("Auto pump ON"); 
  digitalWrite(pump,HIGH);
  if(millis()-timer<2000)
  {
    digitalWrite(buzz,HIGH);
  }
  else{
    digitalWrite(buzz,LOW);
  }
  }
  else{
    lcd.setCursor(0,1);
    lcd.print("Auto pump OFF");
    digitalWrite(pump,LOW);
    timer=millis();
  }
 }
 else{
  lcd.setCursor(0,1);
  lcd.print("Manual pump ON"); 
  digitalWrite(pump,HIGH);
  if(millis()-timer<2000)
  {
    digitalWrite(buzz,HIGH);
  }
  else{
    digitalWrite(buzz,LOW);
  }
 }
 delay(100);
}