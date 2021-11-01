
#include <pitches.h>

int speakerPin = 57; // Pin connected
int melody[] = { // Notes in a melody
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4,
};
int noteDuration = 4; // Quarter note

void setup() {
}

void loop() {
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {
    // Calculate the length of nores
    int noteLength = 1000 / noteDuration;
    // Play tones
    tone(speakerPin, melody[thisNote], noteLength);
    delay(noteLength);
    noTone(speakerPin); // Stop playing tone
  }
  while (true);
}
