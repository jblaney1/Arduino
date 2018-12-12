// Midterm Handson Exam Portion
// Oct 17, 2018
// Joshua Blaney

int Potpin = A0, LEDpin = 2, button = 3, dt = 5, A = 8, B = 9, C = 10, D = 11, n = 0;
long t0, t1;
float elapsed;
int previousSw = HIGH, On = LOW;
boolean pause = false;

void setup() {
  Serial.begin(9600);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(LEDpin,OUTPUT);
}

void loop() {
  int currentSw;
  t0 = millis();
  while(!pause)
  {
    currentSw = digitalRead(button);
    if (previousSw != currentSw){delay(10);}
    if (currentSw == LOW && previousSw == HIGH){pause = true;}
    dt = map(analogRead(Potpin), 0, 1023, 4, 13);
    cw();
    n++;
    if(n%10 == 0)
    {
      On = !On;
      digitalWrite(LEDpin, On);
    }
  }
  pause = false;
  t1 = millis();
  elapsed = (t1-t0);
  delay(500);
  Serial.print("Elapsed time in seconds: ");
  Serial.println(elapsed/1000.0);
  Serial.print("Number of steps: ");
  Serial.println(n*4);
  while(!pause){
  currentSw = digitalRead(button);
  if (previousSw != currentSw){delay(5);}
  if (currentSw == LOW && previousSw == HIGH){pause = true;}
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  }
  delay(500);
  n = 0;
  t0 = 0;
  t1 = 0;
  pause = false;
}

void cw(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  delay(dt);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  delay(dt);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  delay(dt);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  delay(dt);
}
