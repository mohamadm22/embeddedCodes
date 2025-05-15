#include <Wire.h>
#define address 0x50

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(address);
  Wire.write(3);
  Wire.endTransmission();

  Wire.requestFrom(address,1);
  Wire.read();
  
}






























