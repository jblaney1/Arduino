/****************************************
  Example pitch estimation sketch for the
  Adafruit Microphone Amplifier.

  Works by counting the number of cycles in a short period (sampleWindow)
  and then dividing by sampleWindow to get pitch f0 = # cycles / time (sec)
  We count a cycle every time the wave goes from below zero to above zero.

  Be sure to connect Adafruit mic to 3.3V, and to connect a wire from 3.3V to the AREF pin.
  Note: max sensitivity on Adafruit mic is achieved by turning screw on back fully CCW.
  
  Kubichek 9/16
****************************************/

const int sampleWindow = 100; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
unsigned int prevsample = 0;
int micPIN = A0;   //pin connected to microphone
float pitch;
float avg=400;
float avgzc=0;
float avgpitch=500;  //initial guess at pitch
float alpha=.05;  //weight for sample

void setup()
{
  Serial.begin(9600);
  analogReference(EXTERNAL);
  }

void loop()
{
  int nzc = 0; //# zero crossings

  unsigned long startMillis = millis(); // Start of sample window

  // collect data for sampleWindow mS
  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(micPIN);
    avg = alpha*sample + (1.0-alpha)*avg;
    if (prevsample < avg && sample >= avg) nzc++;  
    prevsample = sample;
       //Serial.print(avg); Serial.print(" "); Serial.print(avgzc); Serial.print(" "), Serial.println(sample);
  }
   pitch = (float) nzc / (float)sampleWindow * 1000.;
   avgpitch = alpha*pitch+(1.0-alpha)*avgpitch;
   avgzc = alpha*nzc + (1.0-alpha)*avgzc;
   Serial.println(avgpitch);
}
