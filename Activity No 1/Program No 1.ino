/*
    Program No. 1
    02/02/2024
    Make an Arduino sketch to implement the following truth table:
    x   y   z   D0  D1  D2  D3  D4  D5  D6  D7
    0   0   0   1   0   0   0   0   0   0   0
    0   0   1   0   1   0   0   0   0   0   0
    0   1   0   0   0   1   0   0   0   0   0
    0   1   1   0   0   0   1   0   0   0   0
    1   0   0   0   0   0   0   1   0   0   0
    1   0   1   0   0   0   0   0   1   0   0
    1   1   0   0   0   0   0   0   0   1   0
    1   1   1   0   0   0   0   0   0   0   1
    Use:
        x --> pin 2
        y --> pin 3
        z --> pin 4
        D0 to D7 --> pin 11 to pin 18
*/

#define x digitalRead(2)
#define y digitalRead(3)
#define z digitalRead(4)

void setup() {
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(16, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(18, OUTPUT);
}

void loop() {
    if ((x == 0) && (y == 0) && (z == 0)) {
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        digitalWrite(14, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
    } else if ((x == 0) && (y == 0) && (z == 1)) {
	    digitalWrite(11, LOW);
	    digitalWrite(12, HIGH);
	    digitalWrite(13, LOW);
	    digitalWrite(14, LOW);
	    digitalWrite(15, LOW);
	    digitalWrite(16, LOW);
	    digitalWrite(17, LOW);
	    digitalWrite(18, LOW);
    } else if ((x == 0) && (y == 1) && (z == 0)) {
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
        digitalWrite(14, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
    } else if ((x == 0) && (y == 1) && (z == 1)) {
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
    } else if ((x == 1) && (y == 0) && (z == 0)) {
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
    } else if ((x == 1) && (y == 0) && (z == 1)) {
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        digitalWrite(14, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
    } else if ((x == 1) && (y == 1) && (z == 0)) {
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        digitalWrite(14, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);
        digitalWrite(17, HIGH);
        digitalWrite(18, LOW);
    } else if ((x == 1) && (y == 1) && (z == 1)) {
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        digitalWrite(14, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        digitalWrite(18, HIGH);
    }
}