void setup() {
  pinMode(A0, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
 int x = analogRead(A0);
 Serial.println(x);
}
