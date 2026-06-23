# getting an sg90 servo to work

ok so i bought this little blue servo like months ago and it just sat in a box because honestly i was kinda intimidated. every tutorial was like "connect the pwm signal" and i didnt even know what pwm meant back then

anyway i figured it out eventually. its actually really simple once you just try it. this is what i wish someone had told me back then

---

parts

you need an arduino uno. and an sg90 servo (the tiny blue one). and a breadboard. and 3 wires. male to male.

thats literally it.

---

how to connect it

the servo has 3 wires coming out of it. brown, red, orange.

brown -> gnd
red -> 5v  
orange -> pin 9

the first time i did this i plugged orange into 5v and red into pin 9 like an idiot and nothing happened. didnt break anything but i sat there confused for like 15 minutes. so yeah dont do that

---

the code

i put the code in a file called sweep_servo.ino. just open it in arduino ide and upload it to the board. the servo will start moving from 0 to 180 degrees and back. like a windshield wiper.

quick breakdown of what the code is doing:

#include <Servo.h> at the top brings in the servo library (built in, no download)
Servo myservo; makes a servo object called myservo
myservo.attach(9); tells it the servo is on pin 9
myservo.write(angle); is the actual command that moves it

the for loop just counts up from 0 to 180 and calls write() each time. then counts back down
delay(15) gives the servo time to physically reach the angle before the next command comes

if you change delay(15) to delay(5) it moves faster but gets kinda jerky. if you do delay(50) its super slow and smooth. try it.

---

other sketches in this repo

i put a bunch of different versions in here because i kept experimenting:

sweep_servo.ino is the basic one. start there
potentiometer_servo.ino lets you control the servo by turning a knob. this one was really satisfying the first time
sweep_microseconds.ino does the same thing but instead of angles you type the pulse width directly in microseconds
sweep_nonblocking.ino uses millis() instead of delay(). this matters later when you need the arduino to do more than one thing at once
two_servos.ino controls two servos at the same time moving in opposite directions
calibrate_servo.ino is something i wrote because my servo couldnt actually reach 0 degrees without making this awful buzzing sound. turns out a lot of sg90s stop at like 5 or 10 degrees on the low end

---

the thing about pulses

i kept reading "pwm" everywhere and didnt get it for ages. here is what it actually means:

the arduino sends a short pulse of electricity to the servo 50 times every second. actually its not exactly 50hz for all servos but for the sg90 it is. anyway the length of that pulse tells the servo where to go. if the pulse is 1 millisecond, thats 0 degrees. 1.5 milliseconds is 90 degrees. 2 milliseconds is 180 degrees.

thats it. the servo library does all the math so you just type an angle and it figures out the pulse for you. but knowing the pulse thing helped me understand why writeMicroseconds() exists and why some servos do weird stuff at the edges of their range.

---

power stuff

i almost fried my arduino once trying to run three servos from the 5v pin. dont do that.

one sg90 on usb power is totally fine. but when a servo is pushing against something (like if you hold the horn still) it pulls way more current. like 360 milliamps. the arduino 5v pin can give about 400 milliamps. so one servo is safe. two stalled servos will reset the arduino or make it act really weird.

if you want to run more than one servo or a bigger servo you need a separate power supply. i wrote down what i learned about that in external-power.md.

oh also if your arduino keeps disconnecting from your computer when the servo moves, thats the power thing. the servo pulls too much and the usb port shuts off for a second. i had this happen with my laptop. using a powered usb hub fixed it.

---

stuff that went wrong for me

- the servo made a buzzing sound but didnt move. the red wire was in 3.3v instead of 5v.
- the serial monitor was totally blank. turns out my usb cable was from a power bank and didnt have data lines. switched cables and it worked.
- servo got really hot once. i had it trying to go to 180 but physically it could only go to like 160 and it was pushing against its own limit the whole time. calibrate_servo.ino helps find the actual limits.
- spent forever debugging once and the wire was just loose in the breadboard. pushed it in properly and everything worked.

---

what im doing

im trying to learn robotics one piece at a time. this servo tutorial is part of a series. so far ive done:

- how to use an ultrasonic sensor (hc-sr04)
- this servo tutorial

next im going to do a joystick module. then combine the ultrasonic and servo to make a little tracker that points at whatever is closest. after that maybe a pan-tilt mount with two servos. eventually a robot arm.

im 15 and i live in iran. writing these tutorials is how i make sure i actually understand what im doing. if i can explain it to someone else then i probably get it.

if something is wrong just open an issue or email me. i probably made mistakes in here somewhere

parham

im putting this then match this with all other files in our repo
