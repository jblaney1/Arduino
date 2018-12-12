#include<SoftwareSerial.h>

SoftwareSerial HC12(12,13);

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
  delay(40);
  HC12.write("AT+DEFAULT"); delay(80);
  HC12.write("AT+C001"); delay(80);
  HC12.write("AT+P4"); delay(80);
  digitalWrite(11, HIGH);
  delay(80);
}

void loop() {
  while(HC12.available()){
    Serial.write(HC12.read());
  }
  while (Serial.available()){
    HC12.write(Serial.read());
  }

}
