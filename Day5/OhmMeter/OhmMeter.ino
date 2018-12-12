  int analogInPin = A4;
  float sensorValue = 0, Rref = 220.0, Rtest;
  
void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  Rtest = Rref * (1023.0-sensorValue)/sensorValue;
  Serial.print("Sensor = ");
  Serial.print(sensorValue);
  Serial.print("    Resistance = ");
  Serial.println(Rtest);
  delay(1000);
  
}
