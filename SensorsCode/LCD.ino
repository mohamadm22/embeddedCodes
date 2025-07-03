// 1. تضمين مكتبة LiquidCrystal
#include <LiquidCrystal.h>

// 2. إنشاء كائن باسم lcd وتعريف أرجل التوصيل بالترتيب:
// (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // 3. تهيئة الشاشة: 16 عمود و2 سطر
  lcd.begin(16, 2);

  // 5. تحريك المؤشر إلى السطر الاول (العمود رقم 0)
  lcd.setCursor(0, 0);
  // 4. طباعة رسالة في السطر الأول
  lcd.print("Hello ");

  // 5. تحريك المؤشر إلى السطر الثاني (العمود رقم 0)
  lcd.setCursor(0, 1);

  // 6. طباعة رسالة أخرى
  lcd.print("NEHAL");
}

void loop() {
  // لا يوجد شيء في الـ loop
}