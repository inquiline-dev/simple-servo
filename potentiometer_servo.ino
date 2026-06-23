/*
   Potentiometer-Controlled Servo
   Turn a knob and the servo follows. No computer needed after upload.

   Connections:
   - Servo brown  → Arduino GND
   - Servo red    → Arduino 5V
   - Servo orange → Arduino pin 9
   - Potentiometer left pin   → Arduino GND
   - Potentiometer center pin → Arduino A0
   - Potentiometer right pin  → Arduino 5V

   Created by Parham (inquiline-dev), 2026.
   License: MIT
*/

#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int servoPin = 9;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
  Serial.println("Turn the knob — the servo follows.");
}

void loop() {
  int potValue = analogRead(potPin);
  int angle = map(potValue, 0, 1023, 0, 180);

  myServo.write(angle);

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print("  ->  Angle: ");
  Serial.println(angle);

  delay(15);
}
