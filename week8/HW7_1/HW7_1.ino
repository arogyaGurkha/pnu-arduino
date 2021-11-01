int pins_LED[] = {2, 3, 4, 5};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(pins_LED[i], OUTPUT);
  }
}

void loop() {
  int reading = analogRead(56); // Read photoresistor value
  Serial.println(reading);
  int count_led = (reading >> 8) + 1; // 10 bit value to 2 bit value
  for (int i = 0; i < 4; i++) {
    if (reading < 150) digitalWrite(pins_LED[i], LOW); // if reading is less than 150 turn off all LEDs
    else if (i < count_led) digitalWrite(pins_LED[i], HIGH);
    else digitalWrite(pins_LED[i], LOW);
  }
  delay(500);
}
