#include <Servo.h>

Servo myservo;

int pos = 0, dt = 5, neutraly = 499, neutralx = 516, A = 8, B = 9, C = 10, D = 11;

void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  myservo.attach(12);
}

void loop() {
  int joyx = analogRead(A1);
  int joyy = analogRead(A0);
  Serial.println(joyx);
  if(joyx > neutralx){
    dt = map(joyx - neutralx, 0, 512, 10, 1);
    ccw();
  }
  else if (joyx < neutralx){
    dt = map(neutralx - joyx, 0, 512, 10, 1);
    cw();
  }
  else if (joyy < neutraly ){
    int val = (joyy % 90);
    myservo.write(val);
    delay(15);
  }
  else if (joyy > neutraly ){
    int val = 180 - (joyy % 90);
    myservo.write(val);
    delay(15);
  }
}

void ccw(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  delay(dt);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  delay(dt);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  delay(dt);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  delay(dt);
}

void cw(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  delay(dt);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  delay(dt);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  delay(dt);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  delay(dt);
}

