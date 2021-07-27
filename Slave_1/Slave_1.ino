#include <Servo.h>
#include <Wire.h>

Servo myServo[13];

void setup()
{

  for (int i = 0; i < 14; i++)
  {
    myServo[i].attach(i+1);
    myServo[i].write(0);
  }
  Wire.begin(1);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
           // start serial for output
}

void runServo(int x) {
  for (int pos = 0; pos <= 180; pos ++) 
  { 
    myServo[x-1].write(pos);
    Serial.println(pos);
    delay(15);                       
}

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  int x = Wire.read();    // receive byte as an integer
  runServo(x);

}
