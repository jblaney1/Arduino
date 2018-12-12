void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
  // A for loop to change the pin in the loop
  
  for(int i = 6; i <= 13; i++)
  {
      Blinkit(i);
  }
  for(int i = 0; i <= 7; i++)
  {
      Blinkit(13 - i);
  }
}

void Blinkit(int pin){
  int onTime = rand() % 500, offTime = rand() % 50;
  digitalWrite(pin,HIGH);
  delay(onTime);
  digitalWrite(pin,LOW);
  delay(offTime); 
}
