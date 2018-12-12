/*    Arduino Long Range Wireless Communication using HC-12
            Based on www.HowToMechatronics.com
  Sends a packet containing 2 integers, derived from x and y joystick. 
  Packet header is 0xFFFF
  RK 8/18
*/

#include <SoftwareSerial.h>

SoftwareSerial HC12(10, 11);            // HC-12 TX Pin, HC-12 RX Pin

void setup() {
  Serial.begin(9600);                   // Serial port to computer
  HC12.begin(9600);                     // Serial port to HC12
  pinMode(6, OUTPUT);                   // set pin
  digitalWrite(6, LOW);                 //incoming treated as AT commands
  delay(40);
  HC12.write("AT+DEFAULT"); delay(80);
  HC12.write("AT+C001"); delay(80);
  HC12.write("AT+P4"); delay(80);
  digitalWrite(6, HIGH);                //go into transparent comm
  delay(80);                            //give it time to return to transparent
}

void loop() {
  int x = analogRead(A0);       
  int y = analogRead(A1);
  HC12.write(0xFF);
  HC12.write(0xFF);
  HC12.write(lowByte(x));
  HC12.write(highByte(x));
  HC12.write(lowByte(y));
  HC12.write(highByte(y));
  delay(15);  //Make sure softwareSerial can keep up (about 10ms is minimum)
}
