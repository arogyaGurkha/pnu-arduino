#include <SPI.h>

int SS_arduino = 53;
int SS_EEPROM = 42;

void setup(void) {
  pinMode(SS_arduino, OUTPUT);
  pinMode(SS_EEPROM, OUTPUT);
  digitalWrite(SS_arduino, HIGH);      // no slave is selected
  digitalWrite(SS_EEPROM, HIGH);

  SPI.begin();
  // lower transmission speed for stable communication
  SPI.setClockDivider(SPI_CLOCK_DIV16);
}

void loop(void) {
  const char *p = "Hello, World\n";
  digitalWrite(SS_arduino, LOW);   //select slave
  for (int i = 0 ; i < strlen(p); i++) { // transfer characters
    SPI.transfer(p[i]);
  }
  digitalWrite(SS_arduino, HIGH);   //release slave
  delay(1000);
}
