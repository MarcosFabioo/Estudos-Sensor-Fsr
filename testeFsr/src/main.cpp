#include <Arduino.h>
#define FSR_PIN A0
#define LED_PIN D2
#define LED_PIN2 D4

void setup()
{
  Serial.begin(115200);
  pinMode(FSR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop()
{
  int sensorValue = analogRead(FSR_PIN);
  float voltage = sensorValue * (1.0 / 1023.0);

  if (sensorValue > 30)
  {
    Serial.println("Pressionado\n");
    Serial.print("Valor bruto: ");
    Serial.print(sensorValue);
    Serial.print(" | Tensão: ");
    Serial.println(voltage);

    if (sensorValue <= 400)
    {
      digitalWrite(LED_PIN, HIGH);
    }

    if (sensorValue > 400)
    {
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN2, HIGH);
    }
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN2, LOW);
  }
  delay(100);
}