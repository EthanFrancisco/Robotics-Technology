/*
    April 28, 2024
    Make a program that will implement the following procedure:
    Input a string (ex. "Abanakakabasanapalako")
    a. If the number of characters of the string is odd, then change the last letter of the string to "Y" and output the new string.
    b. Otherwise, change the first letter of the string to "A" and output the new string.
    c. If the string contains "ka", change it with "do".
*/

String inputString = " ";
String outputString = " ";

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        inputString = Serial.readString();
        Serial.println("Input String: " + inputString);
        if (inputString.length() % 2 == 0) {
            outputString = "A" + inputString.substring(1);
        } else {
            outputString = inputString.substring(0, inputString.length() - 1) + "Y";
        }
        outputString.replace("ka", "do");
        Serial.println("Output String: " + outputString);
    }
}