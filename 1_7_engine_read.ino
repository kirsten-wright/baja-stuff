#include <stdio.h>   
#include <SoftwareSerial.h> 
//Pin 2 is attached to gear tooth sensor
//Pin 3 is attached to engine rpm
volatile unsigned long time1;
volatile unsigned long time2;
volatile unsigned long deltaA;
volatile int gateA = 0;
unsigned long timelast;

void setup(){
  Serial.begin(19200);
  attachInterrupt(digitalPinToInterrupt(3), ignition, RISING);
  time1 = micros();
  }
  
void loop(){
  //Serial.println(deltaA);
  //while(gateA != 1){Serial.println(deltaA);flag_reset();}

  }
int ignition(){
time2 = micros();
deltaA = time2-time1;
Serial.println(deltaA);
time1 = time2;
  }

void flag_reset(){
gateA=0;
  
}
