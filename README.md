# 74HC595 Shift Register - 8 LED Controller

A comprehensive project demonstrating the 74HC595 shift register IC for controlling 8 LEDs with Arduino, featuring both hardware implementation and an interactive web-based simulation.

## 🔌 What is the 74HC595 IC?

The **74HC595** is a high-speed CMOS 8-bit serial-in, parallel-out shift register with output latches. It's an essential component for expanding the output capabilities of microcontrollers like Arduino.

### Key Features:
- **Serial Input, Parallel Output**: Send data bit by bit, control 8 outputs simultaneously
- **Pin Conservation**: Control 8 LEDs using only 3 Arduino pins instead of 8
- **Cascadable**: Multiple 74HC595s can be chained together for even more outputs
- **High-Speed Operation**: Works reliably at high clock frequencies
- **Low Power Consumption**: CMOS technology ensures efficient operation

### How It Works:
1. **Data Input**: Serial data is sent bit by bit through the DS (Data Serial) pin
2. **Clock Control**: The SHCP (Shift Clock) pin controls when each bit is shifted in
3. **Latch Control**: The STCP (Storage Clock) pin transfers data from shift register to output latches
4. **Output**: All 8 outputs (Q0-Q7) are updated simultaneously

## 📋 Pin Configuration

| 74HC595 Pin | Function | Arduino Connection | Description |
|-------------|----------|-------------------|-------------|
| Pin 14 (DS) | Serial Data Input | Pin 2 | Data bit input |
| Pin 11 (SHCP) | Shift Clock | Pin 3 | Clock for shifting data |
| Pin 12 (STCP) | Storage Clock | Pin 4 | Clock for latching outputs |
| Pin 13 (OE) | Output Enable | GND | Always enable outputs |
| Pin 10 (SRCLR) | Master Reset | 5V | Disable reset (always high) |
| Pin 16 (VCC) | Power Supply | 5V | Positive power supply |
| Pin 8 (GND) | Ground | GND | Negative power supply |
| Pins 15,1-7 (Q0-Q7) | Outputs | LEDs + 220Ω Resistors | 8 parallel outputs |

## 🛠️ Hardware Setup

### Required Components:
- 1x Arduino Uno/Nano
- 1x 74HC595 IC
- 8x LEDs (any color)
- 8x 220Ω resistors
- Breadboard and jumper wires

### Wiring Instructions:
1. Connect 74HC595 power pins (VCC to 5V, GND to GND)
2. Connect control pins (DS→Pin 2, SHCP→Pin 3, STCP→Pin 4)
3. Connect OE to GND and SRCLR to 5V
4. Connect LEDs with 220Ω resistors to output pins Q0-Q7
5. Upload the Arduino code to your microcontroller

## 💻 Arduino Code Features

The included Arduino sketch (`Example/Example.ino`) provides several demonstration modes:

### Demo Modes:
- **Sequential LED Control**: Turn on LEDs one by one
- **Binary Counter**: Display numbers 0-255 in binary
- **Knight Rider Effect**: Moving light pattern
- **Random Patterns**: Random LED combinations
- **Blink All**: All LEDs blink together
- **Walking LEDs**: Two LEDs move in a pattern

### Key Functions:
- `updateShiftRegister(byte data)`: Core function to send data to 74HC595
- `turnOnLED(int ledNumber)`: Turn on specific LED
- `setLEDPattern(byte pattern)`: Set all LEDs at once
- `knightRider()`: Create moving light effect

## 🌐 Interactive Web Interface

The project includes a beautiful HTML simulation (`working html web.html`) that demonstrates the 74HC595 functionality without hardware.

### Features:
- **Visual LED Display**: 8 interactive LEDs that respond to clicks
- **Real-time Binary Display**: Shows current pattern in binary and decimal
- **Circuit Diagram**: Visual wiring diagram with color-coded connections
- **Control Buttons**: 
  - **Sequential**: Turn on LEDs one by one
  - **Binary Counter**: Count from 0 to 255
  - **Knight Rider**: Moving light effect
  - **Random Pattern**: Random LED combinations
  - **Blink All**: All LEDs blink together
  - **Walking LEDs**: Two LEDs move in sequence
  - **All ON/OFF**: Control all LEDs at once
- **Serial Monitor**: Simulated Arduino serial output
- **Responsive Design**: Works on desktop and mobile devices

### How to Use the Web Interface:
1. Open `working html web.html` in any modern web browser
2. Click individual LEDs to toggle them on/off
3. Use control buttons to run various demo patterns
4. Watch the binary and decimal displays update in real-time
5. Monitor the simulated serial output for debugging information

## 🎯 Applications

The 74HC595 is perfect for:
- **LED Matrices**: Control large LED displays efficiently
- **7-Segment Displays**: Drive multiple numeric displays
- **Relay Control**: Switch multiple relays with few pins
- **Sensor Arrays**: Read multiple digital sensors
- **Motor Control**: Control multiple stepper/servo motors
- **I/O Expansion**: Add more outputs to any microcontroller

## 🔧 Advanced Usage

### Cascading Multiple 74HC595s:
```cpp
// Connect Q7' (pin 9) of first IC to DS of second IC
// Use same clock and latch pins for all ICs
// Send data for all ICs in sequence
```

### Custom Patterns:
```cpp
// Create custom LED patterns
byte customPattern = 0b10101010; // Alternating pattern
updateShiftRegister(customPattern);
```

## 📚 Learning Resources

- [74HC595 Datasheet](https://www.ti.com/lit/ds/symlink/sn74hc595.pdf)
- [Arduino ShiftOut Documentation](https://www.arduino.cc/reference/en/language/functions/advanced-io/shiftout/)
- [Digital Electronics Tutorials](https://www.electronics-tutorials.ws/)

## 🤝 Contributing

Feel free to contribute to this project by:
- Adding new demo patterns
- Improving the web interface
- Adding more documentation
- Creating additional examples

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

## 🎉 Acknowledgments

- Arduino community for excellent documentation
- 74HC595 IC manufacturers for reliable hardware
- Open source contributors who inspire innovation

---

**Happy Tinkering! 🔧✨**
