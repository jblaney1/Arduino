/*
   Light sensor.  Converts voltage to resistance to Lux. Outputs to serial monitor
   This versions adds in an LCD and DHT11 temp/humidity sensor
   R. Kubichek, ECE department, University of Wyoming

   DHT code taken from Elegoo Lesson 19
*/

int lightPin = A0;        //pin connected to light sensor
int Rref = 10000; //voltage divider resistor for light sensor
int blinkLED = 2; //blink when take sample
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  //pin connections
#include <SimpleDHT.h>

int pinDHT11 = 5;  //DHT data pin
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);               // initialize serial comm at 9600 bps:
  pinMode(blinkLED, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  delay(1000);  //the DHT11 sensor is slow so wait 
  digitalWrite(blinkLED, HIGH); //flash each time a measurement is made
  delay(10);
  digitalWrite(blinkLED, LOW);
  int rawLight = analogRead(lightPin);
  //convert raw analogin reading to resistance (see workshop notes)
  float Rldr = Rref * (1023.0 - rawLight) / rawLight;
  //convert resistance to Lux (see workshop notes)
  float Lux = pow(10.0, 6.64 - 1.32 * log10(Rldr));

  //temp and humidity
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.println("Read DHT11 failed");
    return;
  }
  int tempc = (int) temperature; //convert from byte to int
  float tempf = temperature * 1.8 + 32.0;
  int humid = (int) humidity; //convert from byte to int
  //Pretty output to serial monitor
  //  Serial.print("Lux = "); Serial.print(Lux); 
  //  Serial.print("   deg C =");          Serial.print(tempc);
  //  Serial.print("   deg F = ");      Serial.print(tempf);
  //  Serial.print("   Humidity% = ");  Serial.println(humid);
  //Use this un-pretty output if we just want to copy/paste data or use serial plotter
  Serial.print(Lux); Serial.print("    ");
  Serial.print(tempf); Serial.print("     ");
  Serial.println(humid);

  //Update the LCD
  lcd.setCursor(0, 0);
  lcd.print("Light(Lux)      ");  //16 characters defined
  lcd.setCursor(11, 0);
  lcd.print(Lux);
  lcd.setCursor(0, 1);
  lcd.print("TF=       H%=    ");
  lcd.setCursor(3, 1);
  lcd.print(tempf);
  lcd.setCursor(13, 1);
  lcd.print(humid);
}
