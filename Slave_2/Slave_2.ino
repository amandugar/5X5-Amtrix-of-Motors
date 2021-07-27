#include <Servo.h>
#include <Wire.h>

Servo myServo[12];

void setup()
{
  for (int i = 0; i < 13; i++)
  {
    myServo[i].attach(i + 1);
    myServo[i].write(0);
  }
  Wire.begin(2);
  Wire.onReceive(receiveEvent);

}

void runServo(byte x) {
  for (int pos = 0; pos <= 180; pos ++) // goes from 0 degrees to 180 degrees
  {

    myServo[x-1].write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void loop()
{
  delay(100);
}

void receiveEvent(int howMany)
{
  int x = Wire.read();
  runServo(x);

}
