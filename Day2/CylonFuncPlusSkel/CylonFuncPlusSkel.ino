/*
 Blink sketch modified to be a Cylon back-and-forth red eye
 Modified to use functions
 Functions modified to use onTime and offTime.
*/

//New functions are typically placed above setup and loop
void blinkit(int pin, int onTime, int offTime){
  //This function blinks an LED  
  digitalWrite(pin,HIGH);
  delay(onTime);
  //Please fill in missing digitalWrite and delays
}

void setup() {
  //Please fill in missing pinMode for 2, 3, 4, and 5
}

void loop() {
  blinkit(2,100,200);  //change the on/off time for special effects
  //Please fill in missing blinkit commands to make a nice blink pattern
}
