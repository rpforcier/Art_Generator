//Libraries
#include "LightSound.h"
#include "Image.h"

//Control Variables
int statusFlag = 0;
int enableFlag = 0;

void setup()
{
  pinSetup();
  bootLightSound();
}

void loop()
{
    if (digitalRead(switchPin1) == LOW) {statusFlag = 1;}
    if (digitalRead(switchPin2) == LOW) {statusFlag = 2;}
    if (digitalRead(switchPin1) == HIGH && digitalRead(switchPin2) == HIGH) {statusFlag = 3;}
    if (digitalRead(startButtonPin) == LOW) {enableFlag = 1;}
    
    
    if (statusFlag == 1 && enableFlag == 0)
    {
      ledsOff(); 
      ledOn(1);
    }
    else if (statusFlag == 2 && enableFlag == 0)
    {
      ledsOff(); 
      ledOn(2);
    }
    else if (statusFlag == 3 && enableFlag == 0)
    {
      ledsOff(); 
      ledOn(3);
    }
    else if (enableFlag == 1)
    {
      createImage(statusFlag);
    }
}

void createImage(int flagNumber)
{
  ledsOff();
  playSong(2);
  ledOn(flagNumber);
  openPaintDrawImage(flagNumber);
  ledsOff();
  doneLightSound();
  statusFlag = 0;
  enableFlag = 0; 
}

