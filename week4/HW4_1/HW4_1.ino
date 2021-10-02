void setup() {
  Serial.begin(9600);
}

void loop() {
  int state = 1;
  char buffer[128];
  String wordArray[5]; // contains the five words
  int i = 0; // word count index
  
  for (; ; ) {
    if (state == 1) {
      i++; 
      if (i == 6) { // checks if we are over five, resets if so
        i = 1;
        compare(wordArray); // function to sort and print the wordArray
      }
      Serial.print("Enter " + String(i) + "th Word --> ");
      state = 2;
    }
    
    while (Serial.available()) {
      int len = Serial.readBytesUntil('\n', buffer, 127);
      if (len > 0) {
        buffer[len] = '\0';
        String in_str = String(buffer);
        Serial.println(in_str);
        wordArray[i - 1] = in_str; 
        state = 1;
        break;
      }
    }

  }
}

void compare(String str[]) {
  for (int i = 0; i < 4 ; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      int compare = str[i].compareTo(str[j]);
      if (compare > 0) {
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
  for (int i = 0; i < 5 ; ++i) {
    Serial.println(str[i]); // print the array
  }
}
