int buttons[] = {14, 15, 16, 17}; // 버튼 연결 핀
void setup() {
  Serial.begin(9600); // 시리얼 통신 초기화
  for (int i = 0; i < 4; i++) { // 버튼 연결 핀을 입력으로 설정
    pinMode(buttons[i], INPUT);
  }
}
void loop() {
  for (int i = 0; i < 4; i++) {
    Serial.print(digitalRead(buttons[i])); // 버튼 상태 출력
    Serial.print(" ");
  }
  Serial.println(); // 줄 바꿈
  delay(1000);
}
