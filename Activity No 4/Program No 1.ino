/*
	April 28, 2024
    1. Make a program that will implement the following procedure:
    Input a string (ex. "Abanakakabasanapalako")
    a. If only Sw1 is closed, then output the capital letters equivalent of the string.
    b. If only Sw2 is closed, then output the smaller letters equivalent of the string.
    c. If both switches are closed, then compare the string with the password (pw: "Robotics")
    d. Otherwise output the initial of the string.
    Use pin 2 for Sw1 and pin 3 for Sw2 and Serial for Output
*/

#define SW1 2
#define SW2 3

String inputString = " ";
String password = "Robotics";

void setup() {
  	Serial.begin(9600);
  	pinMode(SW1, INPUT_PULLUP);
  	pinMode(SW2, INPUT_PULLUP);
}

void loop() {
	if(Serial.available()) {
		inputString = Serial.readString();
		if((digitalRead(SW1) == LOW) && (digitalRead(SW2) == HIGH)) {
				// Switch 1 Closed, inputString to Uppercase
				inputString.toUpperCase();
				Serial.println(inputString);
    		} else if((digitalRead(SW1) == HIGH) && (digitalRead(SW2) == LOW)) {
				// Switch 2 Closed, inputString to Lowercase
				inputString.toLowerCase();
				Serial.println(inputString);
    		} else if((digitalRead(SW1) == LOW) && (digitalRead(SW2) == LOW)) {
				// Both Switches Closed, Compare inputString with password
    			if(inputString == password)
      				Serial.println("Password Matched");
    			else
      				Serial.println("Password Not Matched");
  		} else {
    		Serial.println(inputString[0]);
  		}
  		delay(1000);
  	}
}
