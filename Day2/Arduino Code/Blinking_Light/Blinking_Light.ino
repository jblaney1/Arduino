void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int onTime = 125, offTime = 65;
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(10 + i,HIGH);
    delay(onTime);
    digitalWrite(10 + i,LOW);
    delay(offTime); 
  }
    for(int i = 0; i < 4; i++)
  {
    digitalWrite(13 - i,HIGH);
    delay(onTime);
    digitalWrite(13 - i,LOW);
    delay(offTime); 
  }
} 
