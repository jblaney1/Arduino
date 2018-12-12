/* Plays 1 song
 *  Borrowed from several sources including:
 * http://garagelab.com/profiles/blogs/how-to-use-tone-function-arduino-playing-the-james-bond-theme
 * https://gist.github.com/pyropeter/671426
 */

#include "pitches.h"

//Songs

int Jepardy[] = {
  NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2,
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_C3, NOTE_F3, NOTE_C3, NOTE_F3,
  NOTE_AS3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_CS3,
  NOTE_C3, NOTE_F3, NOTE_C3, NOTE_A2, // the same again
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_AS3, 0, NOTE_G3, NOTE_F3,
  NOTE_E3, NOTE_D3, NOTE_CS3, NOTE_C3, 0
  };

// note duration: 1 = whole note, 2 = half note, 4 = quarter note, 8 = eighth note, etc.
int JepardyDurations[] = {
  4,    4,    4,    4,
  4,    4,          2,
  4,    4,    4,    4,
  3,   8, 8, 8, 8, 8,
  4,    4,    4,    4, // the same again
  4,    4,          2,
  4, 8, 8,    4,    4,
  4,    4,    4,    4,
  0};

int wholeNote = 1000; // lentgh of a whole note in ms 
int buzzPin = 8;

void setup() {}

void loop(){
  for (int thisNote = 0; JepardyDurations[thisNote] != 0; thisNote++) {
    // Note duration = one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = wholeNote/JepardyDurations[thisNote];
    tone(buzzPin, Jepardy[thisNote],noteDuration * 0.9);
    delay(noteDuration); //pause between notes
  }
}

