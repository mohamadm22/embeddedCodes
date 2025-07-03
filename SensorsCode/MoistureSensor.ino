// 1. لا حاجة إلى مكتبة خارجية، نستخدم analogRead

int moisturePin = A0;         // 2. تعريف منفذ إدخال الحساس

void setup() {
}

void loop() {

  analogRead(moisturePin);            // 3. بترجع قيمة الرطوبة

}