/*
  Skeleton sketch implementing Cylon back-and-forth red eyes.
  Modified to use the blinkit function
*/

//We usually place new functions like blinkit above setup and loop functions.
void blinkit(int x) {
  //This function blinks an LED
  digitalWrite(x, HIGH);
  delay(1000);
  digitalWrite(x, LOW);
  delay(1000);
}

void setup() {
  // Add pinMode statements to declare pins 2,3,4,5 as OUTPUT
}

void loop() {
  blinkit(2);
  blinkit(3);
  //Add more blinkits to create the Cylon effect
}
