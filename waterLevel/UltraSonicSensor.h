clas UltrasonicSensor {
private:
  byte triggerPin;
  byte echoPin;
public:
  UltrasonicSensor(byte triggerPin, byte echoPin)
  void init();
};