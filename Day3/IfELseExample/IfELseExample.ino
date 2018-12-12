/*
   Exercise to help understand if-then-else
*/
int LeftLED = 5;
int LeftSwitch = 4;
int RightSwitch = 3;
int RightLED = 2;

void setup() {
  pinMode(LeftLED, OUTPUT);
  pinMode(RightLED, OUTPUT);
  pinMode(LeftSwitch, INPUT_PULLUP);
  pinMode(RightSwitch, INPUT_PULLUP);
}

void loop() {
  int Left = digitalRead(LeftSwitch);
  int Right = digitalRead(RightSwitch);

  if (Right == HIGH || Left == HIGH || (Right == HIGH && Left == HIGH)) {
    digitalWrite(LeftLED,HIGH);
  }  
  else
  {
    digitalWrite(LeftLED,LOW);
  }
  if ((Right == HIGH && Left == HIGH) || (Right == LOW && Left == LOW)){
    digitalWrite(RightLED,HIGH);
  }
  else if ((Right == HIGH && Left == LOW)||(Right == LOW && Left == HIGH)){
    digitalWrite(RightLED,LOW);
  }
}
