/*
  Distance sensor with LCD
   R. Kubichek, ECE department, University of Wyoming
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  //pin connections
float SpeedOfSound = 0.0343; //cm/us sea level
const int MAX_DISTANCE = 400; //trustworthy range
float AvgDist = 0; //average distance
float alpha = .9;  //averaging speed
int echoPin = 4;
int trigPin = 5;


void setup() {
  Serial.begin(9600);               // initialize serial comm at 9600 bps:
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);}

void loop() {

  //Insert code to use ultrasonic distance sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  while(digitalRead(echoPin)==LOW){}
  float t0 = micros();
  while(digitalRead(echoPin)){}
  float duration = micros()-t0;
  float distance = (duration / 2.0) * SpeedOfSound;
  if(distance < MAX_DISTANCE){
    AvgDist = alpha * AvgDist + (1 - alpha) * distance;
    Serial.print(distance);
    Serial.print(" ");
    Serial.println(AvgDist);
  }
  delay(50);
  //Update the LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance (cm)   ");  //16 characters defined
  lcd.setCursor(0, 1);
  lcd.print("d=       avg=    ");
  lcd.setCursor(3, 1);
  lcd.print(distance);
  lcd.setCursor(14, 1);
  lcd.print(AvgDist);
}
