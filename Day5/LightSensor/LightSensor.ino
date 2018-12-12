  int lightPin= A0, rawLight;
  float Rldr = 0, Rref = 10000.0, Lux;
  
void setup() {
  Serial.begin(9600);
}

void loop() {
  rawLight = analogRead(lightPin);
  Rldr = Rref * (1023.0-rawLight)/rawLight;
  Lux = pow(10.0, 6.64 - 1.32 * log10(Rldr));
  Serial.println(Lux);
  delay(1000);
}
