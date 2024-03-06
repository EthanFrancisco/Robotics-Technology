/*
    03/06/2024
    Write a program that will perform the following procedure:
    When the Arduino receives a integer:
    a.  1 - rotate stepper motor in a clockwise direction by 50 steps (10 rpm)
    b.  3 - rotate stepper motor in a clockwise direction by 100 steps (20 rpm)
    c.  5 - rotate stepper motor in a counter clockwise direction by 80 steps (30 rpm)
    d.  7 - rotate stepper motor in a counter clockwise direction by 120 steps (40 rpm)
*/

#include <Stepper.h>

void setup() {
    Serial.begin(9600);
}

void loop() {
    int stepsPerRevolution = 200;
    Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
    int stepCount = 0;
    int speed = 0;
    int direction = 0;
    int input = 0;
    if (Serial.available() > 0) {
        input = Serial.read();
        if (input == 1) {
            stepCount = 50;
            speed = 10;
            direction = 1;
        } else if (input == 3) {
            stepCount = 100;
            speed = 20;
            direction = 1;
        } else if (input == 5) {
            stepCount = 80;
            speed = 30;
            direction = 0;
        } else if (input == 7) {
            stepCount = 120;
            speed = 40;
            direction = 0;
        }
        myStepper.setSpeed(speed);
        if (direction == 1) {
            myStepper.step(stepCount);
        } else {
            myStepper.step(-stepCount);
        }
    }
}