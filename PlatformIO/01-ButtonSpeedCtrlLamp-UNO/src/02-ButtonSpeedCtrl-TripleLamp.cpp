#include <Arduino.h>

#define ledRed 2
#define ledGreen 4
#define ledYellow 7
#define buttonSpeedUp 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonSpeedUp, INPUT);
  digitalWrite(buttonSpeedUp, HIGH);

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void speedMode(int option){
  if (option == 1){
    digitalWrite(ledRed, HIGH);
    delay(100);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    delay(100);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, HIGH);
    delay(100);
    digitalWrite(ledYellow, LOW);
  } else {
    digitalWrite(ledRed, HIGH);
    delay(1000);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    delay(1000);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, HIGH);
    delay(1000);
    digitalWrite(ledYellow, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int isButtonSpeedPressed = digitalRead(buttonSpeedUp);

  if(isButtonSpeedPressed == 0){
    Serial.println("Haloo kawan");
    speedMode(1);
  } else {
    speedMode(0);
  }
}
