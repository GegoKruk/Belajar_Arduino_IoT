#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Definisikan Pin
const int buzzerPin = 9;
const int potPin = A0;

// Inisialisasi LCD I2C (Ganti 0x27 jika alamat LCD Anda berbeda)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();
  lcd.print("Buzzer Freq:");
}

void loop() {
  // 1. Baca nilai Potensiometer (0-1023)
  int potValue = analogRead(potPin);

  // 2. Map nilai 0-1023 ke rentang frekuensi yang bisa didengar (misal 100 Hz - 2000 Hz)
  // Frekuensi Nada (Hertz)
  long frequency = map(potValue, 0, 1023, 100, 2000); 

  // 3. Mainkan nada
  // Durasi 100ms agar terdengar seperti nada yang dipotong-potong
  tone(buzzerPin, frequency, 100); 

  // 4. Tampilkan di LCD
  lcd.setCursor(0, 1);
  lcd.print("Freq: ");
  lcd.print(frequency);
  lcd.print(" Hz   "); // Spasi untuk menghapus sisa angka lama
  
  // Tunda sebentar sebelum loop berikutnya
  delay(50); 
}