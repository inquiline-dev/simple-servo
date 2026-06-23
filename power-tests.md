# Servo Power Consumption Measurements

*Values below are manufacturer typicals for the SG90. Real measurements from my own servo coming soon.*

Measured with a multimeter in series between Arduino 5V and SG90 red wire.

| Condition | Current Draw |
|-----------|-------------|
| Idle (not moving) | ~8 mA |
| Sweeping (0° to 180°, no load) | ~150 mA |
| Stalled (horn held still) | ~360 mA |
| Arduino Uno alone (no servo) | ~45 mA |

*Values are typical for an SG90. Your servo may vary slightly.*

## What this means

- The Arduino's 5V regulator can supply about **400mA** total.
- A single unloaded SG90 sweeping freely is safe — it draws ~150mA, well within limits.
- **If the servo stalls**, it can pull ~360mA. That's close to the limit.
- Running 2 stalled servos (~720mA) will brown out or reset the Arduino.
- **For multiple servos:** use an external 5V supply connected to a breadboard power rail.

## How to measure this yourself

1. Set a multimeter to **DC current (mA)** mode.
2. Connect the **red probe** to Arduino 5V.
3. Connect the **black probe** to the servo's red wire.
4. Current flows through the meter — you'll see the reading change as the servo moves.
5. To measure stall current: gently hold the servo horn so it can't turn, and note the peak reading. **Do this only for 1–2 seconds.**

## Coming soon

- Oscilloscope screenshots of the PWM signal
- Current measurements on a real SG90
