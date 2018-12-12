void setup() {
  pinMode(3,OUTPUT);

}

void loop() {
  int x = analogRead(A0);
  x = x/4;
  analogWrite(3,x);
}
