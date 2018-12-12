/*    Arduino Long Range Wireless Communication using HC-12
  Ref:  www.HowToMechatronics.com
  RK 8/18
  Reads a packet containing two integers (4 bytes), X and Y
  Packet is started by 0xFF
*/

#include <SoftwareSerial.h>

SoftwareSerial HC12(11, 12);      // HC-12 TX Pin, HC-12 RX Pin
boolean newVal = false;           //true if a new x-y pair is available
int state = 0;                    //where we are in serial stream
int lx, hx, ly, hy;               //low and high bytes of x and y
int xval, yval;                   //x and y reconstructed values

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  pinMode(13, OUTPUT);             // set pin
  digitalWrite(13, LOW);           //incoming treated as AT commands
  delay(40);

  HC12.write("AT+DEFAULT"); delay(80);
  HC12.write("AT+C001"); delay(80);
  HC12.write("AT+P4"); delay(80);
  digitalWrite(13, HIGH);  //go into transparent comm
  delay(80);              //give it time to return to transparent
}

//packet format is:       0xFF 0xFF lowByteX highByteX lowByteY highByteY
//corresponds to state 0   1    2       3       4          5
//state 0 means we are still searching for a packet start
//state 1 means we have found the first 0xFF.  and so on.
void checkHC12() {
  if (HC12.available() <= 0) return;
  int inVal = HC12.read(); //get one byte
  //Serial.print(state);
  if (state == 0) {
    if (inVal == 0xFF) state++;             //possible beginning of a packet
    return;
  }
  else if (state == 1) {
    if (inVal == 0xFF) state++;             //packet start is confirmed
    else state = 0;                         //not packet start. begin over
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
    //Serial.println();
  }
}

void loop() {
  checkHC12();
  if (newVal) {
    Serial.print(xval); Serial.print("  ");
    Serial.println(yval);
    newVal = false;
  }
}
