//EE2800 F17 Kubichek
//Example of using 7-segment display

const int latchPin = 9;
const int clockPin = 10;
const int dataPin = 8;
//display 0,1,2,3,4,5,6,7,8,9,A,b,C,d,E,F
//numbers represent LED segments a-b-c-d-e-f-g-dp
//These are connected to SR binary Q7 Q6 ... Q1 Q0, where Q0 is dec_point
//Add 1 to turn on decimal point
//values can be expressed as decimal or binary. Here is decimal version:
//int datArray[16] = {252, 96, 218, 242, 102, 182,
//                    190, 224, 254, 246, 238, 62, 156,
//                    122, 158, 142
//                   };
int datArray[16] = {0b11111100, 0b1100000, 0b11011010, //0,1,2
                    0b11110010, 0b1100110,  0b10110110,  //3,4,5
                    0b10111110, 0b11100000, 0b11111110,  //6,7,8
                    0b11110110, 0b11101110, 0b00111110, 0b10011100, //9,A,b,C
                    0b01111010, 0b10011110, 0b10001110 //d,E,F
                   };
void setup ()
{
  //set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop()
{
  for (int num = 0; num < 16; num++)
  {
    digitalWrite(latchPin, LOW); //hold low while bits shifting
    shiftOut(dataPin, clockPin, MSBFIRST, datArray[num]);
    digitalWrite(latchPin, HIGH); //pull the latchPin to save  data
    delay(1000);
  }
}
