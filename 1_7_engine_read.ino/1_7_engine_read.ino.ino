#include <stdio.h>   
#include <SoftwareSerial.h> 
//Pin 2 is attached to gear tooth sensor
//Pin 3 is attached to engine rpm
volatile unsigned long time1a;
volatile unsigned long time2a;
volatile unsigned long time1b;
volatile unsigned long time2b;
volatile unsigned long deltaA;
volatile unsigned long deltaB;
volatile unsigned long deltaL;
volatile double placehold;
volatile int gateL = 0;

void setup(){
  Serial.begin(1000000);
  attachInterrupt(digitalPinToInterrupt(3), ignition, FALLING);
  time1a = micros();
  time1b = micros();
  
  }
  
void loop(){
  //Serial.println(deltaA);
  //while(gateA != 1){Serial.println(deltaA);flag_reset();}

  }

int ignition(){
  
if(gateL==0){
//  deltaA = read_A();
gateL=1;
}
else if(gateL==1){
  time2b = micros();
  deltaL = time2b-time1b;
  placehold = deltaL/1000000.0;
  placehold = 60.0/(placehold);
  Serial.println(placehold);
  time1b = time2b;
  gateL=0; 
}
}
  
int read_A(){
  /*
time2a = micros();
deltaL = time2a-time1a;
time1a = time2a;*/
gateL++;
return 0;
  }

int read_B(){
time2b = micros();
deltaL = time2b-time1b;
time1b = time2b;
return deltaL;
  }

unsigned long math_stuff(unsigned long fir_meas, unsigned long sec_meas){
gateL=0;
placehold = (fir_meas+sec_meas)/1000000;
placehold = 1/(60*placehold);
return placehold;
}
