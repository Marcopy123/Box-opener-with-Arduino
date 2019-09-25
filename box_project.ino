#include <LiquidCrystal.h>
#include <Servo.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   //declaring the pins of the lcd
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);      //assigning the pins of the lcd, creating lcd object
Servo Servo1;         //create a servo object
int trigPin = 10; //variables
int echoPin = 13;
int servo = 6;


void setup() {
  
  delay(2000);
  lcd.begin(16, 2);//turn the lcd on
  pinMode(trigPin, OUTPUT); //pinMode,trigPin on the ultrasonic sensor
  pinMode(echoPin, INPUT);  //pinMode, echoPin on the ultrasonic sensor
  lcd.print("CLOSED");      //start with closed because it starts closed first
  Servo1.attach(servo);     //assigning the servo the pin it was connected to(6)
  
}

void loop() {
 float duration, distance;    //declaring two variables
  digitalWrite(trigPin, LOW);   //testing ultrasonic sensor
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;   //calculating the distance
 
  if (distance <= 17){    //if the distance is less than or equal to 17 centimeters...
    Servo1.write(50);     //turn servo at angle 50 (open the box);
    lcd.clear();          //delete everything that was on the lcd screen
    lcd.print("OPEN");    //display "OPEN" on the lcd screen
    delay(5000);          //wait 5 seconds
    Servo1.write(160);    //turn the servo at angle 160(close the box)
    lcd.clear();          //delete everything that was on the lcd screen
    lcd.print("CLOSED");  //display "CLOSED" on the lcd screen
    delay(1000);          //wait 1 second
        
  }

  
  

  
  
} 
