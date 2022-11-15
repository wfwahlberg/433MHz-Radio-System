#include <Servo.h>
#include <RCSwitch.h>
Servo servo1;
int Val = 7;
int a;
int JoyVal;
float SVal;


RCSwitch mySwitch = RCSwitch();

void setup() {
  // put your setup code here, to run once:

  pinMode(A0,INPUT);

Serial.begin(9600);
mySwitch.enableTransmit(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  
JoyVal = analogRead(A0);
SVal = (180./1023.)*JoyVal;
//Val = map(Val,0,1024,0,180);
mySwitch.send(SVal,30);
  

}
