// Pins connected to an RGB LED
int RGB_LED[] = {6, 7, 8};
void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(RGB_LED[i], OUTPUT);
  }
}
void loop() {
  // Adjusting Blue color.
  // Turn off Green and Red color
  digitalWrite(RGB_LED[1], HIGH);
  digitalWrite(RGB_LED[2], HIGH);
  for (int i = 255; i >= 0; i--) {
    analogWrite(RGB_LED[0], i);
    delay(10);
  }
  // Adjusting Green color.
  // Turn off Blue and Red color
  digitalWrite(RGB_LED[0], HIGH);
  digitalWrite(RGB_LED[2], HIGH);
  for (int i = 255; i >= 0; i--) {
    analogWrite(RGB_LED[1], i);
    delay(10);
  }
  // Adjusting Red color.
  // Turn off Green and Blue color
  digitalWrite(RGB_LED[0], HIGH);
  digitalWrite(RGB_LED[1], HIGH);
  for (int i = 255; i >= 0; i--) {
    analogWrite(RGB_LED[2], i);
    delay(10);
  }
}
