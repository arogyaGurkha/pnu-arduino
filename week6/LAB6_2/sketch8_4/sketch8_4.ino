int pin_button = 14; // 버튼 연결 핀
int pin_LED1 = 13, pin_LED2 = 2; // LED 연결 핀
unsigned long time_previous, time_current;
boolean LED_state1 = false; // LED 상태
boolean LED_state2 = false;
void setup() {
  pinMode(pin_button, INPUT);
  pinMode(pin_LED1, OUTPUT);
  digitalWrite(pin_LED1, LED_state1);
  pinMode(pin_LED2, OUTPUT);
  digitalWrite(pin_LED2, LED_state2);
  time_previous = millis(); // 현재 시간
}
void loop() {
  time_current = millis();
  if (time_current - time_previous >= 1000) {
    time_previous = time_current; // Update start time
    LED_state1 = !LED_state1; // LED1 status switching
    digitalWrite(pin_LED1, LED_state1);
  }
  if (digitalRead(pin_button)) { // button pressing
    LED_state2 = !LED_state2; // LED2 status switching
    digitalWrite(pin_LED2, LED_state2);
    delay(100); // Why this code is required?
  }
}
