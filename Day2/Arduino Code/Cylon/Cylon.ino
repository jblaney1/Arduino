void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int onTime = 60, offTime = 10;

  // A for loop to blink down the line of LED's
  // i is used to change the output number
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(10 + i,HIGH);
    delay(onTime);
    digitalWrite(10 + i,LOW);
    delay(offTime); 
  }

  // A for loop to blink back to the first LED that blinked
  // This look makes it a Cylon blink pattern instead of letting
  // the program restart and blink the first LED again
    for(int i = 0; i < 4; i++)
  {
    digitalWrite(13 - i,HIGH);
    delay(onTime);
    digitalWrite(13 - i,LOW);
    delay(offTime); 
  }
} 
