#include <Servo.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define distanceThreshold 5

const int trigPin = 40;  
const int echoPin = 39; 
const int servoPin = 29; 
 
Servo myServo; 

LiquidCrystal_I2C lcd(0x27, 20, 4);

long duration; 
int distanceCm; 

void setup() { 
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
 
  myServo.attach(servoPin); 
  lcd.init(); 
  lcd.backlight();
  
  // Display "System Loading" on LCD
  lcd.setCursor(3, 0);
  lcd.print("System Loading");
  for (int a = 0; a < 20; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(100);
  }
  lcd.clear();
} 
 
void loop() { 
  lcd.clear();  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
 
  duration = pulseIn(echoPin, HIGH); 
  distanceCm = duration / 58; 

  if (distanceCm < distanceThreshold)
  {
    myServo.write(90);
    lcd.setCursor(0, 3); 
    lcd.print("Garage ON");
  }
  else
  {
    myServo.write(0); 
    lcd.setCursor(0, 3); 
    lcd.print("Garage OFF");
  }
  delay(100); 
}