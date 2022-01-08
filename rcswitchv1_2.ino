/*
Used as an remote rc swithch.  Reads pwm value from receiver and enables two
seperate outputs to control mosfets for switching on and off devices. any pwm input value under 1200 shuts off
outputs.  When it reads a pwm value greater than 1200 and less than 1800 output 1 turns on.  When greater than 1800
and less than 2100 it keeps output 1 on and turns on output 2.
The declared input and output pins are what i used, and it works on an attiny 85, but you can change as you need. I wired the mosfet source to ground, the gate
to the tiny85 output pin with a 1k resistor, and the source to whatever device your using.  ground switched.  Positive will be connected constant.
V1.2
Alex Arocha 2021
*/

static int pwm_pin = 2;  //declare pin which reads pwm value
static int out1 = 3;   //declare pin for output 1
static int out2 = 4;   //declare pin for output 2
static int modepin = 1; //declare mode pin
int pwm_value = 0;  //stores value for current pwm value
int modestate = 0;  //int for state of mode switch

void setup() {
  
  pinMode(pwm_pin, INPUT);  //set pwm pin to input
  pinMode(out1, OUTPUT);  //set output1 to output
  pinMode(out2, OUTPUT);  //set output2 to output
  pinMode(modestate, INPUT);  //set mode switch pin to input

}

void loop() {

  modestate = digitalRead(modepin); //read state of mode switch

  //if mode switch is low
if (modestate == 0){
  pwm_value = pulseIn(pwm_pin, HIGH);

  while (pwm_value < 1200){
    digitalWrite(out1,LOW);
    digitalWrite(out2,LOW);
    pwm_value = pulseIn(pwm_pin, HIGH);
    }
  
  while ((pwm_value >1200) && (pwm_value <1800)){
    digitalWrite(out1,HIGH);
    digitalWrite(out2,LOW);
    pwm_value = pulseIn(pwm_pin, HIGH);
    }
  
  while ((pwm_value >1800) && (pwm_value <2100)){
    digitalWrite(out1,LOW);
    digitalWrite(out2,HIGH);
    pwm_value = pulseIn(pwm_pin, HIGH);
    }
  }

  //if mode switch is high
else{
pwm_value = pulseIn(pwm_pin, HIGH);
  
  while (pwm_value < 1200){
    digitalWrite(out1,LOW);
    digitalWrite(out2,LOW);
    pwm_value = pulseIn(pwm_pin, HIGH);
    }
  
  while ((pwm_value >1200) && (pwm_value <1800)){
    digitalWrite(out1,HIGH);
    digitalWrite(out2,LOW);
    pwm_value = pulseIn(pwm_pin, HIGH);
    }
  
  while ((pwm_value >1800) && (pwm_value <2100)){
    digitalWrite(out1,HIGH);
    digitalWrite(out2,HIGH);
    pwm_value = pulseIn(pwm_pin, HIGH);
    }
}
    
}
