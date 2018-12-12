int switchPin = 3;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(500000);
}
void loop() {
  long int i = 0;
  while (digitalRead(switchPin) == HIGH) {}  //What does first while do?
  long startTime = millis();                  //# milliseconds since power-on
  delay(5);                                   //debounce pushbutton PUSH
  while (digitalRead(switchPin) == LOW) {    //What does second while do?
    i = i + 1;                                                 //# times through loop
  }
  long duration = millis() - startTime;      //duration in ms
  Serial.print("Duration (ms) = ");          //print without line feed
  Serial.println(duration);                  //print with line feed
  delay(5);                                  //debounce pushbutton release
}

