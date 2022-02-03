/*
SparkFun Project #2 Challenge 2
Group 1
Protect Bot
Based off Sparkfun Inventor Kit Sample - Distance Sensor
Purpose: Automatic Hand Sanitizer/Mask Dispenser
*/

#include <Servo.h>   

//initialzing variables
Servo sanitizer; 
Servo door;   

const int trigPin = 11;          
const int echoPin = 12;           

float distance = 0;              

void setup() {
  //setting up servos
  sanitizer.attach(9);
  sanitizer.write(0);

  door.attach(6);
  door.write(160);

  Serial.begin (9600);       

  //setting up distance sensor
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);   
}

void loop() {
  //only enter if-statment when hand is near distance sensor
  if(getDistance() < 4.00 ){
    //code to dispense hand sitizer
    delay(2000);
    sanitizer.write(180);
    delay(2000);
    sanitizer.write(0);
    delay(500);
    //code to dispense mask
    door.write(80);
    delay(8000);
    door.write(160);
  }
}

//------------------FUNCTIONS-------------------------------

//RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR
float getDistance()
{
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object
  float calculatedDistance;         //variable to store the distance calculated from the echo time

  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);      //use the pulsein command to see how long it takes for the
                                          //pulse to bounce back to the sensor

  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse 

  return calculatedDistance;              //send back the distance that was calculated
}
