/*
 * Modified version of IRrecvDemo. 
 * Here we add a blink function whose delay is controlled by IR
 * Skeleton code
 */

#include <IRremote.h>

int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;

int D, rightLED = 2;


void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(rightLED,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(irrecv.decode(&results) == 0xFF30CF){D=1000;}
    if(irrecv.decode(&results) == 0xFF18E7){D=500;}
    if(irrecv.decode(&results) == 0xFF7A85){D=100;}
    if(irrecv.decode(&results) == 0xFF10EF){D=50;}
    irrecv.resume(); // Receive the next value
  }
  digitalWrite(rightLED,HIGH);
  delay(D);
  digitalWrite(rightLED, LOW);
  delay(D);
}

