# external power for servos

one sg90 on usb power is fine. but if you want to run more than one or a bigger servo you need a separate power supply. i learned this the hard way when my arduino kept resetting.

---

why you need it

| power source | max current | how many sg90s |
|-------------|------------|----------------|
| arduino 5v pin (usb) | about 400mA | 1 or 2 |
| external 5v 2a adapter | 2000mA | like 5 or 6 |
| external 5v 5a | 5000mA | way more than you need |

when a servo stalls (something blocks it) it pulls like 360mA. two stalled servos is 720mA which is more than the arduino can give. the arduino either resets or acts really weird.

---

how to hook it up

external 5v (+) goes to breadboard red rail
external 5v (-) goes to breadboard blue rail

servo red wires go to breadboard red rail
servo brown wires go to breadboard blue rail
breadboard blue rail connects to arduino gnd (important! dont skip this)

if you dont connect the ground from the external supply to the arduino gnd the servo wont understand the signal. ask me how i know lol

---

what to use as a power supply

- 5v 2a wall adapter with barrel jack
- bench power supply set to 5v
- 4 aa batteries in a holder (gives 6v, sg90 can handle it)
- usb power bank with a breakout board

---

warning

dont connect external power to the arduino 5v pin while usb is plugged in. you can damage the regulator. power the servos from the breadboard not the arduino. the arduino still needs its own power (usb or barrel jack)
