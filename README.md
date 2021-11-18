# rc_switch
Attiny 85 RC remote switch code.  Created on arduino ide and deployed on attiny85.  It basically reads the RC receiver pwm value.  Based on conditions, it turns on and off two seperate outputs via MOSFETS.  I did this for a traxxas receiver.  You can also see on the images the modification i made to the traxxas trx4 transmittter in order to enable the hidden third channel and installed a 3 position switch to control the pwm value.


/*
Used as an remote rc swithch.  Reads pwm value from receiver and enables two
seperate outputs to control mosfets for switching on and off devices. any pwm input value under 1200 shuts off
outputs.  When it reads a pwm value greater than 1200 and less than 1800 output 1 turns on.  When greater than 1800
and less than 2100 it keeps output 1 on and turns on output 2.
The declared input and output pins are what i used, and it works on an attiny 85, but you can change as you need. I wired the mosfet source to ground, the gate
to the tiny85 output pin with a 1k resistor, and the source to whatever device your using.  ground switched.  Positive will be connected constant.
Alex Arocha 2021
