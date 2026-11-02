#include <Servo.h>

Servo myServo;

const int irSensorPin = A8;
const int servoPin = 7;

void setup() {
  Serial.begin(115200);
  delay(500);

  pinMode(irSensorPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(0);  // Initial position
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);

  if (sensorValue == LOW) {
    // Object detected
    myServo.write(90);
    Serial.print("Object Detected: ");
    Serial.println("YES");
  } else {
    // No object detected
    myServo.write(0);
    Serial.print("Object Detected: ");
    Serial.println("NO");
  }

  delay(500);
}
