#include "Mouse.h"
#include "Keyboard.h"

void mouseMove(int x, int y) //Mouse Function to Overcome Mouse Acceleration
{
  if (x >= 0)
  {
    for (int i = 0; i < x; i++)
    {
      Mouse.move(1,0,0);
    }
  }
  else if (x < 0)
  {
    for (int i = 0; i < abs(x); i++)
    {
      Mouse.move(-1,0,0);
    }
  }

  if (y >= 0)
  {
    for (int i = 0; i < y; i++)
    {
      Mouse.move(0,1,0);
    }
  }
  else if (y < 0)
  {
    for (int i = 0; i < abs(y); i++)
    {
      Mouse.move(0,-1,0);
    }
  }
}

void keyRelease()
{
    delay(100);
    Keyboard.releaseAll();
}


void dot(int pixelSpacing) //Dot for Pixel Art
{
  Mouse.press();
  Mouse.release();
  mouseMove(pixelSpacing,0);
}

void noDot(int pixelSpacing) 
{
  mouseMove(pixelSpacing,0);
}
