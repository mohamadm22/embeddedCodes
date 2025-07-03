// 1. لا حاجة إلى مكتبة خارجية، نستخدم analogRead

int LDR_Pin = A0;         // 2. تعريف منفذ إدخال الحساس

void setup() {
}

void loop() {

  analogRead(LDR_Pin)*5/1023;            // 3. بترجع قيمة الاضائة

}