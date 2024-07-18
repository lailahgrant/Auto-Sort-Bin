    #include<Servo.h>
    Servo servo1;
    Servo servo2;
    int TRIG1 = 4;
    int ECHO1 = 5;
    int TRIG2 = 11;
    int ECHO2 = 12;
    int sensor = 8;
    int distance1, duration1, value, distance2, duration2;
    void setup() {
      // put your setup code here, to run once:
    pinMode(sensor, INPUT);
    pinMode(TRIG1, OUTPUT);
    pinMode(ECHO1, INPUT);
    pinMode(TRIG2, OUTPUT);
    pinMode(ECHO2, INPUT);
    Serial.begin(9600);
    servo1.attach(9);
    servo2.attach(3);
    servo1.write(90);
    servo2.write(30);
    }

    void loop() {
      // put your main code here, to run repeatedly:
      getMetal();
      getDistance1();
      getDistance2();
      delay(200);
      if (distance1 < 12 && value == 1){
        servo1.write(0);
        delay(2000);
        servo2.write(150);
          }
      else if (distance1 < 12 && value == 0){
        servo1.write(180);
        delay(2000);
        servo2.write(150);
          }

      else {
          servo1.write(90);
          servo2.write(30);
      } 
    }

    int getDistance1(){
      digitalWrite(TRIG1,HIGH);
      delay(2);
      digitalWrite(TRIG1,LOW);
      duration1 = pulseIn(ECHO1,HIGH);
      distance1 = (duration1*0.034)/2;
      Serial.print("Distance1: ");
      Serial.println(distance1);
      return distance1;
    }

    int getDistance2(){
      digitalWrite(TRIG2,HIGH);
      delay(2);
      digitalWrite(TRIG2,LOW);
      duration2 = pulseIn(ECHO2,HIGH);
      distance2 = (duration2*0.034)/2;
      Serial.print("Distance2: ");
      Serial.println(distance2);
      return distance2;
    }

    void getMetal(){
      value = digitalRead(sensor);
      Serial.print("Sensor Value: ");
      Serial.println(value);
      delay(500);
    }
