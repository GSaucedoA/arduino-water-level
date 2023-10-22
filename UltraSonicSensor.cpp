#include "UltraSonicSensor.h"
UltrasonicSensor::UltrasonicSensor(byte triggerPin, byte echoPin)
{
  this->triggerPin = triggerPin;
  this->echoPin = echoPin;
}
void UltrasonicSensor::init()
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);
}
void UltrasonicSensor::triggerOn() {}
void UltrasonicSensor::triggerOff() {}
long UltrasonicSensor::getDistance()
{
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(pulseDuration);
  digitalWrite(triggerPin, LOW);
  long time = pulseIn(echoPin, HIGH);
  long distance = calculateDistance(time);
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  return distance;
}

long UltrasonicSensor::calculateDistance(long time){
return time / 59;
}
