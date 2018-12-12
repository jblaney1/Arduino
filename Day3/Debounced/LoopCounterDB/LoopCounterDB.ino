//loop counter with debouncing
int switchPin = 3;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(500000);
}
void loop() {
  long int i = 0;
  while (digitalRead(switchPin) == HIGH) {}  //What does first while do?
  delay(5); //sleep after High to Low transition
  while (digitalRead(switchPin) == LOW) {   //What does second while do?
    i = i + 1;                              //# times through loop
  }
  delay(5);  //sleep after Low to High transition
  Serial.println(i);
}

