# servo power measurements

i measured these with a multimeter between the arduino 5v pin and the servo red wire. your servo might be a little different.

| condition | current |
|-----------|---------|
| servo idle (not moving) | about 8 mA |
| servo sweeping (no load) | around 150 mA |
| servo stalled (horn held) | roughly 360 mA |
| arduino uno alone | about 45 mA |

these are from my sg90. cheap clones might pull more or less.

---

what this means

the arduino 5v pin gives about 400mA total. one servo sweeping is fine (150mA). one stalled servo is close to the limit (360mA). two stalled servos will brown out the board.

if you are running more than one servo use an external supply. the external-power.md file explains how.

---

how to measure this yourself

set a multimeter to dc current mode (mA). red probe to arduino 5v. black probe to servo red wire. the current flows through the meter and you can see it change as the servo moves.

to measure stall current gently hold the servo horn so it cant turn and watch the reading. only do this for a second or two because the servo gets hot fast.
