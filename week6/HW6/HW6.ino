int pin_LEDS[] = {2, 3}; // LEDS
unsigned long interval[] = {1000, 1000}; // Intervals for each LED
unsigned long time_previous[] = {0, 0}, time_current; // Time_previous for each LED, time_current can just be calculated twice.
boolean LED_state[] = {false, false}; // State of each LED
int adc = 0; // Potentiometer value

void setup()
{
  pinMode(A0, INPUT);
  for (int i; i < 2; i++) pinMode(pin_LEDS[i], OUTPUT);
  Serial.begin(9600);
  time_previous[0] = millis(), time_previous[1] = millis();
}

void loop()
{
  time_current = millis();
  if (time_current - time_previous[0] >= interval[0]) { // Check if enough time has passed for Pin[0]
    Serial.print("Pin2 interval: ");
    Serial.println(interval[0]);
    time_previous[0] = time_current;
    LED_state[0] = !LED_state[0];
    digitalWrite(pin_LEDS[0], LED_state[0]);
  }

  time_current = millis();
  if (time_current - time_previous[1] >= interval[1]) { // Check if enough time has passed for Pin[1]
    Serial.print("Pin3 interval: ");
    Serial.println(interval[1]);
    time_previous[1] = time_current;
    LED_state[1] = !LED_state[1];
    digitalWrite(pin_LEDS[1], LED_state[1]);
  }

  adc = analogRead(A0);
  interval[0] = map(adc, 0, 1023, 500, 1500);
  interval[1] = map(adc, 1023, 0, 500, 1500); // Invert the mapping
}
