#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Define the pins for the servos and sensors
Servo servo1;
Servo servo2;

int TRIG1 = 4;
int ECHO1 = 5;
int TRIG2 = 11;
int ECHO2 = 12;
int sensor = 8;

int distance1, duration1, value, distance2, duration2;

// Define the pins for the ultrasonic sensors for bin fullness detection
int TRIG3 = 11; // Metal bin fullness detection
int ECHO3 = 6;
int TRIG4 = 7; // Other bin fullness detection
int ECHO4 = 2;

int distance3, duration3;
int distance4, duration4;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the pins for the sensor and ultrasonic sensors
  pinMode(sensor, INPUT);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);
  pinMode(TRIG4, OUTPUT);
  pinMode(ECHO4, INPUT);

  // Initialize serial communication and attach the servos
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(3);
  servo1.write(90);
  servo2.write(30);

  // Initialize the LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Get sensor readings
  getMetal();
  getDistance1();
  getDistance2();
  getDistance3(); // Get metal bin fullness distance
  getDistance4(); // Get other bin fullness distance

  delay(200);

  // Control servos based on the distance and sensor readings
  if (distance1 < 6 && value == 1) {
    servo1.write(0);
    delay(2000);
    servo2.write(150);
  } else if (distance1 < 6 && value == 0) {
    servo1.write(180);
    delay(2000);
    servo2.write(150);
  } else {
    servo1.write(90);
    servo2.write(30);
  }

  // Update the LCD display based on the bin fullness detection
  updateLCD();
  delay(500); // Add a small delay to avoid excessive looping
}

int getDistance1() {
  digitalWrite(TRIG1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1, LOW);
  duration1 = pulseIn(ECHO1, HIGH);
  distance1 = (duration1 * 0.034) / 2;
  Serial.print("Distance1: ");
  Serial.println(distance1);
  return distance1;
}

int getDistance2() {
  digitalWrite(TRIG2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);
  duration2 = pulseIn(ECHO2, HIGH);
  distance2 = (duration2 * 0.034) / 2;
  Serial.print("Distance2: ");
  Serial.println(distance2);
  return distance2;
}

int getDistance3() {
  digitalWrite(TRIG3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG3, LOW);
  duration3 = pulseIn(ECHO3, HIGH);
  distance3 = (duration3 * 0.034) / 2;
  Serial.print("Distance3 (Metal bin): ");
  Serial.println(distance3);
  return distance3;
}

int getDistance4() {
  digitalWrite(TRIG4, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG4, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG4, LOW);
  duration4 = pulseIn(ECHO4, HIGH);
  distance4 = (duration4 * 0.034) / 2;
  Serial.print("Distance4 (Other bin): ");
  Serial.println(distance4);
  return distance4;
}

void getMetal() {
  value = digitalRead(sensor);
  Serial.print("Sensor Value: ");
  Serial.println(value);
}

void updateLCD() {
  bool metalBinFull = (distance3 < 8);
  bool otherBinFull = (distance4 < 8);

  if (metalBinFull && otherBinFull) {
    lcd.setCursor(0, 0);
    lcd.print("Both bins full  ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  } else if (metalBinFull) {
    lcd.setCursor(0, 0);
    lcd.print("Metal bin full  ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  } else if (otherBinFull) {
    lcd.setCursor(0, 0);
    lcd.print("Other bin full  ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("RECYCLE         ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }
}
