void setup() {
  Serial.begin(9600);
  // 시리얼 포트 초기화
}
void loop() {
  String str1 = "One string", str2 = "Another string";
  int n = 1234;
  float f = 3.14;
  char c = 'A';
  Serial.println(str1);
  // String 출력
  Serial.println(str1 + " " + str2);
  // 문자열 연결
  Serial.println(String(n));
  // 정수로부터 10진 문자열 생성
  Serial.println(String(n, BIN));
  // 정수로부터 2진 문자열 생성
  Serial.println(String(n, HEX));
  // 정수로부터 16진 문자열 생성
  // Serial.println(String(f));
  Serial.println(f);
  // 다른 타입의 데이터를 연결하여 새로운 String 객체를 생성한다.
  Serial.println("String + integer : " + String(n));
  String str3 = "String + character : ";
  str3 += n;
  Serial.println(str3);
  //Serial.println("String + character : " + 1234) ?
  while (true);
}
