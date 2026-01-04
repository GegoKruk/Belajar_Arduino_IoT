#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define buzzer 2

LiquidCrystal_I2C lcd(0x27, 16, 2); 
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  SPI.begin();
  mfrc522.PCD_Init();
  
  lcd.setCursor(0, 0);
  lcd.print("Halo!");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Tempel Kartu");
}

void beep(int durasi) {
  digitalWrite(buzzer, HIGH);
  delay(durasi);
  digitalWrite(buzzer, LOW);
}

void loop() {
  // Cek apakah ada kartu
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return; // tidak ada kartu, keluar loop
  } 

  if (!mfrc522.PICC_ReadCardSerial()){
    return; // gagal baca kartu, keluar loop
  }

  // Kalau sampai sini berarti kartu berhasil dibaca → bunyikan buzzer
  beep(300);

  // Tampilkan UID di LCD dan Serial
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Kartu OK");

  Serial.print("UID Kartu: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tempel Kartu");
}
