# Using an External Power Supply for Servos

One SG90 on USB power is fine. But what if you want to run 2, 3, or 4?

---

## Why you need external power

| Power Source | Max Current | How Many SG90s (moving) |
|-------------|------------|------------------------|
| Arduino 5V pin (USB) | ~400mA | 1–2 safely |
| External 5V 2A adapter | 2000mA | 5–6 easily |
| External 5V 5A supply | 5000mA | 10+ |

When a servo stalls, it can pull **360mA or more**. Two stalled servos = 720mA = brownout or Arduino reset.  

The fix: power the servos separately. The Arduino still controls them, but the heavy current comes from somewhere else.

---

## How to connect external power

External 5V Supply (+) goes to Breadboard red rail (+)  
External 5V Supply (-) goes to Breadboard blue rail (-)  

Breadboard red rail (+) goes to Servo 1 red wire  
Breadboard red rail (+) goes to Servo 2 red wire  
Breadboard blue rail (-) goes to Servo 1 brown wire  
Breadboard blue rail (-) goes to Servo 2 brown wire  
Breadboard blue rail (-) goes to Arduino GND (shared ground!)

**Critical:** Connect the external supply's ground to Arduino GND.  
Without a shared ground, the servo can't understand the signal from the Arduino.

---

## What to use as a power supply

- A 5V 2A wall adapter with a barrel jack
- A bench power supply set to 5V
- A 4×AA battery pack (6V — within SG90 spec)
- A USB power bank with a breakout board

---

## Warning

- **Never** connect external power to the Arduino's 5V pin *while* USB is connected — you can damage the regulator.
- Always power servos from the breadboard rail, not from the Arduino, when using external power.
- The Arduino still needs its own power (USB or barrel jack).
