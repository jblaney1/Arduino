/*
  Skeleton code to help you with HW1 prob 3. 
  You just fill in the code to make it work!  
  Objective: The number of button pushes determines the number of lit LEDs
  There are 5 LEDs so when i>5, reset i to 0.
*/

//Add statements to define variables: switchPin, led1, led2, led3, led4, led5
//They should represent the pin values used in your circuit.

int switchPin = 7, led1 = 2, led2 = 3, led3 = 4, led4 = 5, led5 = 6;

int i = 0;  //initialize number of button pushes

void setup() {
  // Add pinMode statements to initialize the pins:
  // switchPin, led1, led2, led3, led4, led5
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  Serial.begin(500000);
}

void loop() {
  //Here copy in the buttonCounter code.
  
  while (digitalRead(switchPin) == HIGH) {}  
  delay(5);  //sleep after HIGH-LOW transition
  i = i + 1;  //count number of button pushes
  while (digitalRead(switchPin) == LOW) {}
  delay(5);  //sleep after LOW-HIGH transition
  Serial.println(i);
  
  //Result is that i is the number of button pushes
  //Make sure your code is "debounced" (see the course notes)
  
  if (i>5) i=0;  //reset i back to zero as required by problem statement
  
  //now we put in logic to turn on LEDs depending on value off i
  if (i==0) {               //all LEDs are off if i is zero
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
  }
  else if (i==1) {          //one LED is on if i is one
    //fill in digitalWrite statements for 1 LED on, 4 off
    digitalWrite(led1,HIGH);
  }
  else if (i==2) {          //two LEDs are on if i is 2
    //Put in digitalWrite statements for i=2 case
    digitalWrite(led2,HIGH);
  }
 //fill in the remaining if-else statements to handle i=3,4,5
  else if (i==3){
    digitalWrite(led3,HIGH);
  }
  else if (i==4){
    digitalWrite(led4,HIGH);
  }
  else if (i==5){
    digitalWrite(led5,HIGH);
  }
  else
  {
    i = 0;
  }

}
