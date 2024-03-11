/*
    03/11/2024
    Write a program that will perform the following
    procedure:
        When the Arduino receives an integer value:
        1.a. Use L298P Motor Shield
        1.b. SparkFun Motor Driver

        Input   Motor1 or A   Motor2 or B
        1       Clockwise     Clockwise
                100% DC       100% DC
        2       Clockwise     C.Clockwise
                50% DC        100% DC
        3       Clockwise     C.Clockwise
                100% DC       50% DC
        4       STOP          STOP
*/

#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);

int motorSpeed = 255;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int userInput;
    if (Serial.available() > 0) {
        userInput = Serial.parseInt();
        switch(userInput) {
            case 1:
                motor1.setSpeed(motorSpeed);
                motor1.run(FORWARD);
                motor2.setSpeed(motorSpeed);
                motor2.run(BACKWARD);
                break;
            case 2:
                motor1.setSpeed(motorSpeed / 2);
                motor1.run(FORWARD);
                motor2.setSpeed(motorSpeed);
                motor2.run(BACKWARD);
                break;
            case 3:
                motor1.setSpeed(motorSpeed);
                motor1.run(FORWARD);
                motor2.setSpeed(motorSpeed / 2);
                motor2.run(BACKWARD);
                break;
            case 4:
                motor1.run(RELEASE);
                motor2.run(RELEASE);
                break;
        }
    }
}