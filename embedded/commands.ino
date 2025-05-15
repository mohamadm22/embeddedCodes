#define pin_name(led) pin_number(5)         //بنعرف رقم البين الي هنوصلها بالاردوينو
pinMode(pin_name,state(INPUT OUTPUT));      //بنعرف البين انبوت ولا اوتبوت
digitalRead(pin_name);                      //بنقرء القراية من علي البين
digitalWrite(pin_name,HIGH LOW);            //بنكتب علي البين
analogRead(pin_name);                       //بيقرء الاشارة الانالوج من علي البين


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
