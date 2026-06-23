/*
   SG90 Servo Sweep — Basic
   The simplest servo sketch. Moves from 0 to 180 degrees and back.
   Start here if you've never used a servo before.

   Connections:
   - Brown wire  → Arduino GND
   - Red wire    → Arduino 5V
   - Orange wire → Arduino pin 9

   The Servo library is built into Arduino IDE — no download needed.

   Created by Parham (inquiline-dev), 2026.
   License: MIT — use it, change it, share it.
*/

#include <Servo.h>  // Built-in library — already installed with Arduino IDE

Servo myServo;  // Create a servo object. Think of it as naming a remote control.

void setup() {
  myServo.attach(9);    // Tell the Arduino: the servo signal wire is on pin 9
  Serial.begin(9600);   // Start serial so we can see what angle the servo is at
  Serial.println("Servo ready! Starting sweep...");
}

void loop() {
  // Sweep from 0 to 180 degrees
  // Each time through the loop, angle increases by 1
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);   // Move the servo to this angle
    Serial.print("Moving to: ");
    Serial.println(angle);
    delay(15);              // Give the servo time to physically reach the angle
                            // 15ms is a good balance — smooth but not too slow
  }

  // Sweep back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    Serial.print("Moving to: ");
    Serial.println(angle);
    delay(15);
  }
}
