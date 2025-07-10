#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Keypad.h>

#define buzzerpin 13
#define sevoPin   10

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'D','#','0','*'},
  {'C','9','8','7'},
  {'B','6','5','4'},
  {'A','3','2','1'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal_I2C lcd(0x27, 20, 4);
Servo myservo;

String input_password = "258258"; 
String input = "";

void setup() {
  myservo.attach(sevoPin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); 
  lcd.print("Enter the pass:");
  lcd.setCursor(0, 1);
  pinMode(buzzerpin, OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    if (key == 'A') {
      if (input == input_password) {
        lcd.clear();
        lcd.print("Access Granted");
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        myservo.write(90);
        delay(1000);
        myservo.write(0);
      } else {
        lcd.clear();
        lcd.print("Access Denied");
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
      lcd.print("Enter the pass:");
      lcd.setCursor(0, 1);
    }
    else if(key == 'C')
    {
      input = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter the pass:");
      lcd.setCursor(0, 1);
    }
    else{
      input += key;
      lcd.print('*');
    }
  }
}