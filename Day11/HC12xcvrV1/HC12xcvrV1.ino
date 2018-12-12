/*
  HC12 used bi-directional communications.  
  This program used at both radios.
  Initialize channel and power in setup
  Received data: x and y are analogReads of A0 and A1 at xmtr
  Two-way scheme:
    *Each time through loop, check the HC12 to see if anything has been received.
    *Each time through loop, see if conditions for transmission have been met:
      Before transmission, check to see if receiver is in middle of receiving
      a packet (state>0).  If not then don't transmit.  
      If state==0, it means we are not in the middle of receiving a packet.
      Now check to see if enough time has elapsed since last transmission.  
      The goal here is to leave gaps so that neither radio hogs the channel.
      If enough time has elapsed, then transmit a packet.

  Data packet Format:
     byte 0 is 0xFF  (first 2 bytes indicate start of packet)
     byte 1 is 0xFF
     byte 2 is LSB x
     byte 3 is USB x
     byte 4 is LSB y
     byte 5 is USB y
  *note: using FF is ok if the range of values is 0-1023 (0-0x03ff)
  *Unfortunately, the sequence 0xFFFF equals -1, so we can't use 
  *this approach to transmit more general data including negative numbers
  *For signed 2-byte integers, we could use packet start ID=0x7F.  
  *Our program would have to pre-limit integers so the largest MSB is 0x7E 
  *i.e., to x<= 32511 (0x7EFF) 
  *A sequence of two 0x7F's couldn't show up in valid data 
  *Consider two sequential data integers, 4 bytes = Lx Hx, Ly Hy
  *Case: data values Hx=0x7F and Lx=0x7F is not possible since x>=32639 
  *What if our timing is offset?
  *Case: Hx=0x7F and Ly=0x7F not possible in valid data since MSB Hx=0x7F 
  *not allowed
  *Summary: we gain the use of a unique identifier byte but lose 
  *some of the integer range. The max integer value is reduced from 0x7FFF (32767)
  *to 0x7EFF (32511) but we should still have all of the negative numbers
  R Kubichek 9/18
*/

#include <SoftwareSerial.h>

SoftwareSerial HC12(10, 11);      // HC-12 TX Pin, HC-12 RX Pin
boolean newVal = false;           //true if a new x-y pair is available
int state = 0;                    //where we are in the packet
int lx, hx, ly, hy;               //low and high bytes of x and y
int xval, yval;                   //x and y reconstructed values
long lastTrans = millis();        //time of last transmission
int Ttime = 100;                  //time between transmissions (much smaller won't work. collisions?)
byte packetStart = 0x7F;          //identifier for start of packet

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  pinMode(6, OUTPUT);             // set pin
  digitalWrite(6, LOW);           //incoming treated as AT commands
  delay(40);

  HC12.write("AT+DEFAULT"); delay(80);
  HC12.write("AT+C001"); delay(80);     //Transmit channel (1-100)
  HC12.write("AT+P4"); delay(80);       //Power level (1-8)
  digitalWrite(6, HIGH);  //go into transparent comm
  delay(80);              //give it time to return to transparent
}

void checkHC12() {  //checks for incoming bytes on HC12
  if (HC12.available() <= 0) return;
  int inVal = HC12.read();
  Serial.print(state);   //for debugging
  if (state == 0) {
    if (inVal == packetStart) state++;  //possible beginning of a packet
    return;
  }
  else if (state == 1) {
    if (inVal == packetStart) state++;  //packet start is confirmed
    else state = 0;               //not packet start. begin over
    return;
  }
  else if (state == 2) {
    lx = inVal;   //low byte of x
    state++;
    return;
  }
  else if (state == 3) {
    hx = inVal;  //high byte of x
    state++;
    return;
  }
  else if (state == 4) {
    ly = inVal;  //low byte of y
    state++;
    return;
  }
  else if (state == 5) {
    hy = inVal;  //high byte of y
    state = 0;  //done with this packet
    xval = lx + 256 * hx;
    yval = ly + 256 * hy;
    newVal = true;
    Serial.println();
  }
}

void loop() {
  checkHC12();   //Listen for incoming data

  if (newVal) {  //new data available.
    Serial.print(xval); Serial.print("  ");
    Serial.println(yval);
    newVal = false;
  }

  //check to see if conditions for transmission have been met
  if (state == 0 &&               //no incoming so channel clear
  millis()-lastTrans > Ttime) {   //enough elapsed time for another transmission
    lastTrans = millis();         //reset the timer
    int x = analogRead(A0);       
    int y = analogRead(A1);

    HC12.write(packetStart);      //identify beginning of packet
    HC12.write(packetStart);
    HC12.write(lowByte(x));
    HC12.write(highByte(x));
    HC12.write(lowByte(y));
    HC12.write(highByte(y));
  }
}
