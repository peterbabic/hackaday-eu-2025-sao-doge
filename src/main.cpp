#include <Arduino.h>

// Define pin (PB1 corresponds to physical pin 6 on ATtiny85)
// Already defined in platformio.ini as LED_PIN
// #define LED_PIN PB1

// Define button pin (PB3)
#define BUTTON_PIN PB3

// PWM fading parameters
const int fadeAmount = 5;       // How many points to fade the LED by
const int normalFadeDelay = 30; // Normal fade delay (milliseconds)
const int blinkDelay = 100;     // Blink delay when button is pressed (milliseconds)
int brightness = 0;             // Current brightness level (0-255)
bool increasing = true;         // Direction of fade
bool ledState = false;          // State for blinking mode

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize the button pin with internal pullup
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Check if button is pressed (LOW when pressed because of pullup)
  bool buttonPressed = (digitalRead(BUTTON_PIN) == LOW);
  
  if (buttonPressed) {
    // Rapid blinking mode when button is pressed
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    delay(blinkDelay);
  } else {
    // Normal fading mode when button is not pressed
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
    delay(normalFadeDelay);
  }
}
