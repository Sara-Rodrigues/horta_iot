// botao.ino
#define LED 13
#define BUTTON 8

void setup() {
  pinMode(BUTTON, INPUT);
}

void loop() {
  digitalWrite(LED, digitalRead(BUTTON));
  delay(1000);
}
