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

// L298P Motor Driver

int pwmA = 10;
int pwmB = 11;
int enA = 12;
int enB = 13;

void setup() {
    pinMode(pwmA, OUTPUT);
    pinMode(pwmB, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
}

void loop() {
    int userInput;
    if(Serial.available() > 0) {
        userInput = Serial.parseInt();
        switch(userInput) {
            case 1:
                digitalWrite(pwmA, HIGH);
                analogWrite(enA, 255);
                digitalWrite(pwmB, HIGH);
                analogWrite(enB, 255);
                break;
            case 2:
                digitalWrite(pwmA, HIGH);
                analogWrite(enA, 255 * 0.5);
                digitalWrite(pwmB, LOW);
                analogWrite(enB, 255);
                break;
            case 3:
                digitalWrite(pwmA, HIGH);
                analogWrite(enA, 255);
                digitalWrite(pwmB, LOW);
                analogWrite(enB, 255 * 0.5);
                break;
            case 4:
                digitalWrite(pwmA, LOW);
                analogWrite(enA, 0);
                digitalWrite(pwmB, LOW);
                analogWrite(enB, 0);
                break;
        }
    }
}