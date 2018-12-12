/*      Skeleton code for homework #5

  Ref:  www.HowToMechatronics.com
    Includes software for using HC12 as Receiver
    You must enter code to operate stepper motor.
    Lots of hints are provided below in ALL CAPS
    For example, here is a good hint:
    YOUR BREADBOARD SHOULD HAVE LEDS AND RESISTORS ON PINS 9 AND 12
*/

#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11);      // HC-12 TX Pin, HC-12 RX Pin
boolean newVal = false;           //true if a new x-y pair is available
int state = 0;                    //where we are in serial stream
int lx, hx, ly, hy;               //low and high bytes of x and y
long int xval, yval;                   //x and y reconstructed values
boolean ledState = false;         //flashing LED when radio is receiving data

//FILL IN THE FOLLOWING 2 VALUES
int neutral = 498;                 //joystick value when not pushed. Put in your value
int deadzone = 20;                //No motor for when:  neutral-deadzone < xval < neutral+deadzone 

//INCLUDE HERE ANY VARIABLE DECLARATIONS NEEDED FOR STEPPER

int yLED = 9;                     //SEE HOMEWORK ASSIGNMENT FOR DESCRIPTION OF THIS LED
int ledPin = 12;                  //DITTO

#include <Servo.h>

Servo myservo;

int pos = 0, dt = 0, A = 5, B = 4, C = 3, D = 2;

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  pinMode(6, OUTPUT);             // set pin
  digitalWrite(6, LOW);           //incoming treated as AT commands
  delay(40);
  pinMode(ledPin, OUTPUT);
  HC12.write("AT+DEFAULT"); delay(80);
  
  //PICK A UNIQUE COMMUNICATION CHANNEL AS DISCUSSED IN HOMEWORK HANDOUT
  HC12.write("AT+C001"); delay(80);
  HC12.write("AT+P4"); delay(80);
  digitalWrite(6, HIGH);  //go into transparent comm
  delay(80);              //give it time to return to transparent

  //INCLUDE HERE ANY SETUP CODE FOR STEPPER MOTOR
  pinMode(yLED, OUTPUT);          //SEE HOMEWORK DESCRIPTION FOR DESCRIPTION OF THIS LED
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  myservo.attach(12);
}

//YOU DO NOT HAVE TO MODIFY THE "checkHC12" FUNCTION.
//BUT YOU SHOULD TRY TO UNDERSTAND IT
void checkHC12() {
  /* packet format is:       0xFF 0xFF lowByteX highByteX lowByteY highByteY
     corresponds to state 0   1    2       3       4          5
     state 0 means we are still searching for beginning of a packet
     state 1 means we have found the first 0xFF.  
     state 2 means we have found the second 0xFF, next byte is lowByteX
     state 3, 4, 5, for remaining bytes.  
  */ 
  if (HC12.available() <= 0) return;  //Nothing incoming on the radio waves
  int inVal = HC12.read();            //get one byte
  // Serial.print(state);
 // Serial.print("inVal: ");
  //Serial.println(inVal);
  if (state == 0) {
    if (inVal == 0xFF) state++;             //possible beginning of a packet
    return;  //return #1                    (used in homework question)
  }
  else if (state == 1) {
    if (inVal == 0xFF) state++;             //packet start is confirmed
    else state = 0;                         //not packet start. begin over
    return;  //return #2
  }
  else if (state == 2) {                    //now we're reading the 4 byte payload
    lx = inVal;   //low byte of x
    state++;
    return;  //return #3
  }
  else if (state == 3) {
    hx = inVal;  //high byte of x
    state++;
    return;  //return #4
  }
  else if (state == 4) {
    ly = inVal;  //low byte of y
    state++;
    return;  //return #5
  }
  else if (state == 5) {                    //last byte of a packet. Finish up.
    hy = inVal;   //high byte of y
    state = 0;                              //done with this packet, get ready for next
    xval = lx + 256 * hx;
//    Serial.println(lx);
//    Serial.println(hx);
//    Serial.println(xval);
    yval = ly + 256 * hy;
    
    if (xval < 0 || xval > 1024) return; //make sure it's a valid number
    if (yval < 0 || yval > 1024) return; //sometimes we get noise
    newVal = true;
    ledState = !ledState;               //causes LED to flash for healthy comm link
 //   Serial.println();
    return;   //return #6               //this return not really needed
  }
}

//YOU DO NOT HAVE TO MODIFY THE "flushHC12" FUNCTION
void flushHC12() {
  //If data received faster can process it, HC12 buffer fills up, i.e., more than 1 byte available.
  //Our program isn't smart enough to deal with this, causing it to get stuck.
  //Easiest thing to do is just flush everything except the most recent byte.
  while (HC12.available() > 1) HC12.read();  //read and throw away all but last byte
}

//THE LOOP FUNCTION IS PROVIDED FOR YOU. ONLY ONE SLIGHT MODIFICATION NEEDED.
//PLEASE BE SURE YOU UNDERSTAND WHAT'S GOING ON - ESPECIALLY THE USE OF 'MAP'
//FAIR WARNING: THIS COULD BE ON A TEST...
void loop() {
  flushHC12();    //if more than 1 byte available, flush all but most recent
  checkHC12();    //if received byte is available, process it
  if (newVal) {   //we have successfully received new xval and yval
    newVal = false;
    digitalWrite(ledPin, ledState);  //flash to indicate radio link is working

//FOLLOWING COMMAND IS MISPELLED TO MAKE SURE YOU FIX IT AND UNDERSTAND IT
//analogWrite "USES PULSE-WIDTH MODULATION" (PWM). VALUES MUST BE BETWEEN 0 and 255.
//    analogWrite(yLED, yval/4);   //DIVIDE BY 4 TO ENSURE 0<=value<=255
    analogWrite(yLED, yval / 4);   //DIVIDE BY 4 TO ENSURE 0<=value<=255
    //HINT:  UNDERSTAND WHAT'S GOING ON HERE.
    //Use map to get dt delay values ranging from 2 (fast stepper) to 30 (slow stepper)
    if (xval > neutral + deadzone) {  //only respond to significant joy stick movement
      dt = map(abs(xval - neutral), 0, 1023 - neutral, 30, 2); //more joy less delay
      //dt=5;
      Serial.print("cw "); Serial.println(dt); 
        cw(); 
    }
    else if (xval < neutral - deadzone) {
      dt = map(abs(neutral - xval), 0, neutral, 30, 2); //more joy less delay
      //dt=5;
      Serial.print("cw "); Serial.println(dt); 
        ccw(); 
    }
  }
}

//COPY IN YOUR CW() AND CCW() FUNCTIONS HERE

void ccw(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  delay(dt);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  delay(dt);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  delay(dt);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  delay(dt);
}

void cw(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  delay(dt);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  delay(dt);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  delay(dt);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  delay(dt);
}
