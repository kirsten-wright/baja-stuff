#include <stdio.h>   
#include <SoftwareSerial.h> 
//Pin 2 is attached to gear tooth sensor
//Pin 3 is attached to engine rpm
#define drivegear 61;
#define cvtshaft 18;
volatile unsigned long time1b;
volatile unsigned long time2b;
volatile unsigned long deltaL;
volatile double placehold;
volatile int gateL = 0;
volatile double gear_vel;
volatile double rpm;
volatile double last_rpm;
unsigned long timestamp;

void setup(){
  Serial.begin(1000000);
  attachInterrupt(digitalPinToInterrupt(3), ignition, FALLING);
  time1b = micros();
}

void loop(){
  if(millis()%10 == 0){
  if((rpm > 1.5*(last_rpm + 1.0)){rpm = last_rpm;}
  timestamp = micros();
  Serial.println("%lu,%lf,%lf",timestamp,rpm,gear_vel);
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

/*
int gear(){
if(gateL==0){gateL=1;}
else if(gateL==1){
  time2b = micros();
  last_rpm = rpm;
  rpm = rpm_calc(time2b,time1b);
  time1b = time2b;
  gateL=0; 
  }
}
*/
