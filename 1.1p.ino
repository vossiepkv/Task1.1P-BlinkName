#define LED 13  // Built-in LED pin

struct MorseLetter {
  char letter;
  const char* code;
};

// Morse code dictionary
MorseLetter morseAlphabet[] = {
  {'A', ".-"},  {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
  {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
  {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
  {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
  {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
  {'Z', "--.."}
};

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter your name:");
}

void loop() {
  if (Serial.available()) {
    String name = Serial.readStringUntil('\n'); // Read input until newline
    name.toUpperCase(); // Convert to uppercase for Morse lookup
    Serial.print("Blinking Morse code for: ");
    Serial.println(name);
    
    for (int i = 0; i < name.length(); i++) {
      if (name[i] >= 'A' && name[i] <= 'Z') {
        blinkMorse(getMorseCode(name[i])); // Blink Morse code
        delay(600); // Space between letters
      }
    }
    Serial.println("Done. Enter another name:");
  }
}

const char* getMorseCode(char letter) {
  for (int i = 0; i < 26; i++) {
    if (morseAlphabet[i].letter == letter) {
      return morseAlphabet[i].code;
    }
  }
  return ""; // Return empty if not found
}

void blinkMorse(const char* morse) {
  while (*morse) {
    if (*morse == '.') {
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
    } else if (*morse == '-') {
      digitalWrite(LED, HIGH);
      delay(600);
      digitalWrite(LED, LOW);
    }
    delay(200); // Pause between dots and dashes
    morse++;
  }
}
