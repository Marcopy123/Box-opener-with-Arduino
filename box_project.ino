#include <LiquidCrystal.h>
#include <Servo.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo Servo1;
int trigPin = 10;
int echoPin = 13;
int servo = 6;


void setup() {
  
  delay(2000);
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.print("CLOSED");
  Servo1.attach(servo);
  
}

void loop() {
 float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
 
  if (distance <= 17){
    Servo1.write(50);
    lcd.clear();
    lcd.print("OPEN");
    delay(5000);
    Servo1.write(160);
    lcd.clear();
    lcd.print("CLOSED");
    delay(1000);
    
  }

  
  

  
  
} 
