const int pirPin = A0;
const int ledPin = 7;
const int buzzerPin = 6;

bool motionDetected = false;
bool ledState = false;

unsigned long previousBlinkTime = 0;
unsigned long previousSerialTime = 0;

const unsigned long blinkInterval = 250;

void setup() {
  Serial.begin(115200);
  delay(500);

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  noTone(buzzerPin);

  Serial.println("PIR motion detector ready");
}

void loop() {
  motionDetected = digitalRead(pirPin) == HIGH;

  if (motionDetected) {
    unsigned long currentTime = millis();

    // Blink the LED
    if (currentTime - previousBlinkTime >= blinkInterval) {
      previousBlinkTime = currentTime;
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }

    // Sound the buzzer
    tone(buzzerPin, 1000);
  } else {
    digitalWrite(ledPin, LOW);
    ledState = false;
    noTone(buzzerPin);
  }

  // Send a readable status every 500 ms
  if (millis() - previousSerialTime >= 500) {
    previousSerialTime = millis();

    Serial.print("Motion Detected: ");
    Serial.println(motionDetected ? "YES" : "NO");
  }
}
