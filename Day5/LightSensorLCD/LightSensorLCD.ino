/*
   Light sensor.  Converts voltage to resistance to Lux. Outputs to serial monitor
   This versions adds in an LCD
   R. Kubichek, ECE department, University of Wyoming
*/

int lightPin = A0;        //pin connected to light sensor
int Rref = 10000; //voltage divider resistor
int blinkLED = 2; //blink when take sample
int alarmPin = 13;
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  //pin connections

void setup() {
  Serial.begin(9600);               // initialize serial comm at 9600 bps:
  pinMode(blinkLED, OUTPUT);
  lcd.begin(16, 2);
  pinMode(alarmPin,OUTPUT);
}

void loop() {
  if(tempf > 75){
    digitalWrite(alarmPin,HIGH);
  }
  else{
    digitalWrite(alarmPin,LOW);
  }
  digitalWrite(blinkLED, HIGH); //flash each time a measurement is made
  delay(10);
  digitalWrite(blinkLED, LOW);
  int rawLight = analogRead(lightPin);
  //convert raw analogin reading to resistance (see workshop notes)
  float Rldr = Rref * (1023.0 - rawLight) / rawLight;
  //convert resistance to Lux (see workshop notes)
  float Lux = pow(10.0, 6.64 - 1.32 * log10(Rldr));
  Serial.println(Lux);
  lcd.setCursor(0, 0);
  lcd.print("Light(Lux)         ");
  lcd.setCursor(11, 0);
  lcd.print(Lux);
  delay(500);
}
