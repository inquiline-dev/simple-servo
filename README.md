# simple-servo
The easiest possible servo motor tutorial — because everyone deserves to understand what their hands build.


# 🤖 Arduino Basics: Making an SG90 Servo Motor Move

*A project so simple a 10‑year‑old can build it — and understand every piece.*

You will turn an **SG90 micro servo motor** and an **Arduino Uno** into a precise, moving machine.  
No extra power supply, no soldering — just three wires and curiosity.

---

## 🧠 What is a servo motor?

A servo is a smart motor. You don't just turn it on and let it spin. You tell it: *"Go to 45 degrees. Now go to 90 degrees. Now wave."* And it holds that position.

The SG90 is tiny but strong. It can swing from **0° to 180°** and stay exactly where you put it.  
This is the same kind of motor inside robot arms, camera sliders, and remote‑control planes.

**The three wires on the servo:**
- **Brown** – Ground. It completes the circuit.
- **Red** – Power. It drinks from the Arduino's 5V.
- **Orange** – Signal. It listens for position commands.

---

## 🧱 What you need

| Component          | Quantity |
|--------------------|----------|
| Arduino Uno R3     | 1        |
| SG90 micro servo   | 1        |
| Breadboard         | 1        |
| Jumper wires (male‑to‑male) | 3 |

**No soldering. No extra power.**

---

## ⚡ Wiring (text diagram)
Arduino Uno SG90 Servo

GND ------------ Brown wire
5V ------------ Red wire
D9 ------------ Orange wire

That's three wires. The servo gets its power straight from the Arduino's 5V pin.  
One servo is safe — the Arduino can handle it. If you're driving several servos later, you'll need an external supply.

> *Plug the servo into your breadboard so it doesn't dangle. Point the horn away from the wires so it can spin freely.*

---

## 💻 The Code

The full sketch is in the file **`sweep_servo.ino`** in this repository.  
Open it in the Arduino IDE, select your board and port, and click **Upload**.

Then open the **Serial Monitor** (Tools → Serial Monitor, set baud to `9600`).  
You'll see:
ervo ready! Watch it sweep.
Moving to: 0
Moving to: 1
...
Moving to: 180
Moving to: 179
...

The servo horn will smoothly turn from 0° to 180° and back, forever.

---

## 🔬 How the code works (explained for a 10‑year‑old)

1. **`#include <Servo.h>`** — This brings in a helper library that already knows how to talk to servos. It comes with the Arduino IDE, so you don't need to download anything.

2. **`Servo myServo;`** — You create a "driver" called `myServo`. Think of it like giving a name to your remote control.

3. **`myServo.attach(9);`** — You plug that remote into pin 9. Now whatever you tell `myServo` goes to the orange wire.

4. **`myServo.write(angle);`** — The actual command. "Go to this angle and stay there." Inside a `for` loop, `angle` counts from 0 to 180, so the servo moves step by step.

5. **`delay(15);`** — A tiny pause. The servo is fast, but not instant. It needs about 15 milliseconds to physically reach the next angle. Without this delay, it skips and twitches.

6. **Then it sweeps back.** The second `for` loop counts down from 180 to 0, and the servo reverses its journey.

That's the whole magic. No sensors, no cloud — just timing and tiny electric pulses.

---

## 🧪 Try these experiments

- **Change the sweep speed.** Make the delay `5` or `50`. What happens? *Too fast and the servo gets jerky; too slow and it crawls.*
- **Make it wave.** Instead of 0–180, sweep from 45 to 135. Now it looks like it's waving hello.
- **Change the pin.** Move the orange wire to pin 10, change `attach(9)` to `attach(10)` in the code. Does it still work? *(Spoiler: yes — pins 3, 5, 6, 9, 10, 11 are all servo‑ready.)*

---

## 🛠 Troubleshooting

- **Servo buzzes or vibrates but doesn't move.**  
  The USB port may not be giving enough current. Try a powered USB hub, or check that the red wire is firmly in the 5V pin.

- **Servo moves erratically or not at all.**  
  Check the orange wire is on pin 9. If you moved it, open `sweep_servo.ino` and change `attach(9)` to your new pin.

- **Servo gets hot.**  
  It's stalling — something is physically blocking it, or the angle is beyond its range. SG90 usually does 0–180, but some copies stop at 10–170. Stay inside those limits.

- **Nothing happens, and the Serial Monitor is blank.**  
  Make sure the baud rate in the monitor is set to 9600. Also check that your USB cable is data‑capable (some are charge‑only).

---

## 🔜 Next Steps

Now that you can make a servo move to exact angles, imagine controlling it with a joystick or an ultrasonic sensor. That's exactly where we're going next.  
👉 **Next tutorial:** Controlling a servo with a KY-023 joystick module — coming soon.

---

## 🤝 Why this project exists

I'm Parham. I'm 15 and I live in Iran. I built this because the first step into robotics should be so clear that nobody feels stupid.  
If you are a kid who just got their first Arduino, this is for you.  
If you are an adult who was always afraid of wires, this is for you too.

**Knowledge shouldn't be locked behind paywalls or import sanctions. Servos are just tiny muscles waiting for instructions.**

---

## 📄 License

MIT — use this however you like, just keep it open.

---

## 📬 Contact

inquiline.dev@proton.me
