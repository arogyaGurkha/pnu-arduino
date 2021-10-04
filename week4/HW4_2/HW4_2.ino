int pins_LED[] = {2, 3, 4, 5}; // LED 연결 핀
int pin_button = 14;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(pins_LED[i], OUTPUT);
  }
  pinMode(pin_button, OUTPUT);
}

void loop() {
  int led_i = 0; // led index
  boolean direction = true; // direction of leds, true means 2->3->4->5->2...
  boolean oldState, newState; // check whether the switch state has changed or not
  while (true) {
    newState = digitalRead(pin_button); // read the switch state

    led_controller(led_i); // turn on the lights, the 500 delay causes problem with switch,

    if (oldState != newState && !oldState) direction = !direction; // check if the state has changed, this is used to prevent direction to changes when the switch is kept being pressed

    if (direction) {
      led_i++;
      if (led_i == 4) led_i = 0;
    } else {
      led_i--;
      if (led_i == -1) led_i = 3;
    }

    oldState = newState;
  }
}

void led_controller(int led_i) { // 조교님, delay때문에 switch press 응답이 없는 경우, 좀 더 오래 눌러주시면 방향이 바꿔집니다.
  digitalWrite(pins_LED[led_i], HIGH);
  delay(500);
  digitalWrite(pins_LED[led_i], LOW);
}
