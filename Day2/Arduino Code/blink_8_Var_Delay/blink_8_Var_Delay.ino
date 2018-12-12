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
  
  int j = rand();
  
  for(int i = 6; i <= 13; i++)
  {
      Blinkit(j % 7 + 6, 120, 60);
      j = rand();
  }
  for(int i = 0; i <= 7; i++)
  {
      j = rand();
      Blinkit(j % 7 + 6, 60, 30);
  }
}

void Blinkit(int pin, int onTime, int offTime){
  digitalWrite(pin,HIGH);
  delay(onTime);
  digitalWrite(pin,LOW);
  delay(offTime); 
}
