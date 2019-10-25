/*
reference code
https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
for reading distance from ultrasound sensor
https://github.com/enricllagostera/altctrls-wksh-cart360/blob/master/docs/slides.md
for keyboard simulation
*/

#include <USI_TWI_Master.h>
#include <Wire.h>
#include <Keyboard.h> // library to simulate keyboard events


// Make sure these two variables are correct for your setup
int scale = 3; // 3 (±3g) for ADXL337, 200 (±200g) for ADXL377
boolean micro_is_5V = true; // Set to true if using a 5V microcontroller such as the Arduino Uno, false if using a 3.3V microcontroller, this affects the interpretation of the sensor data
int trigPin = 10;    // Trigger
int echoPin = 11;    // Echo
long duration, cm, inches;


void setup()
{
  // Initialize serial communication at 115200 baud
  //Serial.begin(115200);

   Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Keyboard.begin();
}



// Read, scale, and print accelerometer data
void loop()
{
  // Get raw accelerometer data for each axis
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135


  
  if(cm < 10){
    Keyboard.press(' ');
  }
  else {
    Keyboard.releaseAll();
  }
  delay(10);  //delay 0.01S
                 

  
 // Serial.print("duration,   ");
 // Serial.print(duration);
 // Serial.print("===,   ");
 // Serial.print(inches);
 // Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
//  Serial.println();
  
 // delay(250);
  
  
}
