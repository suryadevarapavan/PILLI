void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  Serial.println("Enter a command:");
  //pinMOde();
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read the input string until newline character
    input.trim(); // Remove any leading or trailing whitespace

    if (input == "hello") {
      Serial.println("Hi there!");
    } else if (input == "bye") {
      Serial.println("Goodbye!");
    } else if (input == "blink") {
      blinkLED(); // Call a function to blink the LED
    } else {
      Serial.println("Unknown command.");
    }
  }
}

// Function to blink the LED
void blinkLED() {
  const int ledPin = 13;
  pinMode(ledPin, OUTPUT);

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  Serial.println("LED blinked.");
}
