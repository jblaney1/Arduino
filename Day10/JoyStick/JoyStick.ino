int SW = 2, LED = 12;

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);
  pinMode(LED,OUTPUT);
}

void loop() {
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.println(analogRead(A1));
  if (digitalRead(SW)==LOW) digitalWrite(LED,HIGH);
  else digitalWrite(LED,LOW);
}
