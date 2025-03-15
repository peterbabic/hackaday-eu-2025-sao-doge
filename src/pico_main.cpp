#include <Arduino.h>

// LED_PIN is defined in platformio.ini as GPIO 25 (Pico's built-in LED)

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("Pico LED Blink Starting");
  
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);   // Turn the LED on
  Serial.println("LED ON");
  delay(1000);                   // Wait for a second
  digitalWrite(LED_PIN, LOW);    // Turn the LED off
  Serial.println("LED OFF");
  delay(1000);                   // Wait for a second
}
