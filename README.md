# Whac-a-Mole-Game
## Interactive Whac-A-Mole Game Using Momentary Push Buttons
[Embedded System Design File](https://github.com/bidayatulhidayah/Embedded-System-Design)

## Introduction

 The Interactive Whac-A-Mole Game project is an innovative arcade-style game designed to
 provide an engaging and competitive experience for two players. Utilizing an Arduino Mega
 microcontroller, the game integrates momentary push buttons for player interaction, 16x2 LCD
 screens for real-time score tracking, and an emergency stop button for safety. Players compete
 to reach a score of 20 by hitting mole targets, with the system ensuring accurate score updates
 and smooth gameplay. This project demonstrates the practical application of embedded systems
 in game design, combining various components to create a seamless and interactive experience.
 
 Key objectives of the Interactive Whac-A-Mole Game include developing a responsive
 game that accurately detects button presses, implementing real-time score tracking through
 LCD displays, and ensuring safe operation with an emergency stop button. The game is
 designed to be both fun and educational, showcasing the versatility and potential of embedded
 systems. The project also emphasizes cost-effectiveness, using a 12V 3A DC power adapter
 with a buck converter to ensure a stable power supply, and ensuring compatibility of all
 components with the Arduino Mega microcontroller.

 ## Objective

- Develop an Interactive Game:
  - Create a responsive and challenging game that engages players.
  - Ensure smooth gameplay mechanics that respond accurately to user
 inputs.

- Utilize Momentary Push Buttons:
  - Implement momentary push buttons for player interaction.
  - Ensure accurate detection and response to button presses.

- Implement Real-Time Score Tracking:
  - Use LCDscreens to display real-time scores for each player.
  - Ensure accurate and timely updates of scores.

- Provide Safe Operation:
  - Integrate an emergency stop button to halt the game if needed.
  - Ensure the system operates safely and reliably.

## Components

- Microcontroller:
  - Arduino Mega
  - 
- Input Deveices:
  - 16 momentary push buttons (6 for each player)
 
- Output Devices:
  - Two 16x2 LCD screens for displaying current scores (using SDA SCL
 connection)
  - 8-channel relay modules for controlling game elements
    
- Power Supply:
  - 12V 3ADC power adapter
  - Buck converter to step down 12V to 5V for Arduino Mega
  
- Safety Features:
  - Emergency stop button
  - Restart/start button
 
## Libraries

- [ezButton](https://github.com/ArduinoGetStarted/button) by ArduinoGetStarted.com
- [LiquidCrystal I2C](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) by Frank de Brabander
 
## Circuit Diagram

<img src="https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/51cb3a2a02ec8a915eb302fc4cc24be2e532aca6/Image%20and%20Diagram/Circuit%20Diagram.png" alt="Circuit Diagram" width="400" />


## Flow Chart

<img src="https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/51cb3a2a02ec8a915eb302fc4cc24be2e532aca6/Image%20and%20Diagram/Flow%20chart.png" alt="Flow Chart" width="400" />

## Reference Video and Image

- [Demonstration Video](https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/4430c6887ebce76aeb7fcb27ba02e3d036cbf209/Image%20and%20Diagram/Demonstration.mp4)

<img src="https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/4430c6887ebce76aeb7fcb27ba02e3d036cbf209/Image%20and%20Diagram/Front%20view.jpg" alt="Front View" width="400" />

<img src="https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/4430c6887ebce76aeb7fcb27ba02e3d036cbf209/Image%20and%20Diagram/Side%20view.jpg" alt="Side View" width="400" />

<img src="https://github.com/bidayatulhidayah/Whac-a-Mole-Game/blob/4430c6887ebce76aeb7fcb27ba02e3d036cbf209/Image%20and%20Diagram/Backview.jpg" alt="Back View" width="400" />

