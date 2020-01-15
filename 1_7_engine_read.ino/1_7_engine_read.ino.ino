#include <stdio.h>   
#include <SoftwareSerial.h> 
//Pin 2 is attached to gear tooth sensor
//Pin 3 is attached to engine rpm
#define drivegear 61;
#define cvtshaft 18;
volatile unsigned long time1b, time2b, time1a, time2a, deltaL, deltaG;
volatile double placehold, vel, last_vel, rpm, last_rpm;
volatile int gateL = 0;
volatile int gateG = 0;
volatile double ;
volatile double ;
volatile double ;
unsigned long timestamp;

void setup(){
  Serial.begin(1000000);
  attachInterrupt(digitalPinToInterrupt(3), ignition, FALLING);
  attachInterrupt(digitalPinToInterrupt(2), rotation, FALLING);
  time1b = micros();
  time1a = micros();
}

void loop(){
  if(millis()%10 == 0){
  if(rpm > (1.5*(last_rpm + 1.0))){rpm = last_rpm;}
  timestamp = micros();
  Serial.print(timestamp);
  Serial.print(",");
  Serial.print(rpm);
  Serial.print(",");
  Serial.println(vel);
  }
}

int rotation(){
if(gateG==0){gateG=1;}
else if(gateG==1){
  time2a = micros();
  last_vel = vel;
  time1a = time2a;
  gateG=0; 
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

double vel_calc(unsigned long timeA, unsigned long timeB){
  deltaG = timeA-timeB;
  
  return placehold;
}
