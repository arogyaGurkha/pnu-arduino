
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enter 2 Integers to add");
}

void loop() {
  // put your main code here, to run repeatedly:
  int x, y;

  if (Serial.available() > 0) { 

    x = Serial.parseInt(); // Parse the first integer

    if (!(Serial.available() > 0)) { // If the user presses send before entering the second integer

      while (!Serial.available() > 0); // Wait until the user enters the second integer
      
      y = Serial.parseInt(); // Parse the second integer

    } else { // If both integers are sent on one go
      y = Serial.parseInt(); // Parse the second integer as well
    }

    LogResults(x, y); // Log the results

  }
}

void LogResults(int x, int y) {
  int sum = x + y;

  Serial.print(x);
  Serial.print(" + ");
  Serial.print(y);
  Serial.print(" = ");
  Serial.println(sum);

  Serial.println("Enter 2 Integers to add");
}
