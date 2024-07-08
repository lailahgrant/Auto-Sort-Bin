#include <Servo.h>

Servo tap_servo;
int insensor_pin = A0;
int sensor_pin = 4;
int tap_servo_pin =5;
int valI;
int valII;
void setup(){
  pinMode(sensor_pin,INPUT);
  pinMode(insensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);
  
}

void loop(){
  valI = digitalRead(sensor_pin);
  valII =analogRead(insensor_pin);
  if (valI=0)
  {tap_servo.write(0);
  }
  if (valI==1)
  {tap_servo.write(180);
    }
  if (valII==0)
  {tap_servo.write(0);
    }  
  if (valII>=250) 
  {tap_servo.write(180);
  }
}