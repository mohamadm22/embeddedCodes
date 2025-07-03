#include <Keypad.h>  // 1. استدعاء مكتبة Keypad

// 2. تحديد عدد الصفوف والأعمدة
const byte ROWS = 4; 
const byte COLS = 4;

// 3. إنشاء مصفوفة تمثل الأحرف الموجودة في لوحة المفاتيح
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// 4. تعريف أرجل الصفوف والأعمدة المرتبطة بالأردوينو
byte rowPins[ROWS] = {9, 8, 7, 6};   // توصيل R1-R4
byte colPins[COLS] = {5, 4, 3, 2};   // توصيل C1-C4

// 5. إنشاء كائن Keypad باستخدام المكتبة
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
}

void loop() {
  
  if (keypad.getKey())  // 8. إذا تم الضغط على زر (قيمة غير فارغة)
  {  
  }
}