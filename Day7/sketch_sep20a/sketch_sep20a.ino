int BUZpin = 8, delayM = 1000;

void setup()
{
  pinMode(BUZpin, OUTPUT);  
}

void loop()
{
  int t0 = millis();

  if(delayM < 3000)
     {
        delayM = delayM + 100;
     }
  else
     {
        delayM = 100;
     }
    
  while((millis() - t0) < 250)
  {
     digitalWrite(BUZpin, HIGH);
     delayMicroseconds(delayM);
     digitalWrite(BUZpin, LOW);
     delayMicroseconds(delayM);
  }
  delay(250);
}

