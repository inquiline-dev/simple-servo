/*
   Potentiometer-Controlled Servo
   Turn a knob and the servo follows. No computer needed after upload.

   Connections:
   - Servo brown  → Arduino GND
   - Servo red    → Arduino 5V
   - Servo orange → Arduino pin 9
   - Pot left pin  → Arduino GND
   - Pot center    → Arduino A0
   - Pot right pin → Arduino 5V

   How it works:
   analogRead(A0) returns 0-1023 based on the knob position.
   map() converts that range to 0-180 degrees for the servo.

   Created by Parham (inquiline-dev), 2026.
   License: MIT — use it, change it, share it.
*/

#include <Servo.h>

Servo myServo;

const int potPin = A0;     // Potentiometer center pin
const int servoPin = 9;    // Servo signal pin

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
  Serial.println("Turn the knob — the servo follows.");
  Serial.println("Pot value -> Angle");
  Serial.println("-------------------");
}

void loop() {
  int potValue = analogRead(potPin);              // Read the knob (0-1023)
  int angle = map(potValue, 0, 1023, 0, 180);     // Convert to servo angle (0-180)

  myServo.write(angle);  // Move the servo

  // Show what's happening
  Serial.print(potValue);
  Serial.print(" -> ");
  Serial.print(angle);
  Serial.println(" degrees");

  delay(15);  // Smooth movement — not too fast, not too slow
}
