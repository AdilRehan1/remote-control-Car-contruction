#include <Servo.h>

Servo steeringServo;

// Joystick pins
int joyX = A0;
int joyY = A1;
int servo = 9;

// Steering limits
int minAngle = 30;
int maxAngle = 150;

// Dead zone
int deadZone = 50;

void setup() {
  steeringServo.attach(servo);
}

void loop() {

  int xVal = analogRead(joyX);
  int yVal = analogRead(joyY);

  // ---------- STEERING ----------
  int angle = map(xVal, 0, 1023, minAngle, maxAngle);

  // Dead zone for center
  if (abs(xVal - 512) < deadZone) {
    angle = 90;
  }

  steeringServo.write(angle);

  // ---------- THROTTLE ----------
  delay(10);
}
