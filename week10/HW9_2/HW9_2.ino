int speed_switch = 14, speed_state = 0;
int Enable1 = 38, PWM1 = 9, DIR1 = 39;
boolean switch_state[2] = {false, false}; // 0-> current, 1 -> previous

void setup() {
  Serial.begin(9600);
  pinMode(Enable1, OUTPUT);
  digitalWrite(Enable1, LOW); // 모터 제어 불가능 상태
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(DIR1, HIGH);
}

void change_speed_state() {
  if (switch_state[0]) {
    if (switch_state[1] == false) {
      switch_state[1] = true;
      speed_state += 1;
      speed_state %= 3;
    }
    delay(50); // debouncing
  }
  else switch_state[1] = false;

  Serial.println(speed_state);
}

void loop() {
  switch_state[0] = digitalRead(speed_switch);
  change_speed_state();

  switch (speed_state) {
    case 0: // disable the motor
      digitalWrite(Enable1, LOW);
      break;
    case 1: // enable the motor, half the speed, direction doesn't matter
      digitalWrite(Enable1, HIGH);
      analogWrite(PWM1, 255 / 2);
      break;
    case 2: // no need to enable it here because we sequential move from case 1 to 2, full speed
      analogWrite(PWM1, 255);
      break;
  }

}
