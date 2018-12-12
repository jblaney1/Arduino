/****************************************
  Example pitch estimation sketch for the
  Adafruit Microphone Amplifier.
  Presents pitch estimate to a light bar consisting of 5 LEDs on pins 2,3,4,5,6.

  Works by counting the number of cycles in a short period (sampleWindow)
  and then dividing by sampleWindow to get pitch f0 = # cycles / time (sec)
  We count a cycle every time the wave goes from below zero to above zero.
  NOTE: this only works well for pure tones. Doesn't work well for complex sounds
  such as voice or music.

  Be sure to connect Adafruit mic to 3.3V, and to connect a wire from 3.3V to the AREF pin.
  Note: max sensitivity on Adafruit mic is achieved by turning screw on back fully CCW.

  Kubichek 4/2018
****************************************/

const int sampleWindow = 100; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
unsigned int prevsample = 0;
int micPIN = A0;   //pin connected to microphone
float pitch;
float Middle = 400;
float avgpitch = 500; //initial guess at pitch
float alpha = .05; //smaller=smoother average, larger=faster average
int minPitch = 500;   //lowest reliable pitch
int maxPitch = 2000;  //All LEDs light if pitch above this

void setup()
{
  Serial.begin(9600);
  analogReference(EXTERNAL);
  for (int i = 2; i < 7; i++) pinMode(i, OUTPUT); //5 LEDs on pins 2-6
}

void loop()
{
  int nzc = 0; //# zero crossings
  unsigned long startMillis = millis(); // Start of sample window
  // collect data for sampleWindow mS
  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(micPIN);
    Middle = alpha * sample + (1.0 - alpha) * Middle; //find the middle (average) amplitude
    if (prevsample < Middle && sample >= Middle) nzc++;  //must be a zero xing
    prevsample = sample;
  }
  pitch = (float) nzc / (float)sampleWindow * 1000.;
  avgpitch = alpha * pitch + (1.0 - alpha) * avgpitch; //average pitch

  //light the LEDs
  for (int i = 2; i < 7; i++) digitalWrite(i, LOW); //turn everything off
  int maxLED = map(avgpitch, minPitch, maxPitch, 2, 7); //maxLED ranges 2 to 6.999
  maxLED = constrain(maxLED, 1, 6); //make sure conforms to valid pin no
  for (int i = 2; i <= maxLED; i++) digitalWrite(i, HIGH);

  Serial.println(avgpitch); //output to serial plotter or monitor

}
