#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;

Servo headServo;

void initDistanceMeasurement() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
}

int getDistance() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Set the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the echoPin, returns the sound wave travel time in microseconds
  int duration = pulseIn(echoPin, HIGH);
  // Calculate the distance
  return duration*0.034/2;
}

initServo() {
    headServo.attach(11);
}

void setup() {
    initDistanceMeasurement();
    initServo();
    Serial.begin(9600); // Start the serial communication
}

void loop() {

    for (int i = 0; i <= 90; i+= 5) {
        headServo.write(i);
        delay(500);
        Serial.print(getDistance());
        Serial.print(",");
        Serial.println(i);
    }
    delay(1000);
    for (int i = 90; i <= 180; i+= 5) {
        headServo.write(i);
        delay(500);
        Serial.print(getDistance());
        Serial.print(",");
        Serial.println(i);
    }
    delay(1000);
    
    for (int i = 180; i >= 0; i-= 5) {
        headServo.write(i);
        delay(500);
        Serial.print(getDistance());
        Serial.print(",");
        Serial.println(i);
    }
    /**/
}