#include <Arduino.h>

int ledRed = 3;      // PWM pin
int ledGreen = 5;    // PWM pin
int ledYellow = 6;   // PWM pin
int potPin = A0;     // Potensiometer input

void setup() {
  Serial.begin(9600);

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void loop() {
  // Baca nilai potensiometer (0–1023)
  int potValue = analogRead(potPin);

  // Mapping ke range PWM (0–255)
  int brightness = map(potValue, 0, 1023, 0, 255);

  // Debug ke Serial Monitor
  Serial.print("Pot value: ");
  Serial.print(potValue);
  Serial.print(" | Brightness: ");
  Serial.println(brightness);

  // Atur brightness ketiga lampu
  analogWrite(ledRed, brightness);
  analogWrite(ledGreen, brightness);
  analogWrite(ledYellow, brightness);

  delay(20); // biar smooth
}
