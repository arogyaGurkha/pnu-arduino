#include <SPI.h>

char buf[100];
// pos and process_it are defined as volatile in order to read // them from memory for every references because they could be
// updated in an interrupt handling routine

volatile byte pos = 0 ;
volatile boolean process_it = false;

void setup () {
  Serial.begin(9600);

  //MOSI,SCLK,SS don’t need to be set to input
  //MISO also can be omitted because it is not used in this
  //example
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, INPUT);
  pinMode(SCK, INPUT);
  pinMode(SS, INPUT);
  //set transmission speed to master’s one
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  //configure the register for SPI communication
  //SPCR : SPI Control Register
  SPCR |= (1 << SPE);
  SPCR &= ~(1 << MSTR);
  SPCR |= (1 << SPIE);
}

ISR(SPI_STC_vect) {
  byte c = SPDR;
  if (pos < sizeof(buf)) {
    buf[pos++] = c;

    if (c == '\n') {
      process_it = true;
    }
  }
}

void loop() {
  if (process_it) {
    buf[pos] = 0;
    Serial.print(buf);

    pos = 0;
    process_it = false;
  }
}
