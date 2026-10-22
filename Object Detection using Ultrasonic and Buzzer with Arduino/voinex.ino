const byte TRIG_PIN = 4;
const byte ECHO_PIN = 5;
const byte BUZZER_PIN = 8;

const float OBSTACLE_DISTANCE_CM = 20.0;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(115200);
  delay(500);

  digitalWrite(TRIG_PIN, LOW);
  noTone(BUZZER_PIN);
}

void loop() {
  // Send a 10-microsecond trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo duration, with a 30 ms timeout
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  bool obstacleDetected = false;
  float distanceCm = 0.0;

  if (duration > 0) {
    // Sound travels approximately 0.0343 cm per microsecond
    distanceCm = (duration * 0.0343) / 2.0;

    if (distanceCm <= OBSTACLE_DISTANCE_CM) {
      obstacleDetected = true;
      tone(BUZZER_PIN, 2000);  // 2 kHz buzzer tone
    } else {
      noTone(BUZZER_PIN);
    }
  } else {
    // No echo received
    noTone(BUZZER_PIN);
  }

  // Telemetry output on one line
  Serial.print("Distance: ");

  if (duration == 0) {
    Serial.print("No Echo");
  } else {
    Serial.print(distanceCm, 1);
    Serial.print(" cm");
  }

  Serial.print(" | Obstacle: ");
  Serial.println(obstacleDetected ? "YES" : "NO");

  delay(500);
}
