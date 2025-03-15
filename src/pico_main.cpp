#include <Arduino.h>

// Define the GPIO pins to use (Raspberry Pi Pico has 26 GPIO pins, 0-25)
// Excluding some pins that might be used for other purposes
const int NUM_PINS = 25;
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
    digitalWrite(GPIO_PINS[i], LOW); // Start with all LEDs off
  }
}

void loop() {
  // Turn all GPIOs on
  Serial.println("All GPIOs ON");
  for (int i = 0; i < NUM_PINS; i++) {
    digitalWrite(GPIO_PINS[i], HIGH);
  }
  delay(6000); // Wait for a second
  
  // Turn all GPIOs off
  Serial.println("All GPIOs OFF");
  for (int i = 0; i < NUM_PINS; i++) {
    digitalWrite(GPIO_PINS[i], LOW);
  }
  delay(6000); // Wait for a second
}
