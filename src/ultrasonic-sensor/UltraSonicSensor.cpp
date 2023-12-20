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
void UltrasonicSensor::enableSerialLog(boolean status)
{
  serialLogEnabled = status;
}

long UltrasonicSensor::getDistance()
{
  startPulse();
  delayMicroseconds(pulseDuration);
  stopPulse();
  long time = pulseIn(echoPin, HIGH);
  long distance = calculateDistance(time);
  if (serialLogEnabled)
    printData(distance);

  return distance;
}

// Private Methods

long UltrasonicSensor::calculateDistance(long time)
{
  return time / 59;
}

void UltrasonicSensor::printData(long distance)
{
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
}

void UltrasonicSensor::startPulse()
{
  digitalWrite(triggerPin, HIGH);
}

void UltrasonicSensor::stopPulse()
{
  digitalWrite(triggerPin, LOW);
}
