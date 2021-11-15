#include <Wire.h>

#define SLAVE 4

void setup() {

  // Wire library initialization for I2C communication. In case of Slave, address should
  // be specified
  Wire.begin(SLAVE);

  //register a handling function for receiving data from Master
  Wire.onReceive(receiveFromMaster);

  Serial.begin(9600);
}
void loop() {
}
void receiveFromMaster(int bytes) {

  byte r1 = Wire.read();              //read 2byte integer
  byte r2 = Wire.read();

  int value = (r1 << 8) + r2;

  Serial.print("I got");
  Serial.println(value);
}
