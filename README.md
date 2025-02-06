# Whac-a-Mole-Game
## Interactive Whac-A-Mole Game Using Momentary Push Buttons
[Embedded System Design File](https://github.com/bidayatulhidayah/Embedded-System-Design)

# Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Components](#components)
- [Library Required](#library-required)
- [Circuit Diagram](#circuit-diagram)
  - [Pin Mapping](#pin-mapping)
- [Flow Chart](#flow-chart)
- [Installation](#installation)
- [Game Logic](#game-logic)
- [Troubleshooting](#troubleshooting)
- [Reference Video and Image](#reference-video-and-image)
- [License](#license)
- 
## Overview

 This project implements a simple game where two players press buttons corresponding to active LEDs. The player who presses the correct button corresponding to the active LED gets a point. This game uses an Arduino to manage the logic, button presses, and LED states, while displaying the scores on two LCD screens.

## Features
- Two-player gameplay: Each player has a set of 8 buttons and 8 corresponding LEDs.
- Score tracking: The scores for both players are displayed on separate LCD screens.
- Random LED activation: A random LED is activated for each player at regular intervals.
- Button press detection: The player who presses the correct button corresponding to the active LED gains a point.
- Reset functionality: A reset button to start the game from scratch

## Components

- Microcontroller: Arduino Mega (2560)
- LCD Displays: 2x 16x2 LCD with I2C interface
- Buttons: 16 buttons (8 for each player)
- LEDs: 16 LEDs (8 for each player)
- Reset Button: 1 button to reset the game
 
## Library Required

- [ezButton](https://github.com/ArduinoGetStarted/button): : Library for managing button inputs by ArduinoGetStarted.com
- [LiquidCrystal I2C](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library): Library for controlling the LCD with I2C communication by Frank de Brabander


 
## Circuit Diagram

<img src="https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/51cb3a2a02ec8a915eb302fc4cc24be2e532aca6/Image%20and%20Diagram/Circuit%20Diagram.png" alt="Circuit Diagram" width="400" />

### Pin Mapping
#### Player 1 (Buttons)
- Button 1: Pin 33
- Button 2: Pin 37
- Button 3: Pin 29
- Button 4: Pin 35
- Button 5: Pin 25
- Button 6: Pin 23
- Button 7: Pin 27
- Button 8: Pin 31
#### Player 1 (LEDs)
- LED 1: Pin 38
- LED 2: Pin 42
- LED 3: Pin 40
- LED 4: Pin 44
- LED 5: Pin 46
- LED 6: Pin 48
- LED 7: Pin 50
- LED 8: Pin 52
#### Player 2 (Buttons)
- Button 1: Pin 7
- Button 2: Pin 2
- Button 3: Pin 8
- Button 4: Pin 9
- Button 5: Pin 6
- Button 6: Pin 5
- Button 7: Pin 4
- Button 8: Pin 3
#### Player 2 (LEDs)
- LED 1: Pin 39
- LED 2: Pin 41
- LED 3: Pin 43
- LED 4: Pin 47
- LED 5: Pin 45
- LED 6: Pin 49
- LED 7: Pin 51
- LED 8: Pin 53
#### Reset Button
- Reset Button: Pin 11

## Flow Chart

<img src="https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/51cb3a2a02ec8a915eb302fc4cc24be2e532aca6/Image%20and%20Diagram/Flow%20chart.png" alt="Flow Chart" width="400" />

## Installation
1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/your-username/led-button-game.git

2. Open the project in the Arduino IDE. 

3. . Install the necessary libraries:

- Go to Sketch > Include Library > Manage Libraries.
- Search for and install ezButton and LiquidCrystal_I2C.
  
4. Upload the code to your Arduino.

## Game Logic
- At the start of the game, random LEDs are activated for both players.
- The player who presses the button corresponding to the active LED scores a point.
- The score for each player is displayed on their respective LCD.
- The game resets when the reset button is pressed.

## Troubleshooting
- Buttons not responding: Ensure that the button pins are connected properly and the pull-up resistors are enabled in the code.
- LCD not displaying: Double-check the I2C address for the LCD displays.

## Reference Video and Image

- [Demonstration Video](https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/4430c6887ebce76aeb7fcb27ba02e3d036cbf209/Image%20and%20Diagram/Demonstration.mp4)

<img src="https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/4430c6887ebce76aeb7fcb27ba02e3d036cbf209/Image%20and%20Diagram/Front%20view.jpg" alt="Front View" width="400" />

<img src="https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/4430c6887ebce76aeb7fcb27ba02e3d036cbf209/Image%20and%20Diagram/Side%20view.jpg" alt="Side View" width="400" />

<img src="https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/4430c6887ebce76aeb7fcb27ba02e3d036cbf209/Image%20and%20Diagram/Backview.jpg" alt="Back View" width="400" />

## License
- This project is licensed under the MIT License - see the LICENSE file for details.

