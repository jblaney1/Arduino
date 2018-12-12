void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(100);
  float V = 5.0*sensorValue/1023.0;
  Serial.print("Voltage = ");
  Serial.println(V);
}
