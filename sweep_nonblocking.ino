/*
   SG90 Servo Sweep — Non-Blocking Version
   Uses millis() instead of delay(). The Arduino can do other things
   while the servo moves. This is how real robots work.

   Connections:
   - Brown wire  → Arduino GND
   - Red wire    → Arduino 5V
   - Orange wire → Arduino pin 9

   Why this matters:
   delay() FREEZES the Arduino — it literally does nothing else.
   millis() lets you check if it's time to move, then immediately
   continue reading sensors, checking buttons, etc.

   Created by Parham (inquiline-dev), 2026.
   License: MIT — use it, change it, share it.
*/

#include <Servo.h>

Servo myServo;

int angle = 0;             // Current servo angle
int step = 1;              // Degrees to move each time
bool goingUp = true;       // Direction flag

unsigned long previousMillis = 0;   // Last time we moved the servo
const long interval = 15;           // Milliseconds between moves (same as delay(15))

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  Serial.println("Non-blocking servo sweep ready!");
  Serial.println("The Arduino is free to do other things while the servo moves.");
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time

  // Check if enough time has passed since the last move
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Save the time of this move

    myServo.write(angle);  // Move the servo
    Serial.print("Angle: ");
    Serial.println(angle);

    // Update the angle and handle direction changes
    if (goingUp) {
      angle += step;
      if (angle >= 180) {
        angle = 180;
        goingUp = false;  // Reverse direction
      }
    } else {
      angle -= step;
      if (angle <= 0) {
        angle = 0;
        goingUp = true;   // Reverse direction
      }
    }
  }

  // You can add other code here!
  // It will run thousands of times per second while waiting for the next servo move.
  // For example: read a sensor, check a button, update an LED...
  // This is what makes millis() powerful — the Arduino multitasks.
}
