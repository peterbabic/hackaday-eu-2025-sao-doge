#include <Arduino.h>

// Define pin (PB1 corresponds to physical pin 6 on ATtiny85)
// Already defined in platformio.ini as LED_PIN
// #define LED_PIN PB1

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  
  // Turn the LED off
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
