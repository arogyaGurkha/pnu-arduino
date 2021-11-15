#include <Wire.h>

#define SLAVE 4

void setup() {

  // Wire library initialization for I2C communication. In case of Master, address is not
  // required.
  Wire.begin();
  Serial.begin(9600);
}
void loop() {
  i2c_communication();
  delay(1000);//wait 1 second
}

void i2c_communication() {   // send data to Slave
  int reading = analogRead(A0);

  Wire.beginTransmission(SLAVE);  // start transmission
  Wire.write(reading >> 8);    // write to buffer
  Wire.write(reading & 0xFF);
  Wire.endTransmission(SLAVE);    // actual data transmission

  Serial.print("I send");
  Serial.println(reading);    // print out data received
}
