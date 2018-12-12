/*
 * Example code for running a DC motor using the TI L293D motor controller (H-bridge) chip
 * EE2800 Fall 2800, Kubichek
 */
float SpeedOfSound = 0.0343; //cm/us sea level
const int MAX_DISTANCE = 250; //trustworthy range
float AvgDist = 0; //average distance
float alpha = .9;  //averaging speed
int echoPin = 3;
int trigPin = 2;


int enable1 = 10;
int enable2 = 9;
int dir2A = 5;
int dir2B = 6; 
int sw = 4;
int Mspeed = 0;     //PWM motor speed
int prevsw = LOW;

void setup() {
  pinMode(enable1, OUTPUT);
  pinMode(sw, INPUT_PULLUP);  
  pinMode(enable2, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(dir2B, OUTPUT);

  digitalWrite(enable1, LOW); // initially motor off
  digitalWrite(enable2, LOW); // initially motor off
  digitalWrite(dir2A, LOW);   //turn cw
  digitalWrite(dir2B, HIGH);
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
   /*
    * loop code does following:
    *    Reads the switch
    *    If there is a transition from High to Low, increase motor speed.
    *    If motor speed exceeds the max PWM value of 255, reset it to zero.
    *    Use analogWrite (PWM) to turn on the motor to the proper speed
    *    Note, we are using PWM on the motor's enable pin.
    *    Alternatively we could use PWM on the DIR pins and hold the Enable pin High
    *    SInce you only have one motor, you only need to use analogWrite to one side.
    */
      digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  while(digitalRead(echoPin)==LOW){}
  float t0 = micros();
  while(digitalRead(echoPin)){}
  float duration = micros()-t0;
  float distance = (duration / 2.0) * SpeedOfSound;
  if(distance < MAX_DISTANCE){
    AvgDist = alpha * AvgDist + (1 - alpha) * distance;
    Serial.print(distance);
    Serial.print(" ");
    Serial.println(AvgDist);
  }
    int cursw = digitalRead(sw);
    Mspeed = AvgDist + 100;
    prevsw = cursw;
    if (Mspeed > 250) Mspeed = 0;
    analogWrite(enable2, Mspeed);
}
