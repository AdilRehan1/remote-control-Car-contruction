#include <Servo.h>

Servo steeringServo;

int potPin = A0;
int servo = 9
int potValue;

int minAngle = 30;   // left limit
int maxAngle = 150;  // right limit

void setup() {
  steeringServo.attach(servo);
}

void loop() {

  potValue = analogRead(potPin);   // read potentiometer (0–1023)

  int angle = map(potValue, 0, 1023, minAngle, maxAngle);

  steeringServo.write(angle);

  delay(10);
}
