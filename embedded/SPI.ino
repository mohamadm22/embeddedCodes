#include <SPI.h>

#define slave 3

void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  pinMode(slave,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(slave,LOW);
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  SPI.transfer(5);
  SPI.endTransaction();
}
