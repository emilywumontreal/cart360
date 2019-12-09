
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 3;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int ledSetupPin = 7;
const int buttonSetupPin = 6; 
int pos = 0;
int buttonStateSetup;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(ledSetupPin, OUTPUT);

  pinMode(buttonSetupPin, INPUT);

// myservo.write(170);  
//delay(1000);
myservo.write(10); 
// delay(1000);
  myservo.attach(9);
}

void loop() {

  buttonStateSetup = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateSetup == HIGH) {
      digitalWrite(ledSetupPin, HIGH);
      runMotorSetup();
  }
  else{
     digitalWrite(ledSetupPin, LOW);
  }
//  // read the state of the pushbutton value:
  int buttonState = digitalRead(buttonSetupPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  
    runMotor();


  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
   
  }

}

void runMotor() {
  for (pos = 20; pos <= 80; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(100);
  for (pos = 80; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void runMotorSetup() {

 for (pos = 20; pos <= 80; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(100);
  for (pos = 80; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

   //delay(43200000);  
   delay(5000);

  buttonStateSetup = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateSetup == LOW) {
   return; 
  }
   else
   runMotorSetup();
  }
