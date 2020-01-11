#include <stdio.h>   
#include <SoftwareSerial.h> 
//Pin 2 is attached to gear tooth sensor
//Pin 3 is attached to engine rpm
volatile unsigned long time1b;
volatile unsigned long time2b;
volatile unsigned long deltaL;
volatile double placehold;
volatile int gateL = 0;

void setup(){
  Serial.begin(1000000);
  attachInterrupt(digitalPinToInterrupt(3), ignition, FALLING);
  time1b = micros();
  }
void loop(){}
int ignition(){
  
if(gateL==0){gateL=1;}
else if(gateL==1){
  time2b = micros();
  deltaL = time2b-time1b;
  placehold = deltaL/1000000.0;
  placehold = 60.0/(placehold);
  time1b = time2b;
  gateL=0; 
  Serial.println(placehold);
}
}
