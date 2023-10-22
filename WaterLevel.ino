int ultrasonicTriggerPin = 2;
int ultrasonicEcho = 3;
int serialPort = 9600;
int pulseDuration = 10;
int soundSpeed = 59;
int radarDelayInSeconds = 1;
int radarFinalDelay = 1000 * radarDelayInSeconds;

void setup() {
  Serial.begin(serialPort);
  pinMode(ultrasonicTriggerPin, OUTPUT);
  pinMode(ultrasonicEcho, INPUT);
  digitalWrite(ultrasonicTriggerPin, LOW);
}

void loop() {
  digitalWrite(ultrasonicTriggerPin, HIGH);
  delayMicroseconds(pulseDuration);
  digitalWrite(ultrasonicTriggerPin, LOW);
  long time = pulseIn(ultrasonicEcho, HIGH);
  long distance = calculateDistance(time);
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  delay(radarFinalDelay);
}

long calculateDistance(long time) {
  return time / soundSpeed;
}
