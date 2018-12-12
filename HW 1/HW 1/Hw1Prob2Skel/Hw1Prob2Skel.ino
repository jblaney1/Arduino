/*
 Blink sketch modified to be a Cylon back-and-forth red eye
 Modified to use functions
 Blinkit function enhanced to use onTime and offTime.
*/

//New functions are typically placed above setup and loop
void blinkit(int pin, int onTime, int offTime){
  //This function blinks an LED  
  digitalWrite(pin,HIGH);
  delay(onTime);
  //Please fill in missing digitalWrite and delays
  digitalWrite(pin,LOW);
  delay(offTime);
}

void setup() {
  //Please fill in missing pinMode for 2, 3, 4, and 5
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  int pin = (rand() % 5) + 2, on = (rand() % 70) + 30, off = (rand() % 70) + 30;
  blinkit(pin,on,off);  //change the on/off time for special effect
  //Please fill in missing blinkit commands to make a nice blink pattern
}
