#include <Arduino.h>

// Define the GPIO pins to use (Raspberry Pi Pico has 26 GPIO pins, 0-25)
// Excluding some pins that might be used for other purposes
const int NUM_PINS = 6;
const int GPIO_PINS[NUM_PINS] = {
  3, 5, 7, 18, 20, 22
};

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("Pico GPIO Blink Starting");
  
  // Initialize all GPIO pins as outputs
  for (int i = 0; i < NUM_PINS; i++) {
    pinMode(GPIO_PINS[i], OUTPUT);
    digitalWrite(GPIO_PINS[i], HIGH); 
  }
}

void loop() {
  for (int i = 0; i < NUM_PINS; i++) {
    digitalWrite(GPIO_PINS[i], LOW);
    Serial.print("GPIO ");
    Serial.print(GPIO_PINS[i]);
    Serial.println(" ON");
    delay(500); // Wait between turning on each pin
    digitalWrite(GPIO_PINS[i], HIGH);
    Serial.print("GPIO ");
    Serial.print(GPIO_PINS[i]);
    Serial.println(" OFF");
    // delay(100); // Wait between turning off each pin
    // delay(2000); // Wait between turning off each pin
  }
}
