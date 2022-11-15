#include <Servo.h>
#include <RCSwitch.h>
Servo servo1;
float SVal;
int a;


RCSwitch mySwitch = RCSwitch();

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  mySwitch.enableReceive(0);
  servo1.attach(3);
//servo1.write(180);
    //servo1.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
 if (mySwitch.available()) {
    Serial.println(mySwitch.getReceivedValue());
    
    
    servo1.write(mySwitch.getReceivedValue());
    mySwitch.resetAvailable();
    
  }

}
