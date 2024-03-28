# Seven Segment Indicator Controller

## Components
- **MSP430 Microcontroller**: Controls the seven-segment display and executes display functions.
- **Common-Anode Seven-Segment Display**: Displays digits and characters through individual segments.
- **Resistors (if necessary)**: Limits current flow to protect the microcontroller and display.

## Pin Configuration
### Seven-Segment Display
- A - P1.3
- B - P1.5
- C - P1.7
- D - P1.1
- E - P1.0
- F - P1.4
- G - P1.6
- DT - P1.2

### Display Digits
- D1 - P2.0
- D2 - P2.1
- D3 - P2.2
- D4 - P2.5

## Overview

The Seven Segment Indicator Controller project simplifies the control of seven-segment displays using MSP430 microcontrollers. It provides functions and modules for displaying digits, animations, and effects, making it ideal for various embedded applications.

## Features

- **Digit Display**: Display digits on the seven-segment display with the `printDigit()` function.
- **Animations**: Add visual appeal with built-in animations like carousel and circular animations.
- **Flexible Configuration**: Customize display and animation parameters to suit application requirements.
- **Easy Integration**: Simply include project files in your MSP430 project and use provided functions to control the display.

## Usage

To use the Seven Segment Indicator Controller project:

1. Include project files in your MSP430 project.
2. Configure display pins using the `initDisplay()` function.
3. Utilize provided functions like `printDigit()` to display digits or `displayCarousel()` for animations.

## Contributions

Contributions are welcome! Report bugs, suggest features, or submit pull requests to improve the project. Refer to the GitHub repository for contribution guidelines.

## License

Licensed under the [Apache License, Version 2.0](LICENSE). By contributing, you agree to abide by the terms of this license.
