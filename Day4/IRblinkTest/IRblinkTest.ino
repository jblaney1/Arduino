/*
 * Modified version of IRrecvDemo. 
 * Here we add a blink function whose delay is controlled by IR
 * Skeleton code
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

int D=3000; //blink delay
int rightLED= 2;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(rightLED,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    if (results.value == 0xFF30CF)D=1000; //1 pushed
    //ADD IF STATEMENT FOR CASE 2 PUSHED
    //ADD IF STATEMENT FOR CASE 3 PUSHED
    //ADD IF STATEMENT FOR CASE 4 PUSHED
  }
  digitalWrite(rightLED,HIGH);
  delay(D);
  digitalWrite(rightLED,LOW);
  delay(D);
  }
