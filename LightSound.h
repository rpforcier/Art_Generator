#include "SoundData.h"

//Button, Speaker, and LED Variables
const int switchPin1 = A0,
          switchPin2 = A1,
          startButtonPin = A2;
          
const int ledPin1 = A5,
          ledPin2 = A3,
          ledPin3 = A4;

const int speakerPin = 11;

void pinSetup()
{
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  pinMode(startButtonPin, INPUT_PULLUP);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void playSong(int songNumber)
{
  int *melody;
  int *noteLength;
  int numNotes;

   switch(songNumber) 
   {
    case 1:
          melody = &melodyStartup[0];
          noteLength = &noteLengthStartup[0];
          numNotes = numNotesStartup;
        break;
    case 2:
          melody = &melodyImageStart[0];
          noteLength = &noteLengthImageStart[0];
          numNotes = numNotesImageStart;
        break;
    case 3:
          melody = &melodyImageDone[0];
          noteLength = &noteLengthImageDone[0];
          numNotes = numNotesImageDone;
        break;
    }
    
  for (int thisNote = 0; thisNote < numNotes; thisNote++)
  {
    tone(speakerPin, *melody, *noteLength);
    delay(*noteLength);
    noTone(speakerPin);
    melody++; noteLength++;
  }
}

void bootLightSound()
{ 
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);

  playSong(1);
  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}

void ledsOff()
{
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}

void ledsOn()
{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
}

void ledOn(int ledNumber)
{
  if (ledNumber == 1) {digitalWrite(ledPin1, HIGH);}
  else if (ledNumber == 2) {digitalWrite(ledPin2, HIGH);}
  else if (ledNumber == 3) {digitalWrite(ledPin3, HIGH);}
}

void doneLightSound()
{ 
  for (int j = 0; j < 3; j++)
  {
  ledsOn();
  delay(300);
  ledsOff();
  delay(300);
  }

  ledsOn();
  
  playSong(3);
  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}

