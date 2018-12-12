/*
   Merges the IR and LCD code
   R. Kubichek, ECE department, University of Wyoming
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  //pin connections

#include <IRremote.h>
int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

int led = 2, D = 1000;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);               // initialize serial comm at 9600 bps:
  lcd.begin(16, 2);    // Start the LCD
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  lcd.setCursor(0, 0);
  lcd.print("HEX value rcvd  ");  //16 characters defined
}

void loop() {
  if (irrecv.decode(&results)) {
     if (results.value == 0xFF30CF){
     digitalWrite(led, HIGH);
     delay(D);
     digitalWrite(led, LOW);
     delay(D);}
     else if (results.value == 0xFF18E7){
     for(int i = 0; i < 2; i++)
     {
     digitalWrite(led, HIGH);
     delay(D);
     digitalWrite(led, LOW);
     delay(D);}
     }
     else if (results.value == 0xFF7A58){
      for(int i = 0; i < 3; i++)
     {
     digitalWrite(led, HIGH);
     delay(D);
     digitalWrite(led, LOW);
     delay(D);}
     }
     }
     else if (results.value == 0xFF10EF){
      for(int i = 0; i < 4; i++)
     {
     digitalWrite(led, HIGH);
     delay(D);
     digitalWrite(led, LOW);
     delay(D);}
     }
     }
    lcd.setCursor(0, 1);
    lcd.print("________________");
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    //Update the LCD
    lcd.setCursor(0, 1);
    lcd.print(results.value, HEX);
  }
}
