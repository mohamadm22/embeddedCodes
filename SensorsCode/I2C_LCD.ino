#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Initialize the LCD with I2C address 0x27, 16 columns, and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
}
void loop() {
  lcd.clear(); // Clear the display
  lcd.setCursor(0, 0); // Set cursor to column 0, row 0
  lcd.print("Hello!"); // Print text on the first row
  lcd.setCursor(0, 1); // Set cursor to column 0, row 1
  lcd.print("Arduino I2C"); // Print text on the second row
  delay(2000); // Wait for 2 seconds
}

