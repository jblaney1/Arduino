int pins1[] = {3,4,5,6,7,8,9,10,9,8,7,6,5,4,-1}, duration[] = {20,30,40,50,60,80,110,180,110,80,60,50,40,30},
    dataPin = 11, clockPin = 13, latchPin = 12, pins2[] = {0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,
    0b00100000,0b01000000,0b10000000,0b01000000,0b00100000,0b00010000, 0b00001000, 0b00000100,
    0b00000010, -1};

void setup() {
  for(int i = 0; i < 8; i++)
  {
    pinMode(i+3,OUTPUT);
  }
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  for(int i = 0; pins1[i] != -1; i++)
  {
    int data = pins2[i];
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, data);
    digitalWrite(pins1[i], HIGH);
    delay(duration[i]);
    digitalWrite(latchPin, HIGH);
    digitalWrite(pins1[i], LOW);
    delay(duration[i]);
  }
}
