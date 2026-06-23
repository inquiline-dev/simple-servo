/*
   SG90 Servo Sweep
   The simplest servo code — it moves from 0 to 180 degrees and back.
   No extra libraries, no confusion.

   Connections:
   - Servo brown  → Arduino GND
   - Servo red    → Arduino 5V
   - Servo orange → Arduino pin 9

   Created by Parham (inquiline-dev), 2026.
   License: MIT — use it, change it, share it.
*/

#include <Servo.h>  // Built-in library for controlling servos

Servo myServo;      // Create a servo object called "myServo"

void setup() {
  myServo.attach(9);   // Tell the Arduino the servo is on pin 9
  Serial.begin(9600);  // Start communication so we can see angles
  Serial.println("Servo ready! Watch it sweep.");
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);               // Move to the current angle
    Serial.print("Moving to: ");
    Serial.println(angle);
    delay(15);                          // Small pause for smooth movement
  }

  // Sweep back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    Serial.print("Moving to: ");
    Serial.println(angle);
    delay(15);
  }
}
