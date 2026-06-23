/*
   SG90 Servo Sweep — Microsecond Precision
   Uses writeMicroseconds() to send raw pulse widths instead of angles.
   This is what write() does behind the scenes.

   Connections:
   - Brown wire  → Arduino GND
   - Red wire    → Arduino 5V
   - Orange wire → Arduino pin 9

   Pulse width mapping (approximate):
   - 544 microseconds  = 0 degrees (minimum)
   - 1500 microseconds = 90 degrees (center)
   - 2400 microseconds = 180 degrees (maximum)

   Created by Parham (inquiline-dev), 2026.
   License: MIT — use it, change it, share it.
*/

#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  Serial.println("Microsecond precision mode.");
  Serial.println("Pulse width -> Approx angle");
  Serial.println("--------------------------");
}

void loop() {
  // Sweep using raw pulse widths (544 to 2400 microseconds)
  // Step by 50 microseconds each time for smooth movement
  for (int pulse = 544; pulse <= 2400; pulse += 50) {
    myServo.writeMicroseconds(pulse);
    
    // map() converts the pulse width to an approximate angle for display
    int approxAngle = map(pulse, 544, 2400, 0, 180);
    
    Serial.print(pulse);
    Serial.print(" us -> approx ");
    Serial.print(approxAngle);
    Serial.println(" degrees");
    
    delay(20);  // Slightly longer delay for smoother movement
  }

  delay(500);  // Pause at the end before reversing

  // Sweep back
  for (int pulse = 2400; pulse >= 544; pulse -= 50) {
    myServo.writeMicroseconds(pulse);
    int approxAngle = map(pulse, 544, 2400, 0, 180);
    Serial.print(pulse);
    Serial.print(" us -> approx ");
    Serial.print(approxAngle);
    Serial.println(" degrees");
    delay(20);
  }

  delay(500);
}
