# Controlling an SG90 Servo Motor with Arduino

ok so i bought this little blue servo like 3 months ago and honestly it just sat in my drawer. every tutorial i found started talking about PWM and pulse widths before i even knew which wire was which. i felt dumb. turns out it's actually really simple once you just wire it and upload something.

this tutorial will get you from zero to a working servo sweep in about 10 minutes. no prior knowledge assumed. just the wire, the code, and why it works.

---

## what you need

| part | notes |
|------|-------|
| arduino uno r3 | or compatible |
| sg90 micro servo | the tiny blue one |
| breadboard | any size |
| 3 male-to-male jumper wires | |

no soldering. no extra power supply needed for one servo on USB power.

---

## wiring

the servo has 3 wires coming out of it: brown, red, orange.

- brown → GND on the arduino
- red → 5V on the arduino
- orange → pin 9

the first time i did this i swapped the red and orange wires. nothing broke but the servo just sat there completely still. i stared at it for like 10 minutes before i realized. brown=GND, red=5V, orange=signal. don't mix them up.

![wiring diagram](wiring-diagram.png)

---

## the code

the main sketch is called `sweep_servo.ino`. open it in the arduino ide, select your board and port, and click upload. the servo will start sweeping from 0 to 180 degrees and back, forever.

in short: the code uses the built-in Servo library, attaches the servo to pin 9, and then uses a for loop to count from 0 to 180 and back, calling `write(angle)` each time. a small `delay(15)` gives the servo time to physically reach each position before the next command comes.

this repo has a few different sketches:

- `sweep_servo.ino` — basic sweep. start here.
- `potentiometer_servo.ino` — control the servo with a knob. this one was satisfying ngl.
- `sweep_microseconds.ino` — raw pulse width control instead of angles.
- `sweep_nonblocking.ino` — uses millis() instead of delay(). important for real robots.
- `two_servos.ino` — two servos moving in opposite directions.
- `calibrate_servo.ino` — helps find your servo's actual limits. mine buzzed like crazy at 0 degrees.

---

## how it works

**what is a servo?** a regular DC motor just spins when you give it power. a servo is different — you tell it an exact angle and it goes there and holds it. like telling someone "point to 3 o'clock" instead of "just spin around."

**how does it know the angle?** the arduino doesn't send degrees. it sends pulses — tiny bursts of electricity, 50 times per second. the length of each pulse tells the servo where to go: 1 millisecond means 0 degrees, 1.5 milliseconds means 90 degrees, 2 milliseconds means 180 degrees. the servo has a tiny circuit inside that measures the pulse length and moves until it matches. this is called PWM (pulse width modulation).

**why the delay?** the servo is fast but not instant. it needs about 15 milliseconds to physically reach the next angle. without the delay, you're sending new commands before the old ones finish and the movement gets jerky and unpredictable.

---

## power warning

one sg90 on USB power is fine. but when a servo stalls (like if something blocks it) it can pull around 360mA. the arduino 5V pin gives about 400mA total. so one stalled servo is close to the limit. two stalled servos will reset the arduino or make it act really weird.

if you want to run multiple servos or bigger ones, you need an external power supply. i wrote down what i learned about that in [external-power.md](external-power.md). there are also actual current measurements in [power-tests.md](power-tests.md).

oh also — if your arduino keeps disconnecting from your computer when the servo moves, that's the power thing. the servo pulls too much and the USB port shuts off for a second. my laptop did this. a powered USB hub fixed it.

---

## problems i hit

- **servo buzzes but doesn't move:** the red wire was in 3.3V instead of 5V. the servo needs 5V to operate. check your wiring.
- **serial monitor is blank:** my USB cable was from a power bank and didn't have data lines. try a different cable.
- **servo gets really hot and makes a grinding noise:** it's trying to go past its physical limit. my servo couldn't actually reach 180 degrees — it stopped at about 160. use `calibrate_servo.ino` to find your servo's real limits.
- **servo moves erratically or twitches:** the signal wire was loose in the breadboard. pushed it in properly and everything worked. also check your baud rate is set to 9600.
- **arduino resets when the servo starts moving:** the servo is pulling too much current. see the power warning above.

---

## next steps

this is part of a series i'm building. so far i've done:
- ultrasonic sensor (hc-sr04)
- servo motor (this one)

next is the joystick module, then combining the ultrasonic and servo to make a motion tracker that points at the nearest object.

---

## why this exists

i'm parham. i'm 15 and i live in iran. building stuff here under sanctions means you can't just order whatever you want — you work with what you have and you share what you learn. i write these tutorials because knowledge shouldn't be behind paywalls or sanctions. if you're a kid who just got their first arduino and you're sitting there feeling lost — this is for you. seriously.

---

## about me

i'm parham. i'm 15 and i live in iran. i write these tutorials because knowledge shouldn't be locked behind paywalls or sanctions. if you're just starting out and you feel lost — this is for you. seriously.

---

mit license — use this however you want, just keep it open.
contact: inquiline.dev@proton.me

---

ok that's it. go make something move. if it breaks open an issue. — parham
