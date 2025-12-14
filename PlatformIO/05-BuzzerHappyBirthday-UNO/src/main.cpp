#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


const int buzzerPin = 9; 

LiquidCrystal_I2C lcd(0x27, 16, 2); 

int melody[] = {
  261, 261, 293, 261, 349, 329,
  261, 261, 293, 261, 392, 349,
  261, 261, 523, 440, 349, 329, 293,
  466, 466, 440, 349, 392, 349
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2
};


void setup() {
  
  lcd.init();
  lcd.backlight();
  
  
  lcd.setCursor(0, 0);
  lcd.print("Selamat HBD");
}


void loop() {
  const int tempo = 110; 
  int msPerBeat = 60000 / tempo;

  int notes = sizeof(melody) / sizeof(melody[0]);

  for (int i = 0; i < notes; i++) {

    int noteDuration = msPerBeat / noteDurations[i]; 

    tone(buzzerPin, melody[i], noteDuration);

    int pauseBetweenNotes = noteDuration * 2.0;

    delay(pauseBetweenNotes);

    noTone(buzzerPin);
  }
  
  delay(3000);
}