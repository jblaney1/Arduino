//Toggle program

int led1 = 2;
int sw1 = 3;
int previousSw = HIGH;  //arbitrary
int LEDState = HIGH;    //arbitrary

void setup() {
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LEDState);                 //set LED to current state
  pinMode(sw1, INPUT_PULLUP);
}

void loop() {
  int currentSw = digitalRead(sw1);
  //wait for switch to change
  if (currentSw == LOW && previousSw == HIGH) { //it's a push down
    LEDState = !LEDState;                       //change LED state
    digitalWrite(led1, LEDState);               //update LED
  }
  previousSw = currentSw;
}

