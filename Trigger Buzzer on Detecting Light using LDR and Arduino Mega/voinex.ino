const uint8_t LDR_PIN = A0;
const uint8_t BUZZER_PIN = 8;

// Change to HIGH if the LDR module outputs HIGH when light is detected.
const uint8_t LIGHT_ACTIVE_LEVEL = LOW;

void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Keep buzzer off at startup
  digitalWrite(BUZZER_PIN, LOW);

  Serial.begin(115200);
  delay(500);
}

void loop() {
  int ldrState = digitalRead(LDR_PIN);
  bool lightDetected = (ldrState == LIGHT_ACTIVE_LEVEL);

  if (lightDetected) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  Serial.print("LDR DO State: ");
  Serial.println(ldrState == HIGH ? "HIGH" : "LOW");

  Serial.print("Light Detected: ");
  Serial.println(lightDetected ? "YES" : "NO");

  Serial.print("Buzzer: ");
  Serial.println(lightDetected ? "ON" : "OFF");

  delay(500);
}
