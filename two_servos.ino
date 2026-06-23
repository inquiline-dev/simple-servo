/*
   Two Servos Sweeping Together
   Servo 1 on pin 9, Servo 2 on pin 10.
   They move in opposite directions — the basis of a pan-tilt mount.

   Connections:
   - Servo 1: brown → GND, red → 5V, orange → pin 9
   - Servo 2: brown → GND, red → 5V, orange → pin 10

   Power warning: Two unloaded SG90s are usually safe on USB power.
   If they stall or buzz, use an external 5V supply.

   Created by Parham (inquiline-dev), 2025.
   License: MIT
*/

#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  Serial.begin(9600);
  Serial.println("Two servos, opposite directions.");
}

void loop() {
  for (int angle = 0; angle <= 180; angle++) {
    servo1.write(angle);
    servo2.write(180 - angle);
    Serial.print("Servo 1: ");
    Serial.print(angle);
    Serial.print("  Servo 2: ");
    Serial.println(180 - angle);
    delay(15);
  }

  delay(300);

  for (int angle = 180; angle >= 0; angle--) {
    servo1.write(angle);
    servo2.write(180 - angle);
    delay(15);
  }

  delay(300);
}
