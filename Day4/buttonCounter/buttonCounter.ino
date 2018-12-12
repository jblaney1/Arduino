int switchPin = 3;
int i = 0;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(500000);
  Serial.println("hello");
}
void loop() {
  while (digitalRead(switchPin) == HIGH) {delay(5);}  
  i = i + 1;  //count number of button pushes
  while (digitalRead(switchPin) == LOW) {delay(5);}
  Serial.println(i);
}

