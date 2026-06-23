/*
   Two Servos Sweeping Together
   Servo 1 on pin 9, Servo 2 on pin 10.
   They move in opposite directions — the basis of a pan-tilt mount.

   Connections:
   - Servo 1: brown → GND, red → 5V, orange → pin 9
   - Servo 2: brown → GND, red → 5V, orange → pin 10

   Power warning:
   Two unloaded SG90s on USB power are usually fine.
   If they stall or buzz, use an external 5V supply.
   See external-power.md for details.

   Created by Parham (inquiline-dev), 2026.
   License: MIT — use it, change it, share it.
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
  // Servo 1 goes 0 to 180 while Servo 2 goes 180 to 0
  // They mirror each other — like a jaw opening and closing
  for (int angle = 0; angle <= 180; angle++) {
    servo1.write(angle);           // 0 -> 180
    servo2.write(180 - angle);     // 180 -> 0 (opposite)
    
    Serial.print("Servo 1: ");
    Serial.print(angle);
    Serial.print("  Servo 2: ");
    Serial.println(180 - angle);
    
    delay(15);
  }

  delay(300);  // Brief pause before reversing

  // Reverse the sweep
  for (int angle = 180; angle >= 0; angle--) {
    servo1.write(angle);
    servo2.write(180 - angle);
    delay(15);
  }

  delay(300);
}
