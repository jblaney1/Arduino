int switchPin = 3;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(500000);
}
void loop() {
  long int i = 0, state1 = 0, state2 = 0;
  if (state1 != state2){delay(5);}
  while (digitalRead(switchPin) == HIGH) {}  //What does first while do?
  if (state1 != state2){delay(5);}
  while (digitalRead(switchPin) == LOW) {   //What does second while do?
    i = i + 1;                              //# times through loop
  }
  state2 = state1;
  Serial.println(i);
}

