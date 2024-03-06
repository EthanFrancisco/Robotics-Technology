/*
    03/06/2024
    Write a program that will perform the following procedure: (using pin 9)
    a. When only sw1 (pin 2) is closed then rotate the Servo to 0-degree angle
    b. When only sw2 (pin 3) is closed then rotate the Servo to 60-degree angle
    c. When both sw1 and sw2 are closed then rotate the Servo to 120-degree angle
    d. When both sw1 and sw2 are open then rotate the Servo to 120-degree angle
*/

#include <Servo.h>

Servo servo;

#define sw1 2
#define sw2 3

void setup() {
    servo.attach(9);
    pinMode(sw1, INPUT);
    pinMode(sw2, INPUT);
}

void loop() {
    if (digitalRead(sw1) == HIGH && digitalRead(sw2) == LOW) {
        servo.write(0);
    } else if (digitalRead(sw1) == LOW && digitalRead(sw2) == HIGH) {
        servo.write(60);
    } else if (digitalRead(sw1) == HIGH && digitalRead(sw2) == HIGH) {
        servo.write(120);
    } else {
        servo.write(120);
    }
    delay(100);
}