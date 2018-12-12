/*
  For example
  blinks left LED for nleft counts, then right LED for nright
*/

int LeftLED = 5;
int RightLED = 2;

void setup() {
  pinMode(LeftLED, OUTPUT);
  pinMode(RightLED, OUTPUT);
}

void loop() {
  int nLeft = 5;
  int nRight = 10;  
  for (int k = 0; k < nLeft; k++) {
    digitalWrite(LeftLED, HIGH);
    delay(100);
    digitalWrite(LeftLED, LOW);
    delay(100);
  }
  for (int k = 0; k < nRight; k++) {
    digitalWrite(RightLED, HIGH);
    delay(50);
    digitalWrite(RightLED, LOW);
    delay(50);
  }
}
