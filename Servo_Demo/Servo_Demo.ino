#include <Servo.h>

Servo myservo;

const int buttonPin = 2;
const int servoPin = 9;
const int ledPin = 13;
int buttonState = 0;
int previousButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  myservo.attach(servoPin);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    open();
  } else if (buttonState == LOW) {
    close();
  }
}

void open() {
  myservo.write(180);
  digitalWrite(ledPin, HIGH);
  delay(15);
}

void close() {
  myservo.write(0);
  digitalWrite(ledPin, LOW);
  delay(15);
}
