#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(PCF8574_ADDR_A21_A11_A01, 16, 2);
void setup() {
  Wire.begin();       // aktifkan komunikasi I2C
  lcd.begin(16, 2);   // inisialisasi LCD
  lcd.backlight();    // nyalakan lampu latar
}


void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Halo Kamu!");
  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selamat Pagi!");
  delay(3000);

  lcd.clear();
}

