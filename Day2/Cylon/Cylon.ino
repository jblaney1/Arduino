/*
  EE2800
  Skeleton code for the Cylon project.
*/

// ******  Declare global variables here (above the "void setup()")
//Assign a variable name and give a value for each GPIO pin you use
int ledpin1 = 2;  //the first LED is connected to pin 2

int blinkON = 1000; //how long to turn on LED in ms
int blinkOFF = 500; //how long to turn off LED
//Make sure you declare all variables used in your program exactly once

void setup() {
  //Use pinMode to declare any input or output pins you use
  pinMode(ledpin1, OUTPUT);
  //You need to add one pinMode statement for each pin you use
}

void loop() {
  //blink LED connected to ledpin1 once
  digitalWrite(ledpin1, HIGH); //turn the LED on
  delay(blinkON);
  digitalWrite(ledpin1, LOW); //turn the LED off
  delay(blinkOFF);

  digitalWrite(ledpin2, HIGH); //turn the LED on
  delay(blinkON);
  digitalWrite(ledpin2, LOW); //turn the LED off
  delay(blinkOFF);
  
  //blink LED connected to ledpin3 once
  //blink LED connected to ledpin4 once
  //keep adding commands to finish the blink pattern
}
