#include <SoftwareSerial.h>

SoftwareSerial m_Serial(4,5);

void setup() {
  m_Serial.begin(9600);
  Serial.begin(9600);
}

float readTemperature() {
  int reading = analogRead(54); // A0
  float voltage = reading * 5.0 / 1024.0;
  Serial.print(voltage);
  Serial.print(" V : ");

  float temp_c = voltage * 100;
  Serial.print(String(temp_c) + '\n');
  return temp_c;
}

void loop() {
  m_Serial.print(String(readTemperature()) + '\n');
  delay(1000);
}
