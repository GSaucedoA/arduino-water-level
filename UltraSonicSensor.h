#ifndef ULTRASONIC_SENSOR
#define ULTRASONIC_SENSOR

#include <Arduino.h>
class UltrasonicSensor
{
private:
  byte triggerPin;
  byte echoPin;
  int pulseDuration = 10;
  boolean serialLogEnabled = false;
  long calculateDistance(long time);
  void printData(long distance);

public:
  UltrasonicSensor(byte triggerPin, byte echoPin);
  void init();
  void enableSerialLog(boolean status);
  long getDistance();
};
#endif