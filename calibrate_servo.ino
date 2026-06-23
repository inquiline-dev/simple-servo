/*
   SG90 Servo Calibration
   Finds the real minimum and maximum angles for your specific servo.
   Not all SG90s reach exactly 0° or 180°. This sketch lets you find yours.

   Connections:
   - Servo brown  → Arduino GND
   - Servo red    → Arduino 5V
   - Servo orange → Arduino pin 9

   How to use:
   1. Upload this sketch.
   2. Open Serial Monitor (9600 baud).
   3. Type a number (0–180) and press Enter.
   4. The servo moves to that angle.
   5. Try 0, then 180. Does it buzz? Does it hit a mechanical stop?
   6. Reduce until it's quiet — that's your real range.

   Created by Parham (inquiline-dev), 2026.
   License: MIT
*/

#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  Serial.println("Servo Calibrator Ready");
  Serial.println("Type an angle (0–180) and press Enter.");
  Serial.println("Listen for buzzing — that means the servo is straining.");
}

void loop() {
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();

    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);
      Serial.print("Moved to: ");
      Serial.print(angle);
      Serial.println("°");
      Serial.println("Hear buzzing? Reduce the angle slightly.");
    } else {
      Serial.println("Please enter a number between 0 and 180.");
    }
  }
}
