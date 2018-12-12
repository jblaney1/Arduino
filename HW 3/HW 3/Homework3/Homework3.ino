/*
  EE2800 F18.
  Joshua Blaney
  Sept 27, 2018
*/

//include necessary libraries (i.e., LCD and DHT)
#include <LiquidCrystal.h>
#include <SimpleDHT.h>
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);

//variable declaration and initialization
long t0 = millis();
int micPIN = A0;
int potPIN = A2;
int dcVoltage = 387;   
float avgVol = 0.0;
float alpha = .99;
int pinDHT11 = 2;
SimpleDHT11 dht11;
int leds[] = {9,10,11,12,13};


void setup()
{
  Serial.begin(9600);
  
  //here include the setup code for the microphone
  analogReference(EXTERNAL);
  pinMode(micPIN, INPUT);
  
  //here include pinMode statements for all GPIO pins used
  for (int i = 0; i < 5; i++)
  {
    pinMode(leds[i],OUTPUT);
  }
  
  //here include initialization code for the lcd
  lcd.begin(16, 2);
}
void loop()
{
  //code to read the microphone and find a running average
  int sample = analogRead(micPIN) - dcVoltage;
  int vol = abs(sample);
  avgVol = alpha * avgVol + (1.0 - alpha) * vol;
  
  //convert the running average sound level to dB
  float dB = 20.0 * log10(avgVol);
  
  //Read the pot and add the value to the dB value 
  float potVal = analogRead(potPIN)/16.0;
  float Xdb = dB + potVal;
  
  //Turn on/off the LEDs to implement the light gauge
  if(Xdb > 50){digitalWrite(leds[0],HIGH);}else{digitalWrite(leds[0],LOW);}
  if(Xdb > 56){digitalWrite(leds[1],HIGH);}else{digitalWrite(leds[1],LOW);}
  if(Xdb > 62){digitalWrite(leds[2],HIGH);}else{digitalWrite(leds[2],LOW);}
  if(Xdb > 68){digitalWrite(leds[3],HIGH);}else{digitalWrite(leds[3],LOW);}
  if(Xdb > 74){digitalWrite(leds[4],HIGH);}else{digitalWrite(leds[4],LOW);}
      
  if (millis() - t0 > 1000) {  //do the following once per second
    t0 = millis(); //reset the clock
    
    //code to measure the temperature and humidity
    byte temperature = 0;
    byte humidity = 0;
    byte data[40] = {0};
    dht11.read(pinDHT11, &temperature, &humidity, data);
    int tempc = (int) temperature;
    float tempf = temperature * 1.8 + 32.0;
    int humid = (int) humidity;
    
    //code to update the LCD
    lcd.setCursor(0, 0);
    lcd.print("Sound dB:         ");
    lcd.setCursor(11, 0);
    lcd.print(Xdb);
    lcd.setCursor(0,1);
    lcd.print("TF=");      
    lcd.print(tempf);
    lcd.print("   H%=");  
    lcd.println(humid);
  }
}
