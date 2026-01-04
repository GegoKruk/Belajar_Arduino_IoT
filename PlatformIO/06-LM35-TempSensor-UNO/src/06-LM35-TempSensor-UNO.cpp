#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
int sensorLM35 = A0;

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Test Masuk");

  delay(2000);     
  
  lcd.clear();
}

void loop() {
  // Baca nilai ADC (0–1023)
  int sensorValue = analogRead(sensorLM35);
    
  // Konversi ke tegangan (0–5V)
  float voltage = sensorValue * (5.0 / 1024.0);
    
  // Konversi ke suhu (°C)
  float temperature = voltage * 100;

  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(temperature);

  delay(5000);       // update tiap 1 detik
}
