void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  // function bawaan arduino, arah ke pin digital
  // param 1 pin led, param 2 value high = menyala
  delay(1500);
  

  digitalWrite(LED_BUILTIN, LOW);
  // function bawaan arduino, arah ke pin digital
  // param 1 pin led, param 2 value high = menyala
  delay(1500);
}
