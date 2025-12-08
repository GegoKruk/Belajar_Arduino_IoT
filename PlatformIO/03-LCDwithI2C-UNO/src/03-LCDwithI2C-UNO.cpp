#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Wire.begin();       // aktifkan komunikasi I2C
  lcd.init();         // inisialisasi LCD
  lcd.backlight();    // nyalakan lampu latar
}


void loop() {
  lcd.setCursor(0, 0);   // kolom 0, baris 0 → pojok kiri atas
  lcd.print("Halo Kamu!");
  delay(3000);

  lcd.setCursor(0, 1);   // kolom 0, baris 0 
  lcd.print("Selamat Siang!");
  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0);   // kolom 0, baaris 1 
  lcd.print("Semoga Sukses!");
  delay(3000);

  lcd.setCursor(5, 1);   // kolom 5, baris 1 → tengah bawah
  lcd.print("Keren Keren");
  delay(3000);

  lcd.clear();
}

