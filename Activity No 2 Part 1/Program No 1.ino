/*
    Program No. 1
    03/06/2024
    Make a program to implement the following events:
    SW1     SW2     Motor1      Motor2
    Pin 2   Pin 3   Pin 11 & 10 Pin 6 & 5
    0       1       Clockwise   STOP
                    1 0
                    30% DC
    1       0       STOP        Clockwise
                                0 1
                                70% DC
    0       0       Clockwise   C. Clockwise
                    1 0         0 1
                    40% DC      60% DC
    1       1       C. ClockwiseClockwise
                    0 1         1 0
                    100% DC     25% DC
*/

#define SW1 2
#define SW2 3

void setup() {
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop() {
    if (digitalRead(SW1) == 0 && digitalRead(SW2) == 1) {
        analogWrite(11, 255 * 0.3);
        analogWrite(10, 0);
        analogWrite(6, 0);
        analogWrite(5, 0);
    } else if (digitalRead(SW1) == 1 && digitalRead(SW2) == 0) {
        analogWrite(11, 0);
        analogWrite(10, 0);
        analogWrite(6, 255 * 0.7);
        analogWrite(5, 0);
    } else if (digitalRead(SW1) == 0 && digitalRead(SW2) == 0) {
        analogWrite(11, 255 * 0.4);
        analogWrite(10, 0);
        analogWrite(6, 0);
        analogWrite(5, 255 * 0.6);
    } else if (digitalRead(SW1) == 1 && digitalRead(SW2) == 1) {
        analogWrite(11, 255);
        analogWrite(10, 0);
        analogWrite(6, 0);
        analogWrite(5, 255 * 0.25);
    }    
}
