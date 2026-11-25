const int RELAY_PIN = 8;
const int IR_PIN = 2;

void setup() {
  Serial.begin(115200);
  delay(500);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(IR_PIN, INPUT);

  // Active-low relay: HIGH means OFF
  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
  int sensorValue = digitalRead(IR_PIN);
  bool objectDetected = (sensorValue == LOW);

  // Active-low relay: LOW means ON
  digitalWrite(RELAY_PIN, objectDetected ? LOW : HIGH);

  Serial.print("Object Detected: ");
  Serial.println(objectDetected ? "YES" : "NO");

  Serial.print("Pump: ");
  Serial.println(objectDetected ? "ON" : "OFF");

  delay(500);
}
