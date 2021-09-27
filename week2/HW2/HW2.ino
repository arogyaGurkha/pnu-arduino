
void setup() {

  Serial.begin(9600);
  Serial.println("Enter 2 Integers to add"); // This prints the first prompt
}

void loop() {

  int x, y;

  if (Serial.available() > 0) {

    x = Serial.parseInt(); // Parse the first integer

    while (!Serial.available()); // This checks if only one integer was entered (technically it check bytes, so the program wouldn't work properly if anything other than integers are entered...)

    y = Serial.parseInt(); // Parse the second integer

    LogResults(x, y); // Log the results
  }
}

void LogResults(int x, int y) {

  Serial.print(x);
  Serial.print(" + ");
  Serial.print(y);
  Serial.print(" = ");
  Serial.println(x + y);

  Serial.println("Enter 2 Integers to add");
}
