#include <Servo.h>

// Define servo motor objects
Servo Pipe_Servo;  // Servo motor for moving the initial bin
Servo Gate_Servo;  // Servo motor for opening and closing the drop mechanism

// Define sensor pins
const int inductiveSensorPin = A0;    // Inductive sensor pin
const int capacitiveSensorPin = 3;    // Capacitive sensor pin

// Define servo motor control positions
const int centerPosition = 90;       // Position for center (initial) bin
const int plasticPosition = 0;       // Position for plastic bin
const int metalPosition = 180;       // Position for metal bin
const int otherPosition = 45;        // Position for other materials bin
const int dropOpenPosition = 90;     // Position to open the drop mechanism
const int dropClosePosition = 0;     // Position to close the drop mechanism

int i = 0;
int n = 0;
long duration;
int distance;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(inductiveSensorPin, INPUT);
  pinMode(capacitiveSensorPin, INPUT);

  // Attach servos to the pins
  Pipe_Servo.attach(5);  // Adjust pin number based on your setup
  Gate_Servo.attach(6);  // Adjust pin number based on your setup

  // Set initial position of the servos
  Pipe_Servo.write(centerPosition);
  Gate_Servo.write(dropClosePosition);

  // Wait for servos to initialize
  delay(500);
}

void loop() {
  // Check object presence
  int inductiveValue = analogRead(inductiveSensorPin);
  int capacitiveValue = digitalRead(capacitiveSensorPin);
  
  Serial.print("Inductive Sensor: ");
  Serial.print(inductiveValue);
  Serial.print(" | Capacitive Sensor: ");
  Serial.println(capacitiveValue);

  // Delay before checking again
  delay(1000);

  if (inductiveValue >= 250) {
    // Object detected as metal
    moveAndDrop(metalPosition);
  } else if (capacitiveValue == HIGH) {
    // Object detected as plastic
    moveAndDrop(plasticPosition);
  } else {
    // Object detected as other material
    moveAndDrop(otherPosition);
  }

  // Delay before checking again
  delay(1000);
}

// Function to move initial bin and drop object
void moveAndDrop(int position) {
  Pipe_Servo.write(position);  // Move initial bin to plastic/metal/other bin position
  delay(1000);  // Allow time for servo to reach the position
  Gate_Servo.write(dropOpenPosition);  // Open the drop mechanism
  delay(1000);  // Keep the bin open for 1 second
  Gate_Servo.write(dropClosePosition);  // Close the drop mechanism
  delay(500);  // Allow time for drop mechanism to close

  // Move back to center position
  Pipe_Servo.write(centerPosition);
  delay(500);  // Optional delay after returning to center position
}
