/* Using DHT sensor
 *  This simple example reads the temperature and humidity and 
 *  outputs the values to the serial monitor
 */

#include <SimpleDHT.h>

int pinDHT11 = 5;  //DHT data pin
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);               // initialize serial comm at 9600 bps:
}

void loop() {
  delay(1000);  //the DHT11 sensor is slow so wait a couple secs
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
    Serial.print("   deg C =");          Serial.print(tempc);
    Serial.print("   deg F = ");      Serial.print(tempf);
    Serial.print("   Humidity% = ");  Serial.println(humid);
}
