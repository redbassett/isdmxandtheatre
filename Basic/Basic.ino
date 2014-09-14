#include <Servo.h>

Servo myservo;

const int servoPin = 9;
const int contactPin = 2;
const int ledPin = 13;
const int degree45 = 3;
const int degree90 = 4;
const int degree180 = 5;

int contactState = 0;
int previousContactState = 0;

int incomingByte = 0;

int degreeMode;

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(contactPin, INPUT);
	pinMode(degree45, INPUT);
	pinMode(degree90, INPUT);
	pinMode(degree180, INPUT);
	
	if (digitalRead(degree45) == HIGH) {
		degreeMode = 45;
	} else if (digitalRead(degree90) == HIGH) {
		degreeMode = 90;
	} else {
		degreeMode = 180;
	}
	
	myservo.attach(servoPin);

	Serial.begin(9600);
}

void loop() {
	contactState = digitalRead(contactPin);
	
	if (Serial.available() > 0) {
		incomingByte = Serial.read();
	}
	
	if (contactState == HIGH || incomingByte == 49) {
		open();
	} else if (contactState == LOW || incomingByte == 48) {
		close();
	}
}

void open() {
	myservo.write(degreeMode);
	digitalWrite(ledPin, HIGH);
	Serial.print('Opening servo (');
	Serial.print(degreeMode);
	Serial.println(' degrees).');
	delay(15);
}

void close() {
	myservo.write(0);
	digitalWrite(ledPin, LOW);
	Serial.println('Closing servo (0 degrees).');
	delay(15);
}
