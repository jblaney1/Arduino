//EE2800
//This sketch decodes the IR Remote signals
//Only some of the codes are represented here
//The remaining codes represented by ?????? must be filled in by the student

#include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void translateIR() {
  // takes action based on IR code received
  switch (results.value)
  {
    case 0xFFA25D: Serial.println("POWER"); break;
    case 0xFFE21D: Serial.println("FUNC/STOP"); break;
    case 0xFF629D: Serial.println("VOL+"); break;
    case 0xFF22DD: Serial.println("FAST BACK");    break;
    //the following case values must be provided by the student
    //Then the "//" can be remove to make the statement active
    //  case 0x??????: Serial.println("PAUSE");    break;
    //  case 0x??????: Serial.println("FAST FORWARD");   break;
    //  case 0x??????: Serial.println("DOWN");    break;
    //  case 0x??????: Serial.println("VOL-");    break;
    //  case 0x??????: Serial.println("UP");    break;
    //  case 0x??????: Serial.println("EQ");    break;
    //  case 0x??????: Serial.println("ST/REPT");    break;
    //  case 0x??????: Serial.println("0");    break;
    //  case 0x??????: Serial.println("1");    break;
    //  case 0x??????: Serial.println("2");    break;
    //  case 0x??????: Serial.println("3");    break;
    //  case 0x??????: Serial.println("4");    break;
    //  case 0x??????: Serial.println("5");    break;
    //  case 0x??????: Serial.println("6");    break;
    //  case 0x??????: Serial.println("7");    break;
    //  case 0x??????: Serial.println("8");    break;
    //  case 0x??????: Serial.println("9");    break;
    //  case 0x??????: Serial.println(" REPEAT");break;
    default:
      Serial.println(" other button   ");
  }
  delay(500);
}

void setup()   
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn(); // Start the receiver
}

void loop()   
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR();
    irrecv.resume(); // receive the next value
  }
}

