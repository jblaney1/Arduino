//button counter debounced

int switchPin = 3;
int i = 0;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(500000);
  Serial.println("hello");
}
void loop() {
  while (digitalRead(switchPin) == HIGH) {}  
  delay(5);  //sleep after HIGH-LOW transition
  i = i + 1;  //count number of button pushes
  while (digitalRead(switchPin) == LOW) {}
  delay(5);  //sleep after LOW-HIGH transition
  Serial.println(i);
}

