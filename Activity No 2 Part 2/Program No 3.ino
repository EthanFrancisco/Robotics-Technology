/*
    Make a program to implement the following events:
    2.a. Use ADAFRUIT Motor Driver v.1
    2.b. Use ADAFRUIT Motor Driver v.2

    ANA 5       Motor1      Motor2      Stepper(1.8deg/Step)
    POT         Channel 1   Channel 2   Port 2
    <200        CLOCKWISE   C.CLOCKWISE C.CLOCKWISE
                100% DC     100% DC     30 STEPS - 40rpm
    <400        CLOCKWISE   C.CLOCKWISE CLOCKWISE
                50% DC      100% DC     25 STEPS - 30rpm
    <600        CLOCKWISE   C.CLOCKWISE C.CLOCKWISE
                100% DC     50% DC      1 STEP - 20rpm
    <800        C.CLOCKWISE CLOCKWISE   CLOCKWISE
                25% DC      25% DC      1 STEP - 10rpm
    OTHERWISE   STOP        STOP        STOP
*/

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_Stepper motor3(200, 2);

int pot = A5;
int val;

void setup() {
    Serial.begin(9600);
}

void loop() {
    val = analogRead(pot);
    Serial.println(val);

    if (val < 200) {
        motor1.setSpeed(255);
        motor1.run(FORWARD);
        motor2.setSpeed(255);
        motor2.run(BACKWARD);
        motor3.setSpeed(40);
        motor3.step(30, BACKWARD, SINGLE);
    } else if (val < 400) {
        motor1.setSpeed(255 * 0.5);
        motor1.run(FORWARD);
        motor2.setSpeed(255);
        motor2.run(BACKWARD);
        motor3.setSpeed(30);
        motor3.step(25, FORWARD, SINGLE);
    } else if (val < 600) {
        motor1.setSpeed(255);
        motor1.run(FORWARD);
        motor2.setSpeed(255 * 0.5);
        motor2.run(BACKWARD);
        motor3.setSpeed(20);
        motor3.step(1, BACKWARD, SINGLE);
    } else if (val < 800) {
        motor1.setSpeed(255 * 0.25);
        motor1.run(BACKWARD);
        motor2.setSpeed(255 * 0.25);
        motor2.run(FORWARD);
        motor3.setSpeed(10);
        motor3.step(1, FORWARD, SINGLE);
    } else {
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.step(0, FORWARD, SINGLE);
    }
}