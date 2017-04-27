
#include <Servo.h>

float voltage = 0;
float  sensor = 0;
float currentC = 0;
int      angle = 0;

Servo myservo;


void setup()
{
  myservo.attach(4);
  myservo.write(95);
  Serial.begin(9600);
}

int calculateservo(float temperature)
{
  float resulta;
  int resultb;
  resulta = -6 * temperature;
  resulta = resulta + 180;
  resultb = int(resulta);
  return resultb;
}
void loop() {
  // read current temperature
  int sensor = analogRead(0);
  Serial.println(sensor);
  delay(500);

  voltage = (sensor * 5000) / 1024;
  voltage = voltage - 500;
  currentC = voltage / 10;

  // display current temperature on servo
  //angle = calculateservo(currentC);

  // angle = sensor;

  // convert temperature to a servo position
  if (sensor > 125)
  {
    myservo.write(0); // set servo to temperature

  } else {
    myservo.write(95);
  }
}
