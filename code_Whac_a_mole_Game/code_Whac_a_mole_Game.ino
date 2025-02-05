#include <ezButton.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//initialize the liquid crystal library
LiquidCrystal_I2C LCD_1(0x26, 16, 2);
LiquidCrystal_I2C LCD_2(0x27, 16, 2);

// Player 1 buttons and LEDs
ezButton button1P1(33);  // create ezButton object that attaches to pin 33 for Player 1
ezButton button2P1(37);  // create ezButton object that attaches to pin 37 for Player 1
ezButton button3P1(29);  // create ezButton object that attaches to pin 29 for Player 1
ezButton button4P1(35);  // create ezButton object that attaches to pin 35 for Player 1
ezButton button5P1(25);  // create ezButton object that attaches to pin 25 for Player 1
ezButton button6P1(23);  // create ezButton object that attaches to pin 23 for Player 1
ezButton button7P1(27);  // create ezButton object that attaches to pin 27 for Player 1
ezButton button8P1(31);  // create ezButton object that attaches to pin 31 for Player 1

const int led1PinP1 = 38;  // define the pin for LED1 for Player 1
const int led2PinP1 = 42;  // define the pin for LED2 for Player 1
const int led3PinP1 = 40;  // define the pin for LED3 for Player 1
const int led4PinP1 = 44;  // define the pin for LED4 for Player 1
const int led5PinP1 = 46;  // define the pin for LED5 for Player 1
const int led6PinP1 = 48;  // define the pin for LED6 for Player 1
const int led7PinP1 = 50;  // define the pin for LED7 for Player 1
const int led8PinP1 = 52;  // define the pin for LED8 for Player 1

// Player 2 buttons and LEDs
ezButton button1P2(7);  // create ezButton object that attaches to pin 7 for Player 2
ezButton button2P2(2);  // create ezButton object that attaches to pin 2 for Player 2
ezButton button3P2(8);  // create ezButton object that attaches to pin 8 for Player 2
ezButton button4P2(9);  // create ezButton object that attaches to pin 9 for Player 2
ezButton button5P2(6);  // create ezButton object that attaches to pin 6 for Player 2
ezButton button6P2(5);  // create ezButton object that attaches to pin 5 for Player 2
ezButton button7P2(4);  // create ezButton object that attaches to pin 4 for Player 2
ezButton button8P2(3);  // create ezButton object that attaches to pin 3 for Player 2

const int led1PinP2 = 39;  // define the pin for LED1 for Player 2
const int led2PinP2 = 41;  // define the pin for LED2 for Player 2
const int led3PinP2 = 43;  // define the pin for LED3 for Player 2
const int led4PinP2 = 47;  // define the pin for LED4 for Player 2
const int led5PinP2 = 45;  // define the pin for LED5 for Player 2
const int led6PinP2 = 49;  // define the pin for LED6 for Player 2
const int led7PinP2 = 51;  // define the pin for LED7 for Player 2
const int led8PinP2 = 53;  // define the pin for LED8 for Player 2

//GameStatus
bool gameStatus = false;

unsigned long previousMillisP1 = 0;  // Variable to store the time when the LED was last turned on for Player 1
unsigned long previousMillisP2 = 0;  // Variable to store the time when the LED was last turned on for Player 2

unsigned long ledDuration = 500;  // Duration for LED to stay on in milliseconds
int activeLedP1 = -1;             // Variable to store the index of the currently active LED for Player 1
int activeLedP2 = -1;             // Variable to store the index of the currently active LED for Player 2

int scoreP1 = 0;  // Player 1 score
int scoreP2 = 0;  // Player 2 score

// Define the pin for the reset button
const int resetButtonPin = 11;

void updateScore(bool player1) {
  if (player1) {
    scoreP1++;
    Serial.print("Player 1 Score: ");
    Serial.println(scoreP1);
    //Print on LCD_1

    LCD_1.setCursor(0, 0);
    LCD_1.print("Score Player 1: ");


    LCD_1.setCursor(1, 4);
    LCD_1.print(scoreP1);

  } else {
    scoreP2++;
    Serial.print("Player 2 Score: ");
    Serial.println(scoreP2);
    //Print on LCD_2
    LCD_2.setCursor(0, 0);
    LCD_2.print("Score Player 2: ");
    LCD_2.setCursor(1, 4);
    LCD_2.print(scoreP2);
  }
}

void setup() {
  Serial.begin(9600);

  // Set debounce time for Player 1 buttons
  button1P1.setDebounceTime(50);
  button2P1.setDebounceTime(50);
  button3P1.setDebounceTime(50);
  button4P1.setDebounceTime(50);
  button5P1.setDebounceTime(50);
  button6P1.setDebounceTime(50);
  button7P1.setDebounceTime(50);
  button8P1.setDebounceTime(50);

  // Set debounce time for Player 2 buttons
  button1P2.setDebounceTime(50);
  button2P2.setDebounceTime(50);
  button3P2.setDebounceTime(50);
  button4P2.setDebounceTime(50);
  button5P2.setDebounceTime(50);
  button6P2.setDebounceTime(50);
  button7P2.setDebounceTime(50);
  button8P2.setDebounceTime(50);

  // Set LED pins as outputs for Player 1
  pinMode(led1PinP1, OUTPUT);
  pinMode(led2PinP1, OUTPUT);
  pinMode(led3PinP1, OUTPUT);
  pinMode(led4PinP1, OUTPUT);
  pinMode(led5PinP1, OUTPUT);
  pinMode(led6PinP1, OUTPUT);
  pinMode(led7PinP1, OUTPUT);
  pinMode(led8PinP1, OUTPUT);

  // Set LED pins as outputs for Player 2
  pinMode(led1PinP2, OUTPUT);
  pinMode(led2PinP2, OUTPUT);
  pinMode(led3PinP2, OUTPUT);
  pinMode(led4PinP2, OUTPUT);
  pinMode(led5PinP2, OUTPUT);
  pinMode(led6PinP2, OUTPUT);
  pinMode(led7PinP2, OUTPUT);
  pinMode(led8PinP2, OUTPUT);

  // Set buttons pins as inputs with internal pull-up resistors for Player 1
  pinMode(33, INPUT_PULLUP);
  pinMode(37, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);

  // Set buttons pins as inputs with internal pull-up resistors for Player 2
  pinMode(7, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  // Set the reset button pin as input with internal pull-up resistor
  pinMode(resetButtonPin, INPUT_PULLUP);

  //initialize lcd screen
  LCD_1.init();
  LCD_2.init();
  // turn on the backlight
  LCD_1.backlight();
  LCD_2.backlight();
}

void loop() {

  // LCD_1.setCursor(0, 2);
  // LCD_1.print("Score Player 1: ");

  // LCD_2.setCursor(0, 2);
  // LCD_2.print("Score Player 2: ");

  if (gameStatus) {
    unsigned long currentMillis = millis();  // Get the current time

    // Player 1
    if (currentMillis - previousMillisP1 >= ledDuration) {
      // Turn off the currently active LED for Player 1
      if (activeLedP1 != -1) {
        turnOffLed(activeLedP1, true);  // true indicates Player 1
      }

      // Randomly select a new LED for Player 1
      activeLedP1 = random(1, 9);
      turnOnLed(activeLedP1, true);  // true indicates Player 1

      // Remember the time when the LED was turned on for Player 1
      previousMillisP1 = currentMillis;
    }

    // Player 2
    if (currentMillis - previousMillisP2 >= ledDuration) {
      // Turn off the currently active LED for Player 2
      if (activeLedP2 != -1) {
        turnOffLed(activeLedP2, false);  // false indicates Player 2
      }

      // Randomly select a new LED for Player 2
      activeLedP2 = random(1, 9);
      turnOnLed(activeLedP2, false);  // false indicates Player 2

      // Remember the time when the LED was turned on for Player 2
      previousMillisP2 = currentMillis;
    }

    // Check Player 1 button presses
    button1P1.loop();
    button2P1.loop();
    button3P1.loop();
    button4P1.loop();
    button5P1.loop();
    button6P1.loop();
    button7P1.loop();
    button8P1.loop();

    if (button1P1.isPressed() && activeLedP1 == 1) {
      turnOffLed(activeLedP1, true);  // true indicates Player 1
      updateScore(true);
    }
    if (button2P1.isPressed() && activeLedP1 == 2) {
      turnOffLed(activeLedP1, true);  // true indicates Player 1
      updateScore(true);
    }
    if (button3P1.isPressed() && activeLedP1 == 3) {
      turnOffLed(activeLedP1, true);  // true indicates Player 1
      updateScore(true);
    }
    if (button4P1.isPressed() && activeLedP1 == 4) {
      turnOffLed(activeLedP1, true);  // true indicates Player 1
      updateScore(true);
    }
    if (button5P1.isPressed() && activeLedP1 == 5) {
      turnOffLed(activeLedP1, true);  // true indicates Player 1
      updateScore(true);
    }
    if (button6P1.isPressed() && activeLedP1 == 6) {
      turnOffLed(activeLedP1, true);  // true indicates Player 1
      updateScore(true);
    }
    if (button7P1.isPressed() && activeLedP1 == 7) {
      turnOffLed(activeLedP1, true);  // true indicates Player 1
      updateScore(true);
    }
    if (button8P1.isPressed() && activeLedP1 == 8) {
      turnOffLed(activeLedP1, true);  // true indicates Player 1
      updateScore(true);
    }

    // Check Player 2 button presses
    button1P2.loop();
    button2P2.loop();
    button3P2.loop();
    button4P2.loop();
    button5P2.loop();
    button6P2.loop();
    button7P2.loop();
    button8P2.loop();

    if (button1P2.isPressed() && activeLedP2 == 1) {
      turnOffLed(activeLedP2, false);  // false indicates Player 2
      updateScore(false);
    }
    if (button2P2.isPressed() && activeLedP2 == 2) {
      turnOffLed(activeLedP2, false);  // false indicates Player 2
      updateScore(false);
    }
    if (button3P2.isPressed() && activeLedP2 == 3) {
      turnOffLed(activeLedP2, false);  // false indicates Player 2
      updateScore(false);
    }
    if (button4P2.isPressed() && activeLedP2 == 4) {
      turnOffLed(activeLedP2, false);  // false indicates Player 2
      updateScore(false);
    }
    if (button5P2.isPressed() && activeLedP2 == 5) {
      turnOffLed(activeLedP2, false);  // false indicates Player 2
      updateScore(false);
    }
    if (button6P2.isPressed() && activeLedP2 == 6) {
      turnOffLed(activeLedP2, false);  // false
      updateScore(false);
    }
    if (button7P2.isPressed() && activeLedP2 == 7) {
      turnOffLed(activeLedP2, false);  // false indicates Player 2
      updateScore(false);
    }
    if (button8P2.isPressed() && activeLedP2 == 8) {
      turnOffLed(activeLedP2, false);  // false indicates Player 2
      updateScore(false);
    }

    // Check if any player has reached the winning score
    if (scoreP1 >= 20) {
      Serial.println("Player 1 wins!");

      // LCD_1.setCursor(0, 0);
      // LCD_1.print("Congratulations");
      //LCD_1.setCursor(1, 0);
      //LCD_1.print("You are the Winner!");
      // //Player 2 Loose
      // LCD_2.setCursor(0, 0);
      // LCD_2.print("Well done");
      // LCD_2.setCursor(0, 2);
      // LCD_2.print("Please try again!");

      gameStatus = false;

    } else if (scoreP2 >= 20) {
      Serial.println("Player 2 wins!");

      // LCD_1.setCursor(0, 0);
      // LCD_1.print("Well done");
      // LCD_1.setCursor(0, 2);
      // LCD_1.print("Please try again!");
      //Player 2 Winner
      // LCD_2.setCursor(0, 0);
      // LCD_2.print("Congratulations");
      // LCD_2.setCursor(1, 0);
      // LCD_2.print("You are the Winner!");

      gameStatus = false;
    }
  }
  // Check if the reset button is pressed
  if (digitalRead(resetButtonPin) == LOW) {
    resetGame();
    gameStatus = !gameStatus;
  }
}

// Function to turn on the specified LED for the respective player
void turnOnLed(int led, bool player1) {
  if (player1) {
    switch (led) {
      case 1:
        digitalWrite(led1PinP1, LOW);  // Turn LED1 on for Player 1
        break;
      case 2:
        digitalWrite(led2PinP1, LOW);  // Turn LED2 on for Player 1
        break;
      case 3:
        digitalWrite(led3PinP1, LOW);  // Turn LED3 on for Player 1
        break;
      case 4:
        digitalWrite(led4PinP1, LOW);  // Turn LED4 on for Player 1
        break;
      case 5:
        digitalWrite(led5PinP1, LOW);  // Turn LED5 on for Player 1
        break;
      case 6:
        digitalWrite(led6PinP1, LOW);  // Turn LED6 on for Player 1
        break;
      case 7:
        digitalWrite(led7PinP1, LOW);  // Turn LED7 on for Player 1
        break;
      case 8:
        digitalWrite(led8PinP1, LOW);  // Turn LED8 on for Player 1
        break;
    }
  } else {
    switch (led) {
      case 1:
        digitalWrite(led1PinP2, LOW);  // Turn LED1 on for Player 2
        break;
      case 2:
        digitalWrite(led2PinP2, LOW);  // Turn LED2 on for Player 2
        break;
      case 3:
        digitalWrite(led3PinP2, LOW);  // Turn LED3 on for Player 2
        break;
      case 4:
        digitalWrite(led4PinP2, LOW);  // Turn LED4 on for Player 2
        break;
      case 5:
        digitalWrite(led5PinP2, LOW);  // Turn LED5 on for Player 2
        break;
      case 6:
        digitalWrite(led6PinP2, LOW);  // Turn LED6 on for Player 2
        break;
      case 7:
        digitalWrite(led7PinP2, LOW);  // Turn LED7 on for Player 2
        break;
      case 8:
        digitalWrite(led8PinP2, LOW);  // Turn LED8 on for Player 2
        break;
    }
  }
}

// Function to turn off the specified LED for the respective player
void turnOffLed(int led, bool player1) {
  if (player1) {
    switch (led) {
      case 1:
        digitalWrite(led1PinP1, HIGH);  // Turn LED1 off for Player 1
        break;
      case 2:
        digitalWrite(led2PinP1, HIGH);  // Turn LED2 off for Player 1
        break;
      case 3:
        digitalWrite(led3PinP1, HIGH);  // Turn LED3 off for Player 1
        break;
      case 4:
        digitalWrite(led4PinP1, HIGH);  // Turn LED4 off for Player 1
        break;
      case 5:
        digitalWrite(led5PinP1, HIGH);  // Turn LED5 off for Player 1
        break;
      case 6:
        digitalWrite(led6PinP1, HIGH);  // Turn LED6 off for Player 1
        break;
      case 7:
        digitalWrite(led7PinP1, HIGH);  // Turn LED7 off for Player 1
        break;
      case 8:
        digitalWrite(led8PinP1, HIGH);  // Turn LED8 off for Player 1
        break;
    }
  } else {
    switch (led) {
      case 1:
        digitalWrite(led1PinP2, HIGH);  // Turn LED1 off for Player 2
        break;
      case 2:
        digitalWrite(led2PinP2, HIGH);  // Turn LED2 off for Player 2
        break;
      case 3:
        digitalWrite(led3PinP2, HIGH);  // Turn LED3 off for Player 2
        break;
      case 4:
        digitalWrite(led4PinP2, HIGH);  // Turn LED4 off for Player 2
        break;
      case 5:
        digitalWrite(led5PinP2, HIGH);  // Turn LED5 off for Player 2
        break;
      case 6:
        digitalWrite(led6PinP2, HIGH);  // Turn LED6 off for Player 2
        break;
      case 7:
        digitalWrite(led7PinP2, HIGH);  // Turn LED7 off for Player 2
        break;
      case 8:
        digitalWrite(led8PinP2, HIGH);  // Turn LED8 off for Player 2
        break;
    }
  }
}

// Function to reset the game
void resetGame() {
  // Reset all variables
  previousMillisP1 = 0;
  previousMillisP2 = 0;
  scoreP1 = 0;
  scoreP2 = 0;
  activeLedP1 = -1;
  activeLedP2 = -1;

  // Turn off all LEDs
  for (int i = 1; i <= 8; i++) {
    turnOffLed(i, true);   // Player 1 LEDs
    turnOffLed(i, false);  // Player 2 LEDs
  }
}
