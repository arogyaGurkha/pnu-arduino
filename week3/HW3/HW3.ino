int pins[] = {2, 3, 4, 5};

void setup() {

  Serial.begin(9600);
  for (int i = 0; i < 4; ++i) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  };
}

void loop() {

  for (int index = 0; index < 6; index++) { // We use 6 because we want a sequence of 6 numbers : 1, 3, 7, 15, 7, 3
    int pattern = 1, shift;

    if (index < 4) shift = index;
    else shift = 6 - index;

    for (int i = 0; i < shift; i++) {
      pattern = (pattern << 1) | 0x01; // Bitshift and add 1
    }

    if (pattern == 0b0001) { // If 0001, first pin is set to high and the rest to low (first pin is always set to high)
      digitalWrite(pins[0], HIGH);
      for (int pin = 1; pin < 4; ++pin)
        digitalWrite(pins[pin], LOW);
    }

    if (pattern == 0b1111) { // If 1111, all pins are set to high
      for (int pin = 0; pin < 4; ++pin)
        digitalWrite(pins[pin], HIGH);
    }

    if (pattern == 0b0111) { // If 0111, all but the last pin are set to high
      for (int pin = 0; pin < 3; ++pin)
        digitalWrite(pins[pin], HIGH);
      digitalWrite(pins[3], LOW);
    }

    if (pattern == 0b0011) { // If 0011, first two pins are set to high and last two to low
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], HIGH);
      digitalWrite(pins[2], LOW);
      digitalWrite(pins[3], LOW);
    }

    delay(500); // delay so it doesnt burn your eyes
  }
}
