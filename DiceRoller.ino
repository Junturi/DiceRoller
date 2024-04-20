//Include the library for the LCD:
#include <LiquidCrystal.h>

//Set up the pins of the LCD screen
const int rs = 7;
const int en = 6;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

const LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Declare the pins used for the buttons
const byte selectButton = 11;
const byte backButton = 10;
const byte removeButton = 12;
const byte addButton = 13;
const byte rightButton = 8;
const byte leftButton = 9;

void setup() {
  Serial.begin(9600);

  //Set up the pinmodes for the buttons
  //Use INPUT_PULLUP to ensure the buttons are in high state when not pressed
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(backButton, INPUT_PULLUP);
  pinMode(removeButton, INPUT_PULLUP);
  pinMode(addButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);

  //Set upt the number of columns and rows of the LCD
  lcd.begin(16,2);
  //Print the welcome text to the screen
  startText();
}

void loop() {

  //Poll the buttons
  if (digitalRead(selectButton) == LOW){
    delay(300); //Small delay to debounce the button
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.print("Select");
    Serial.println("Select");
  }
  if (digitalRead(backButton) == LOW){
    delay(300);
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.print("Back");
    Serial.println("Back");
  }
  if (digitalRead(removeButton) == LOW){
    delay(300);
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.print("Remove");
    Serial.println("Remove");
  }
  if (digitalRead(addButton) == LOW){
    delay(300);
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.print("Add");
    Serial.println("Add");
  }
  if (digitalRead(rightButton) == LOW){
    delay(300);
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.print("Right");
    Serial.println("Right");
  }
  if (digitalRead(leftButton) == LOW){
    delay(300);
    clearRow(1);
    lcd.setCursor(0, 1);
    lcd.print("Left");
    Serial.println("Left");
  }
}

void clearRow(int row) {
  Serial.print("Clear row: ");
  Serial.println(row);
  for (uint8_t i = 0; i < 16; i++){
    lcd.setCursor(i, row);
    lcd.print(" ");
    }
}

void startText() {
  lcd.print("Choose the dice");
}
