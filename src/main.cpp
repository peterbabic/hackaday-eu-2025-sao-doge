#include <Arduino.h>

// Define pin (PB1 corresponds to physical pin 6 on ATtiny85)
// Already defined in platformio.ini as LED_PIN
// #define LED_PIN PB1

// PWM fading parameters
const int fadeAmount = 5;       // How many points to fade the LED by
const int fadeDelay = 30;       // How long to wait between fade steps (milliseconds)
int brightness = 0;             // Current brightness level (0-255)
bool increasing = true;         // Direction of fade

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Set the brightness of the LED
  analogWrite(LED_PIN, brightness);
  
  // Change the brightness for next time through the loop
  if (increasing) {
    brightness += fadeAmount;
    
    // Reverse direction at the top
    if (brightness >= 255) {
      brightness = 255;
      increasing = false;
    }
  } else {
    brightness -= fadeAmount;
    
    // Reverse direction at the bottom
    if (brightness <= 0) {
      brightness = 0;
      increasing = true;
      delay(1000);
    }
  }
  
  // Wait for a bit before changing brightness again
  delay(fadeDelay);
}
