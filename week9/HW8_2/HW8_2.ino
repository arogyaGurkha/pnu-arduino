#include <LiquidCrystal.h>

// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결

byte celsius[8] = {
  B10000, B00011, B00100, B00100, B00100, B00100, B00100, B00011
};

void setup() {
  Serial.begin(9600);
  lcd.createChar(0, celsius);
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.write("Temp: ");
  lcd.setCursor(0, 1);
  lcd.write("Light: ");
  lcd.setCursor(12, 0);
  lcd.write(byte(0));
}

float readTemperature() {
  // Read the value of temp sensor
  int reading = analogRead(55);
  // Calculate voltage from ADC value
  float voltage = reading * 5.0 / 1024.0;
  // Calculate Celsius degree as multiply voltage value of 100
  float temp_C = voltage * 100;
  return temp_C;
}

float readIlluminance() {
  // Read the value of photo-resistor
  int reading = analogRead(56);
  // Calculate voltage from ADC value
  float voltage = reading * 5.0 / 1024.0;
  return voltage;
}

void writeLCD(float temperature, float illuminance) {
  lcd.setCursor(6, 0);
  lcd.print(temperature);
  lcd.setCursor(6, 1);
  lcd.print(illuminance);
}

void loop() {
  writeLCD(readTemperature(), readIlluminance());
  delay(1000);
}
