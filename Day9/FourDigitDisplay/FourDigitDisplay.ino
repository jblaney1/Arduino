/* this sketch drives a 4 digit 7 segment display
   Display is the sh5461as common cathode device
   kubichek ee2800 fall 2017
*/
int lastDigit = 3; //save last digit used (initial value is arbitrary)
int frameRate = 50; //#frames (all 4 digits) per second
int digDelay = 1000 / frameRate / 4; //time in m.s. to dwell on each digit
const int latchPin = 9;   //Pins controlling shift register
const int clockPin = 10;
const int dataPin = 8;
int digPins[] = {2, 3, 4, 5}; //pins to sink digit 1, 2, 3, 4 (1 is leftmost)

//display 0,1,2,3,4,5,6,7,8,9,A,b,C,d,E,F
//numbers in datArray represent LED segments a-b-c-d-e-f-g-dp
//These are connected to SR binary Q7 Q6 ... Q1 Q0, where Q0 is dec_point
//Add 1 to turn on decimal point
//Example of binary format: instead of 142 we could write 0b10001110
//values can be expressed as decimal or binary. Here is decimal version:
//int datArray[16] = {252, 96, 218, 242, 102, 182,
//                    190, 224, 254, 246, 238, 62, 156,
//                    122, 158, 142
//                   };
int datArray[16] = {0b11111100, 0b1100000, 0b11011010, //252, 96, 218
                    0b11110010, 0b1100110,  0b10110110,  //242, 102, 182
                    0b10111110, 0b11100000, 0b11111110,  //190, 224, 254
                    0b11110110, 0b11101110, 0b00111110, 0b10011100, //246, 238, 62, 156
                    0b01111010, 0b10011110, 0b10001110   //122, 158, 142
                   };
void setup ()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int k = 0; k < 4; k++) pinMode(digPins[k], OUTPUT);
}

void oneDigit(int digNo, int val) {
  //This function displays a number="val" on digit# = digNo
  //by holding digPins[digNo] LOW, we make the LED
  //ground go LOW (connects it to GND), which turns it on.
  digitalWrite(digPins[lastDigit], HIGH); //clear the previous digit
  lastDigit = digNo; //save for next time
  digitalWrite(digPins[digNo], LOW); //turn on desired digit
  digitalWrite(latchPin, LOW); //disable SR output while bits shifting in
  shiftOut(dataPin, clockPin, MSBFIRST, datArray[val]);
  digitalWrite(latchPin, HIGH); //enable the shift register output
  delay(digDelay); //hold for brief period for POV
}

void showNum(int number, int duration) {
  //This function breaks number into 4 separate digits
  //Displays the 4-digit number for duration ms
  int x = number;
  int onesDig = x % 10;  x = x / 10;
  int tensDig = x % 10;  x = x / 10;
  int hunDig = x % 10;  x = x / 10;
  int thouDig = x % 10; //Higher order digits will be ignored
  long t0 = millis();
  while (millis() - t0 < duration) { //hold for required duration
    oneDigit(0, onesDig);
    oneDigit(1, tensDig);
    oneDigit(2, hunDig);
    oneDigit(3, thouDig);
  }
}
void loop() {
  //stopwatch display showing tenths of seconds
  for (int k = 0; k < 10000; k++) {
    showNum(k, 100); //show each number for 100 ms
  }
}

