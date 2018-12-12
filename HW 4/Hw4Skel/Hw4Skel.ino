// EE2800 Homework #4
// Ultra Cylon Skeleton code to test soldering project.
// Fall 2018
// Joshua Blaney

int sw1 = 3;     // First Switch pin number
int sw2 = 4;     // Second Switch pin number

int LEDpin1[] = {2, 2, 5, 2, 5, 2, 5, 5, 2, 5, 2, 5, 5, 5, 5, 2, -1
                };
int LEDdur1[] = {20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 90, 70, 50, 30, 10, 20
                };
                
//define LEDpin2 here
int LEDpin2[] = {2,5,2,5,5,2,5,5,2,5,2,5,2,2,5,2,5,5,2,5,2,5,-1};

//define LEDdur2 here
int LEDdur2[] = {100,300,200,500,400,700,600,500,400,
                 200,300,100,300,200,500,400,700,600,500,400,20};

int pattern = 1; //startup pattern

void setup() {
  //various pinMode statements
  pinMode(2,OUTPUT);            // First LED pin
  pinMode(sw1,INPUT_PULLUP);    // First switch pin
  pinMode(sw2,INPUT_PULLUP);    // Second switch pin
  pinMode(5,OUTPUT);            // Other LED pin
}

void loop() {
    if (pattern == 1) {                                               // Conditional statement to see if the first blink pattern is used
      //blink pattern 1
      for(int k = 0; k < 16; k++){                                    // For statement to go through first blink pattern
         if (digitalRead(sw2) == LOW){ pattern = 2; break;}           // Check for change in switch 1, break the loop and execute other pattern
         digitalWrite(LEDpin1[k], HIGH);
         delay(LEDdur1[k]);
         digitalWrite(LEDpin1[k], LOW);
         delay(LEDdur1[k]);
  }
    }
    else {
      //blink pattern 2
      for(int k = 0; k < 21; k++){                                    // For statement to go through second blink pattern
         if (digitalRead(sw1) == LOW){ pattern = 1; break;}           // Check for change in switch 2, break loop and execute other pattern
         digitalWrite(LEDpin2[k], HIGH);
         delay(LEDdur2[k]);
         digitalWrite(LEDpin2[k], LOW);
         delay(LEDdur2[k]);
    }
  }
}
