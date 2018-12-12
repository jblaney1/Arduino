/*
  Merges the IR and LCD code
  Skeleton code for Challenge #3
  NOTE: some code is missing - you have to figure it out
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  //pin connections

#include <IRremote.h>
int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);               // initialize serial comm at 9600 bps:
  lcd.begin(16, 2);    // Start the LCD
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  lcd.setCursor(0, 0);  //display top row of LCD. Doesn't change 
  lcd.print("HEX value rcvd  ");  //16 characters defined
  pinMode(LEDpin, OUTPUT);
}

void blinkit(int nblink) {
  //blinks the LED nblink times
  for (int k = 0; k < nblink; k++) {
    digitalWrite(LEDpin, HIGH);
    delay(100);
    digitalWrite(LEDpin, LOW);
    delay(100);
  }
}
void loop() {
  if (irrecv.decode(&results)) {

    if (results.value == 0xFF30CF) blinkit(1); //1 pushed
    else if       <missing code>               //2 pushed
    else if                                    //3 pushed
    else if                                    //4 pushed
    else blinkit(10);

    lcd.setCursor(0, 1);
    lcd.print("________________");  //clear the display
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    //Update the LCD
    lcd.setCursor(0, 1);
    lcd.print(results.value, HEX);
    delay(1000);
  }
}
