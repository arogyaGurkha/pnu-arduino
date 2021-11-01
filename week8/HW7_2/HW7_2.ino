#include <pitches.h>

int speakerPin = 57;
int vResistor = A2;
int melody[] = { // scale
  0, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};
int noteDuration = 4; // Quarter note
int noteLength = 1000 / noteDuration;

void setup() {
  Serial.begin(9600);
  pinMode(vResistor, INPUT);
}

void loop() {
  int reading = analogRead(vResistor); // potentiometer
  Serial.println(reading);

  int key = map(reading, 0, 1023, 0, 8); // 
  tone(speakerPin, melody[key], noteLength);
}
