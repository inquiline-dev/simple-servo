/*
   SG90 Servo Sweep — Microsecond Precision
   Uses writeMicroseconds() for direct pulse-width control.
   This is what write() does behind the scenes.

   Connections:
   - Servo brown  → Arduino GND
   - Servo red    → Arduino 5V
   - Servo orange → Arduino pin 9

   Created by Parham (inquiline-dev), 2025.
   License: MIT
*/

#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  Serial.println("Servo ready! Microsecond precision mode.");
  Serial.println("Pulse width   |   Approx. Angle");
  Serial.println("--------------------------------");
}

void loop() {
  // 544 microseconds = minimum pulse (~0°)
  // 2400 microseconds = maximum pulse (~180°)
  // 1500 microseconds = center (~90°)

  for (int pulse = 544; pulse <= 2400; pulse += 50) {
    myServo.writeMicroseconds(pulse);
    Serial.print("Pulse: ");
    Serial.print(pulse);
    Serial.print(" us  ->  approx ");
    int approxAngle = map(pulse, 544, 2400, 0, 180);
    Serial.print(approxAngle);
    Serial.println(" degrees");
    delay(20);
  }

  delay(500);

  for (int pulse = 2400; pulse >= 544; pulse -= 50) {
    myServo.writeMicroseconds(pulse);
    int approxAngle = map(pulse, 544, 2400, 0, 180);
    Serial.print("Pulse: ");
    Serial.print(pulse);
    Serial.print(" us  ->  approx ");
    Serial.print(approxAngle);
    Serial.println(" degrees");
    delay(20);
  }

  delay(500);
}
