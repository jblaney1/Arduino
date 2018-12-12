/* Borrowed from:
   http://garagelab.com/profiles/blogs/how-to-use-tone-function-arduino-playing-the-james-bond-theme
   https://gist.github.com/pyropeter/671426
   http://www.princetronics.com/supermariothemesong/
*/

#include "pitches.h"

//Songs
int Mario[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

int Bond[] = {
  //Introduction
  NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_DS5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_B4,
  NOTE_E4, NOTE_G4, NOTE_DS5, NOTE_D5, NOTE_G4, NOTE_B4,
  NOTE_B4, NOTE_FS5, NOTE_F5, NOTE_B4, NOTE_D5, NOTE_AS5,
  NOTE_A5, NOTE_F5, NOTE_A5, NOTE_DS6, NOTE_D6
};
int Jepardy[] = {
  NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2,
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_C3, NOTE_F3, NOTE_C3, NOTE_F3,
  NOTE_AS3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_CS3,
  NOTE_C3, NOTE_F3, NOTE_C3, NOTE_A2, // the same again
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_AS3, 0, NOTE_G3, NOTE_F3,
  NOTE_E3, NOTE_D3, NOTE_CS3, NOTE_C3
};

// note duration: 1 = whole note, 2 = half note, 4 = quarter note, 8 = eighth note, etc.

//Mario main them tempo
int marioDurations[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 
  0   //this zero flags end of array
};

int BondDurations[] = {
  8, 16, 16, 8, 4, 8, 8, 8,
  8, 16, 16, 8, 4, 8, 8, 8,
  8, 16, 16, 8, 4, 8, 8, 8,
  8, 16, 16, 8, 4, 8, 8, 8,
  8, 2, 8, 8, 1,
  8, 4, 8, 4, 8, 8,
  8, 8, 4, 8, 4, 8,
  4, 8, 4, 8, 3, 
  0   //this zero flags end of array
};
int JepardyDurations[] = {
  4,    4,    4,    4,
  4,    4,          2,
  4,    4,    4,    4,
  3,   8, 8, 8, 8, 8,
  4,    4,    4,    4, // the same again
  4,    4,          2,
  4, 8, 8,    4,    4,
  4,    4,    4,    4,
  0  //this zero flags end of array
};

int wholeNote = 1450; // change pace of music("speedy")
int song = 0;    //select a song
int buzzPin = 8;


void setup() {}

void loop() {
  if (song == 0) {
    singsong(marioDurations, Mario);
  }
  else if (song == 1) {
    singsong(BondDurations, Bond);
  }
  else {
    singsong(JepardyDurations, Jepardy);
  }
}

void singsong(int dur[], int mel[]) {
  //following loop goes until it hits a zero in the dur array
  for (int thisNote = 0; dur[thisNote] != 0; thisNote++) {
    // Note duration = one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = wholeNote / dur[thisNote];
    tone(buzzPin, mel[thisNote], noteDuration * 0.9);
    delay(noteDuration); //pause between notes
  }
}

