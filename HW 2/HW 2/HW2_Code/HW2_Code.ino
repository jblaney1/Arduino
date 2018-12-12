
/*
   EE2800-01 (Arduino Section)
   Skeleton code to help you get started with Homework #2
*/

// Joshua Blaney
// 9/19/2018
// Design Experience with Devices

//You need to provide all of the global variable declarations here
int prevBut = 0,
  butCnt = -1, 
  switchPin = 2,
  vpin = A5,
  rpin = A0,
  luxPin = A1,
  L1 = 3,
  L2 = 4,
  L3 = 5,
  L4 = 6,
  L5 = 7,
  Led1 = 8,
  Led2 = 9,
  Led3 = 10;
float voltage,
  R,
  lux;
  
void setup() {
  //use pinMode to set up all of the pins as INPUT or OUTPUT here
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  pinMode(L5,OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(vpin, INPUT);
  pinMode(rpin, INPUT);
  pinMode(luxPin, INPUT);
  pinMode(switchPin, INPUT_PULLUP);
  
  Serial.begin(9600);  //in case you want to output to Serial Monitor
}
void loop() {
  //The following code is provided to count button pushes. Please make sure you understand it!
  int curBut = digitalRead(switchPin);
  if (curBut != prevBut) delay(20); //debounce
  if (prevBut == HIGH && curBut == LOW) butCnt = butCnt + 1;  //count number of button pushes
  prevBut = curBut;

  //You need to check if butCnt is larger than 2: if so set it equal to zero.
  if (butCnt > 2){butCnt = 0;}
  //Here you need to put in the code to turn on/off LED1, LED2, and LED3 depending on butCnt
  
  if (butCnt == 0){
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);}
  else if (butCnt == 1){
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, LOW);}
  else if (butCnt == 2){
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, HIGH);}
    
  //Start off with all five LEDs (L1-L5) turned off. Put that code here.
  
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
      
  if (butCnt == 0) { // voltmeter
    //here you put the code to implement the voltmeter

    // Calculate the voltage
    voltage = 5.0 * (analogRead(vpin)/1023.0);

    // Turn on the correct lights
    if(voltage < 1){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
    }
    else if(voltage < 2){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
    }
    else if(voltage < 3){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
    }
    else if(voltage < 4){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,HIGH);
      digitalWrite(L5,LOW);
    }
    else if(voltage <= 5){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,HIGH);
      digitalWrite(L5,HIGH);
    }
  }

  //check if butCnt==1. Here you put the code to implement the ohmmeter
  if (butCnt == 1){

    // Calculate the Resistance
    R = 1000.0 * (1023.0 - analogRead(A0))/analogRead(A0);

    // Turn on the correct lights
    if ((R > 198) && (R < 242)){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
    }
    else if ((R > 297) && (R < 363)){
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
    }
    else if ((R > 900) && (R < 1100)){
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
    }
    else if ((R > 9000) && (R < 11000)){
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,HIGH);
      digitalWrite(L5,LOW);
    }
    else{
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      digitalWrite(L5,HIGH);
    }
    
  }
  //check if butCnt==2. Here you put the code to implement the light meter
  if (butCnt == 2){

    // Calculate the LUX
    float rawLight = analogRead(luxPin);
    float Rldr = 10000.0 * (1023.0 - rawLight)/rawLight;
    lux = pow(10.0,6.64 - 1.32 * log10 (Rldr));


    // Turn on the correct lights
    if (lux > 400){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,HIGH);
      digitalWrite(L5,HIGH);
    }
    else if (lux > 300){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,HIGH);
      digitalWrite(L5,LOW);
    }
    else if (lux > 200){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,HIGH);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
    }
    else if (lux > 100){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,HIGH);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
    }
    else if (lux > 50){
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
    }
    else{
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
      digitalWrite(L5,LOW);
    }
  }
}
