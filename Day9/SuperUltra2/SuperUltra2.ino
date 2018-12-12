/*
 * For ee2800. Borrowed/modified from (F2017):
  Shift Register Example
  Turning on the outputs of a 74HC595 using an array

  Hardware:
   74HC595 shift register
   LEDs attached to each of the outputs of the shift register

*/
//Pin connected to ST_CP pin 12 of 74HC595
int latchPin = 9;
//Pin connected to SH_CP pin 11 of 74HC595
int clockPin = 10;
////Pin connected to DS pin 14 of 74HC595
int dataPin = 8;

byte data;
byte dataArray[10];

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);

  dataArray[0] = 0b11111111;
  dataArray[1] = 0b11111110;
  dataArray[2] = 0b11111100;
  dataArray[3] = 0b11111000;
  dataArray[4] = 0b11110000;
  dataArray[5] = 0b11100000;
  dataArray[6] = 0b11000000;
  dataArray[7] = 0b10000000;
  dataArray[8] = 0b00000000;
  dataArray[9] = 0b11100000;
}

void loop() {
delay(1000);
  for (int j = 0; j < 10; j++) {
    //load the light sequence you want from array
    data = dataArray[j];
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, LOW);
    //move 'em out
    shiftOut(dataPin, clockPin, MSBFIRST, data);
    //return the latch pin high to signal chip that it
    //no longer needs to listen for information
    digitalWrite(latchPin, HIGH);
    delay(300);
  }
}


