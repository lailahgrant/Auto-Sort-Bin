#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int TRIG3 = 11; // Metal bin fullness detection
int ECHO3 = 6;
int TRIG4 = 7; // Other bin fullness detection
int ECHO4 = 2;

int distance3, duration3;
int distance4, duration4;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);
  pinMode(TRIG4, OUTPUT);
  pinMode(ECHO4, INPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
}

void loop() {
  getDistance3(); // Get metal bin fullness distance
  getDistance4(); // Get other bin fullness distance

  // Update LCD based on bin fullness detection
  updateLCD();
  delay(2000); // Add a small delay to avoid excessive looping
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

void updateLCD() {
  bool metalBinFull = (distance3 < 5);
  bool otherBinFull = (distance4 < 5);

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
