void setup() {
  Serial.begin(9600);
}

void readTemperature() {
  // Read the value of temp sensor
  int reading = analogRead(55);
  // Calculate voltage from ADC value
  float voltage = reading * 5.0 / 1024.0;
  Serial.print(voltage);
  Serial.print("V: ");
  // Calculate Celsius degree as multiply voltage value of 100
  float temp_C = voltage * 100;
  Serial.print(temp_C);
  Serial.print(" C, ");
  // Calculate Fahrenheit degree
  float temp_F = (temp_C  * 9.0 / 5.0) + 32;
  Serial.print(temp_F);
  Serial.println("F");
}

void readIlluminance() {
  // Read the value of photo-resistor
  int reading = analogRead(56);
  Serial.print("ADC : ");
  Serial.print(reading);
  // Calculate voltage from ADC value
  float voltage = reading * 5.0 / 1024.0;
  Serial.print(", Voltage : ");
  Serial.println(voltage);
}

void loop() {
  readTemperature();
  readIlluminance();
  delay(500);
}
