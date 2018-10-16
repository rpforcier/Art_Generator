/*
//Led SCrolling Animation
int currentTimeLed = 0;
int previousTimeLed = 0;
int ledInterval = 100;

int ledState = LOW;
int currentLed = 21;

void ledScroll()
{
  currentTimeLed = millis();
  
  if (currentTimeLed - previousTimeLed > ledInterval && ledState == LOW)
  {
    ledState = HIGH;
    previousTimeLed = currentTimeLed;
    digitalWrite(currentLed, ledState);
  }
  else if (currentTimeLed - previousTimeLed > ledInterval && ledState == HIGH)
  {
    ledState = LOW;
    previousTimeLed = currentTimeLed;
    digitalWrite(currentLed, ledState);
    currentLed++;
  }

  if (currentLed == 24) {currentLed = 21;} //Reset Led Number
    
}
*/
