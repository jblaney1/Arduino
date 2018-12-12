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
  int Right = digitalRead(RightSwitch);
  int Left = digitalRead(LeftSwitch);

  if (Right == LOW || Left == LOW)  //inclusive OR
    digitalWrite(LeftLED, HIGH);
  else
    digitalWrite(LeftLED, LOW);
  
  if (Right == Left) //exclusive OR
    digitalWrite(RightLED, HIGH);
  else
    digitalWrite(RightLED, LOW);
}
