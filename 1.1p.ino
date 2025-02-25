const int ledPin = BUILTIN_LED;

// Function to blink LED with given ON and OFF duration
void blink(int onTime, int offTime) {
  digitalWrite(ledPin, HIGH);
  delay(onTime);
  digitalWrite(ledPin, LOW);
  delay(offTime);
}

// Functions for each letter
void P() {
  blink(500, 500);
  blink(1500, 500);
  blink(1500, 500);
  blink(500, 500);
}

void A() {
  blink(500, 500);
  blink(1500, 500);
}

void T() {
  blink(1500, 500);
}

void R() {
  blink(500, 500);
  blink(1500, 500);
  blink(500, 500);
}

void I() {
  blink(500, 500);
  blink(500, 500);
}

void C() {
  blink(1500, 500);
  blink(500, 500);
  blink(1500, 500);
  blink(500, 500);
}

void K() {
  blink(1500, 500);
  blink(500, 500);
  blink(1500, 500);
}

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  P();
  A();
  T();
  R();
  I();
  C();
  K();
  delay(2000); // Pause before repeating the sequence
}
