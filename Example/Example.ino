/*
 * 74HC595 Shift Register - 8 LED Controller
 * 
 * Pin Connections:
 * 74HC595 Pin 14 (DS/SER) -> Arduino Pin 12 (Data)
 * 74HC595 Pin 11 (SHCP)   -> Arduino Pin 13 (Clock)
 * 74HC595 Pin 12 (STCP)   -> Arduino Pin 14 (Latch)
 * 74HC595 Pin 13 (OE)     -> GND (Output Enable - always on)
 * 74HC595 Pin 10 (SRCLR)  -> 5V (Master Reset - disabled)
 * 74HC595 Pin 16 (VCC)    -> 5V
 * 74HC595 Pin 8 (GND)     -> GND
 * 
 * Connect LEDs (with 220Ω resistors) to outputs Q0-Q7 (pins 15, 1-7)
 */

// Pin definitions
const int dataPin = 12;   // DS (Serial Data Input)
const int clockPin = 13;  // SHCP (Shift Register Clock)
const int latchPin = 14;  // STCP (Storage Register Clock)

void setup() {
  // Set pins as outputs
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("74HC595 8-LED Controller Started");
  
  // Clear all LEDs initially
  updateShiftRegister(0);
}

void loop() {
  // Demo 1: Turn on LEDs one by one
  Serial.println("Demo 1: Sequential LED turn on");
  for(int i = 0; i < 8; i++) {
    updateShiftRegister(1 << i);  // Shift bit to turn on LED i
    delay(200);
  }
  
  // Demo 2: Turn off LEDs one by one
  Serial.println("Demo 2: Sequential LED turn off");
  for(int i = 7; i >= 0; i--) {
    updateShiftRegister(1 << i);
    delay(200);
  }
  
  // Demo 3: Binary counter (0-255)
  Serial.println("Demo 3: Binary counter");
  for(int i = 0; i < 256; i++) {
    updateShiftRegister(i);
    delay(100);
  }
  
  // Demo 4: Knight Rider effect
  Serial.println("Demo 4: Knight Rider effect");
  knightRider();
  
  // Demo 5: Random pattern
  Serial.println("Demo 5: Random patterns");
  for(int i = 0; i < 20; i++) {
    updateShiftRegister(random(0, 256));
    delay(300);
  }
  
  // Demo 6: All LEDs blink
  Serial.println("Demo 6: All LEDs blink");
  for(int i = 0; i < 10; i++) {
    updateShiftRegister(255);  // All LEDs on
    delay(200);
    updateShiftRegister(0);    // All LEDs off
    delay(200);
  }
  
  delay(1000);
}

void updateShiftRegister(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}

// Safe version with overload protection
void safeUpdateShiftRegister(byte data) {
  // Add small delay to prevent rapid switching that can cause overload
  delayMicroseconds(10);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
  delayMicroseconds(10);
}

// Check if pattern is safe (not too many LEDs on at once)
bool isPatternSafe(byte pattern) {
  int ledCount = 0;
  for(int i = 0; i < 8; i++) {
    if(pattern & (1 << i)) ledCount++;
  }
  // Limit to 4 LEDs max to prevent overload
  return ledCount <= 4;
}

void knightRider() {
  for(int i = 0; i < 8; i++) {
    updateShiftRegister(1 << i);
    delay(100);
  }
  
  for(int i = 6; i > 0; i--) {
    updateShiftRegister(1 << i);
    delay(100);
  }
}

void turnOnLED(int ledNumber) {
  if(ledNumber >= 0 && ledNumber < 8) {
    updateShiftRegister(1 << ledNumber);
  }
}

void turnOffAllLEDs() {
  updateShiftRegister(0);
}

void turnOnAllLEDs() {
  updateShiftRegister(255);
}

void toggleLED(int ledNumber, byte &currentState) {
  if(ledNumber >= 0 && ledNumber < 8) {
    currentState ^= (1 << ledNumber);
    updateShiftRegister(currentState);
  }
}

void setLEDPattern(byte pattern) {
  updateShiftRegister(pattern);
}

void walkingLEDs(int delayTime) {
  byte pattern = 0b11000000;
  
  for(int i = 0; i < 8; i++) {
    updateShiftRegister(pattern);
    pattern = (pattern >> 1) | ((pattern & 1) << 7);
    delay(delayTime);
  }
}