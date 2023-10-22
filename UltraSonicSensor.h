#ifndef ULTRASONIC_SENSOR
#define ULTRASONIC_SENSOR

#include <Arduino.h>
class UltrasonicSensor
{
private:
  byte triggerPin;
  byte echoPin;
  int pulseDuration = 10;
  long calculateDistance(long time);

public:
  UltrasonicSensor(byte triggerPin, byte echoPin);
  void init();
  void triggerOn();
  void triggerOff();
  long getDistance();
};
#endif