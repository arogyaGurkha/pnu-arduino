#include <Servo.h>

Servo m_servo;
int servo_pin = 11, servo_angle = 0, servo_step = 10;
int increment_switch = 14, decrement_switch = 15;
boolean increment_state[2] = {false, false}; // 0-> current, 1-> previous
boolean decrement_state[2] = {false, false}; // 0-> current, 1-> previous

void setup() {
  m_servo.attach(servo_pin);
  Serial.begin(9600);
  m_servo.write(servo_angle);
  delay(100);
}

// Checks for angle boundaries and processes accordingly
void check_servo_angle() {
  if (servo_angle > 180) {
    servo_angle = 180;
  }
  else if (servo_angle < 0) {
    servo_angle = 0;
  }
}

// Checks each switch's current state
void check_switch_state() {
  increment_state[0] = digitalRead(increment_switch);
  decrement_state[0] = digitalRead(decrement_switch);
}

// Increments servo angle by servo_step
void increment_servo_angle() {
  if (increment_state[0]) {
    if (increment_state[1] == false) {
      servo_angle += servo_step;
      increment_state[1] = true;
    }
    delay(50); // debouncing
  }
  else if (!increment_state[0]) increment_state[1] = false;
}

// Decrements servo angle by servo_step
void decrement_servo_angle() {
  if (decrement_state[0]) {
    if (decrement_state[1] == false) {
      servo_angle -= servo_step;
      decrement_state[1] = true;
    }
    delay(50); // debouncing
  }
  else if (!decrement_state[0]) decrement_state[1] = false;
}

void loop() {
  check_switch_state();
  increment_servo_angle();
  decrement_servo_angle();
  check_servo_angle();

  Serial.println("Current angle: " + String(servo_angle));
  m_servo.write(servo_angle);
}
