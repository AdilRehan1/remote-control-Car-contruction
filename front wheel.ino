#include <Servo.h>

Servo steeringServo;

// Joystick pins
int joyX = A0;
int joyY = A1;

// Motor driver pins
int IN1 = 5;
int IN2 = 6;
int PWM = 3;

// Steering limits
int minAngle = 30;
int maxAngle = 150;

// Dead zone
int deadZone = 50;

void setup() {
  steeringServo.attach(9);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
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
  int speed;

  if (yVal > (512 + deadZone)) {
    // FORWARD
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    speed = map(yVal, 512 + deadZone, 1023, 0, 255);
    analogWrite(PWM, speed);

  } 
  else if (yVal < (512 - deadZone)) {
    // REVERSE
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    speed = map(yVal, 512 - deadZone, 0, 0, 255);
    analogWrite(PWM, speed);

  } 
  else {
    // STOP
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(PWM, 0);
  }

  delay(10);
}  delay(10);
}
