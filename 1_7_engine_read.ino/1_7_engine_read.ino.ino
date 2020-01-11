#include <stdio.h>   
#include <SoftwareSerial.h> 
//Pin 2 is attached to gear tooth sensor
//Pin 3 is attached to engine rpm
volatile unsigned long time1b;
volatile unsigned long time2b;
volatile unsigned long deltaL;
volatile double placehold;
volatile int gateL = 0;
volatile double rpm;
volatile double last_rpm;

void setup(){
  Serial.begin(1000000);
  attachInterrupt(digitalPinToInterrupt(3), ignition, FALLING);
  time1b = micros();
  }
void loop(){
  if(millis()%10 == 0){
  if((rpm >5000.0){rpm = last_rpm;}
  Serial.println(rpm);
  }
  }

int ignition(){
if(gateL==0){gateL=1;}
else if(gateL==1){
  time2b = micros();
  last_rpm = rpm;
  rpm = rpm_calc(time2b,time1b);
  time1b = time2b;
  gateL=0; 
}
}

double rpm_calc(unsigned long timeA, unsigned long timeB){
  deltaL = timeA-timeB;
  placehold = deltaL/1000000.0;
  placehold = 60.0/(placehold);
  return placehold;
}
