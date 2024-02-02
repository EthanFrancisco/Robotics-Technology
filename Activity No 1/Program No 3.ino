/*
    Program No. 3
    02/02/2024
    Write an Arduino sketch that will perform the following
    conditions. Using an ADC to get the signal from Analog input 2, if
    the equivalent digital value is:
    a. Less than or equal to 400 then LED pattern will display
    11000011
    b. Greater than 700 but less than or equal to 600 then send your
    Name and Student Number to the computer thru Serial/RS232 cable
    and LED pattern will display
    10011001
    c. Greater than 1000 then output a PWM signal to pin 9 with 75%
    duty cycle and LED pattern will display 01010101
    Use:
    BAUD RATE: 57600
    LED 0 to LED 7 --> pin 11 to pin 18
*/

#define analogPin 2
int val = 0;

void setup() {
    Serial.begin(57600);
    pinMode(analogPin, INPUT);
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
    val = analogRead(analogPin);
    if (val <= 400) {
        analogWrite(9, 0);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        digitalWrite(14, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);
        digitalWrite(17, HIGH);
        digitalWrite(18, HIGH);
    } else if (val > 400 && val <= 1000) {
        // Changed ADC Values due to inaccuracies
        analogWrite(9, 0);
        Serial.println("Full Name - Student Number");
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        digitalWrite(18, HIGH);
    } else if (val > 1000) {
        analogWrite(9, 255 * 0.75);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(18, HIGH);
    }
}