/*
    Program No. 2
    02/02/2024
    Write an Arduino sketch that will perform the following procedure:
    When the Arduino receives a letter:
        a. 'O' or 'o' - the RGB LED emits ORANGE light
        b. 'V' or 'v' - the RGB LED emits VIOLET light
        c. 'Y' or 'y' - the RGB LED emits YELLOW light
        d. 'W' or 'w' - the RGB LED emits WHITE light
        e. 'B' or 'b' - the RGB LED emits BLACK light
    Use: pin 5 - RED, pin 6 - GREEN, pin 9 - BLUE
*/

#define redPin 5
#define greenPin 6
#define bluePin 9

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();
    switch (data) {
      case 'O':
      case 'o':
        // Orange
        analogWrite(redPin, 255);
        analogWrite(greenPin, 165);
        analogWrite(bluePin, 0);
        break;
      case 'V':
      case 'v':
        // Violet
        analogWrite(redPin, 238);
        analogWrite(greenPin, 130);
        analogWrite(bluePin, 238);
        break;
      case 'Y':
      case 'y':
        // Yellow
        analogWrite(redPin, 255);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0);
        break;
      case 'W':
      case 'w':
        // White
        analogWrite(redPin, 255);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 255);
        break;
      case 'B':
      case 'b':
        // Black
        analogWrite(redPin, 0);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0);
        break;
    }
  }
}