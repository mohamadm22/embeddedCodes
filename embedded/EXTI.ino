#define led 13

void setup()
{
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), EXTI_INTERRUPT2, RISING);
}

void loop()
{

}

void EXTI_INTERRUPT2()
{
  digitalWrite(led, HIGH);
}

void EXTI_INTERRUPT3()
{
}