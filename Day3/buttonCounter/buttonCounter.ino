int switchPin = 3;
int i = 0;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(500000);
  Serial.println("hello");
}
void loop() {
  while (digitalRead(switchPin) == HIGH) {}  
  i = i + 1;  //count number of button pushes
  while (digitalRead(switchPin) == LOW) {}
  Serial.println(i);
}

