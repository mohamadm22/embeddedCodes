#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Keypad.h>

#define buzzerpin 13
#define servopin 10
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'c','0','=','+'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6 ,7, 8, 9};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal_I2C lcd(0x27, 20, 4);
Servo myservo;

String input_password = "258258"; 
String input = "";

void setup() {
  myservo.attach(servopin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); 
  lcd.print("Enter the pass");
  pinMode(buzzerpin, OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    

    if (key == '=') {
      if (input == input_password) {
        lcd.clear();
        lcd.print("Access granted");
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        myservo.write(90);
        delay(1000);
        myservo.write(0);
      } else {
        lcd.clear();
        lcd.print("Access deniend");
        for (int i = 0; i < 5; i++) {
          digitalWrite(buzzerpin, HIGH);
          delay(100);
          digitalWrite(buzzerpin, LOW);
          delay(100);
        }
      }

      delay(2000);
      input = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter the pass");
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }else if(key == 'c'){
      input = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter the pass");
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
    else
    {
      input += key;
      lcd.setCursor(input.length() - 1, 1);
      lcd.print("*");
    }
  }
}
