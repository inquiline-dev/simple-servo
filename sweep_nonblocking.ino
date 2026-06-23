/*
   SG90 Servo Sweep — Non-Blocking Version
   Uses millis() instead of delay() so the Arduino can multitask.
   First step toward real robot control.

   Connections:
   - Servo brown  → Arduino GND
   - Servo red    → Arduino 5V
   - Servo orange → Arduino pin 9

   Created by Parham (inquiline-dev), 2025.
   License: MIT
*/

#include <Servo.h>

Servo myServo;

int angle = 0;
int step = 1;
bool goingUp = true;

unsigned long previousMillis = 0;
const long interval = 15;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  Serial.println("Non-blocking servo sweep ready!");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    myServo.write(angle);
    Serial.print("Angle: ");
    Serial.println(angle);

    if (goingUp) {
      angle += step;
      if (angle >= 180) {
        angle = 180;
        goingUp = false;
      }
    } else {
      angle -= step;
      if (angle <= 0) {
        angle = 0;
        goingUp = true;
      }
    }
  }

  // Put other code here — it runs freely while the servo waits
}
