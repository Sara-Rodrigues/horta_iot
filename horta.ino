#include "DHT.h"
#define LED_VERDE 12
#define LED_VERMELHO 13
#define HGR A1
#define LDR A2
#define DHTPIN A3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(HGR, INPUT);
  pinMode(LDR, INPUT);
}

void loop() {
  if ((analogRead(LDR) < 818.4) && (analogRead(HGR) < 204.6)) {
    while (analogRead(HGR) < 613.7) {
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(LED_VERDE, HIGH);
    }
    Serial.println("Jardim irrigado.");
  } else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    Serial.println("Irrigação inativa.");
  }
}
