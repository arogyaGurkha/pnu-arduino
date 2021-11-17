void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  char buffer[32];
  while(Serial1.available()) {
    int len = Serial1.readBytesUntil('\n', buffer, 31);
    if(len > 0) {
      buffer[len] = '\0';
      String str = String(buffer);
      Serial.println("Current Temprature : " + str);
    }
  }
  
  delay(1000);
}
