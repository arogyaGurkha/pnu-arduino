
// Pins connected to LEDs and their respective brightness
int pins_LED[4][4] = {{2, 3, 4, 5}, {0, 0, 0, 0}};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(pins_LED[0][i], OUTPUT);
    int brightness = 25 * i * 255 / 100; // initial brightness in terms of 25%
    analogWrite(pins_LED[0][i], brightness);
    pins_LED[1][i] = brightness;
  }
}

void loop() {
  for (int i = 0; i < 4; i++) { // cycle through the leds
    pins_LED[1][i] += 5; // increment brightness by 5

    analogWrite(pins_LED[0][i], pins_LED[1][i]);

    if (pins_LED[1][i] >= 255) { // turn of the leds completely once it reaches 255
      pins_LED[1][i] = 0;
    }

    delay(10); // small delay to enhance the fade effect
  }
}
