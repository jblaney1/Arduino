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

  if (Right == LOW) {
    digitalWrite(RightLED,HIGH);
  }
  if (Right == HIGH) {
    digitalWrite(RightLED,LOW);
  }
  
  if (Left == LOW) {
    digitalWrite(LeftLED,LOW);
  }
  if (Left == HIGH) {
    digitalWrite(LeftLED,HIGH);
  }
  
}