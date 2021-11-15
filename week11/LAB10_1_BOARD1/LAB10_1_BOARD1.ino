#include <SoftwareSerial.h>
//SoftwareSerial(RX,TX), cross connected with pins of Mega2560(No.2)
SoftwareSerial mySerial(4, 5);
int button_pin = 2;
boolean previous_state = false;

void setup() {
  mySerial.begin(9600);     // serial connection with Mega2560(No.2)
  Serial.begin(9600);       // serial connection with PC
  pinMode(button_pin, INPUT);
}

void loop() {
  boolean state = digitalRead(button_pin);
  if (state) {
    // the button state is changed from ‘unpressed’ to ‘pressed’
    if (previous_state == false) {
      mySerial.write('1');
      Serial.println("Button is pressed..");
    }
    previous_state = true;
    delay(20);
  }
  else {
    previous_state = false;
  }
}
