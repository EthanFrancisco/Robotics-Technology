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

void setup() {
    pinMode(5, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(10, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int userInput;
    if(Serial.available() > 0) {
        userInput = Serial.parseInt();
        switch(userInput) {
            case 1:
                move(0, 255, 0);
                move(1, 255, 1);
                break;
            case 2:
                move(0, 255 * 0.5, 0);
                move(1, 255, 1);
                break;
            case 3:
                move(0, 255, 0);
                move(1, 255 * 0.5, 1);
                break;
            case 4:
                digitalWrite(10, LOW);
                break;
        }
    }
}

void move(int motor, int speed, int direction) {
    boolean inPin1 = HIGH. inPin2 = LOW;
    digitalWrite(10, HIGH);
    if(direction == 1) {
        inPin1 = HIGH;
        inPin2 = LOW;
    }
    if(direction == 0) {
        inPin1 = LOW;
        inPin2 = HIGH;
    }
    if(motor == 0) {
        digitalWrite(11, inPin1);
        digitalWrite(12 inPin2);
        analogWrite(5, speed);
    }
    if(motor == 1) {
        digitalWrite(9, inPin1);
        digitalWrite(8, inPin2);
        analogWrite(3, speed);
    }
}