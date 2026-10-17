#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

#define SOUND_DO_PIN 2

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  delay(500);

  pinMode(SOUND_DO_PIN, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED initialization failed");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(20, 28);
  display.println("Listening...");
  display.display();

  Serial.println("Sound detection system ready");
}

void loop() {
  int soundDetected = digitalRead(SOUND_DO_PIN);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  if (soundDetected == HIGH) {
    display.setTextSize(1);
    display.setCursor(5, 10);
    display.println("Hey!");

    display.setCursor(5, 28);
    display.println("Welcome to");

    display.setCursor(5, 46);
    display.println("Voinex");

    Serial.println("Sound Detected: YES");
  } else {
    display.setTextSize(1);
    display.setCursor(20, 28);
    display.println("Listening...");

    Serial.println("Sound Detected: NO");
  }

  display.display();
  delay(500);
}
