#include "UltraSonicSensor.h"

byte ultrasonicTriggerPin = 2;
byte ultrasonicEchoPin = 3;
int serialPort = 9600;
int pulseDuration = 10;
int soundSpeed = 59;
int radarDelayInSeconds = 1;
int radarFinalDelay = 1000 * radarDelayInSeconds;

UltrasonicSensor ultrasonicSensor(ultrasonicTriggerPin, ultrasonicEchoPin);

void setup()
{
  Serial.begin(serialPort);
  ultrasonicSensor.init();
}

void loop()
{
  ultrasonicSensor.getDistance();
  delay(radarFinalDelay);
}
