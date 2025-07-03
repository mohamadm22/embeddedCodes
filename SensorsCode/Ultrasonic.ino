// رعشتسملاب ةلصتملا فارطلأا فيرعت 
const int trigPin = 9;  // ـب لصتملا فرطلا Trig رعشتسملا يف 
const int echoPin = 10; // ـب لصتملا فرطلا Echo رعشتسملا يف 
 
// ةفاسملاو ةدملا نيزختل تاريغتم فيرعت 
long duration; // ةدوعلاو باهذلل ةجوملا اهقرغتست يتلا ةينمزلا ةدملا نيزختل 
int distanceCm; // رتميتنسلاب ةفاسملا نيزختل 
 
void setup() { 
  // فرط ةئيهت Trig )ةضبنلا لاسرلإ( جرخمك 
  pinMode(trigPin, OUTPUT); 
  // فرط ةئيهت Echo )ىدصلا لابقتسلا( لخدمك 
  pinMode(echoPin, INPUT); 
 
} 
 
void loop() { 
  // 1. ةضبن لاسرإ Trigger: 
  // فرط نأ نم دكأتلا Trig ةلاح يف LOW لاسرلإا لبق ةريصق ةرتفل 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
 
  // ةضبن لاسرإ HIGH  ةدمل 10 تاجوملا لسري رعشتسملا لعجل ةيناثوركيم 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
 
  // 2. ةينمزلا ةدملا سايق: 
  // ةلاد مادختسا pulseIn() فرط اهيف لظي يتلا ةدملا سايقل Echo ةلاح يف HIGH 
  // ةدوعلاو باهذلل ةجوملا هتقرغتسا يذلا تقولا يه ةدملا هذه 
  duration = pulseIn(echoPin, HIGH); 
  // 3. ةفاسملا باسح: 
  //  / )توصلا ةعرس * ةيناثوركيملاب ةدملا( = رتميتنسلاب ةفاسملا 2 
  //  = ةيبيرقتلا توصلا ةعرس 0.0343 ةيناثوركيم/مس 
  //  / ةدملا :ةطاسبب وأ 58 رتميتنس ىلإ اهليوحتل 
  distanceCm = duration / 58; 

  delay(100); // ةديدج ةءارق ذخأ لبق ريصق ريخأت 
}
