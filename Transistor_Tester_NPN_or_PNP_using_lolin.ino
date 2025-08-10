#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin definitions for D1 mini
const int basePin = D5;       // Base through 1kΩ resistor
const int collectorPin = D6;  // Collector with 10k pull-up to 3.3V

void setup() {
  Serial.begin(115200);

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.display();
  delay(2000);
  display.clearDisplay();

  // Welcome screen
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Auto Transistor Tester"));
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.println(F("Ready!"));
  display.display();
  delay(2000);

  // Pin setup
  pinMode(basePin, OUTPUT);
  pinMode(collectorPin, INPUT_PULLUP);
}

String testTransistor() {
  // --- Test for NPN ---
  digitalWrite(basePin, LOW);
  delay(50);
  int offState = digitalRead(collectorPin);

  digitalWrite(basePin, HIGH);
  delay(50);
  int onState = digitalRead(collectorPin);

  if (offState == HIGH && onState == LOW) {
    return "NPN OK";
  }

  // --- Test for PNP ---
  digitalWrite(basePin, HIGH);
  delay(50);
  offState = digitalRead(collectorPin);

  digitalWrite(basePin, LOW);
  delay(50);
  onState = digitalRead(collectorPin);

  if (offState == LOW && onState == HIGH) {
    return "PNP OK";
  }

  return "Faulty/No Conn";
}

void loop() {
  String status = testTransistor();

  Serial.println(status);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(F("Time: "));
  display.print(millis() / 1000);
  display.println(F("s"));

  display.setTextSize(2);
  display.setCursor(0, 25);
  display.println(status);

  display.display();
  delay(1000);
}
