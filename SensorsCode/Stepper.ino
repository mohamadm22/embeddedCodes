#include <Stepper.h>
#define steps 200
#define IN1 2
#define IN3 3
#define IN2 4
#define IN4 5
Stepper stepper(steps, IN1, IN3, IN2, IN4);
void setup()
{
}
void loop()
{
  stepper.setSpeed(5);
  stepper.step(steps);
  delay(1000);
  stepper.setSpeed(5);
  stepper.step(-steps);
  delay(1000);
}