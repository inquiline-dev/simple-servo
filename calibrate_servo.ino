/*
   SG90 Servo Calibration
   Finds the real minimum and maximum angles for your specific servo.
   Not all SG90s reach exactly 0 or 180 degrees without buzzing.

   Connections:
   - Brown wire  → Arduino GND
   - Red wire    → Arduino 5V
   - Orange wire → Arduino pin 9

   How to use:
   1. Upload this sketch
   2. Open Serial Monitor (9600 baud)
   3. Type an angle (0-180) and press Enter
   4. Listen for buzzing — that means the servo is straining
   5. Reduce the angle until the buzzing stops
   6. Those are your servo's real limits

   My servo buzzed at 0 degrees and stopped around 5. Yours might be different.

   Created by Parham (inquiline-dev), 2026.
   License: MIT — use it, change it, share it.
*/

#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  Serial.println("Servo Calibrator Ready");
  Serial.println("Type an angle (0-180) and press Enter.");
  Serial.println("Listen for buzzing — that means the servo is straining.");
  Serial.println("Find where it stops buzzing. Those are your real limits.");
}

void loop() {
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();  // Read the number you typed

    // Basic safety check — keep within 0-180 range
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);
      Serial.print("Moved to: ");
      Serial.print(angle);
      Serial.println(" degrees");
      
      if (angle <= 5 || angle >= 175) {
        Serial.println("  ^ Near the limit — hear any buzzing?");
      }
    } else {
      Serial.println("Please enter a number between 0 and 180.");
    }
  }
}
