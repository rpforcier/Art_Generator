#include "ImageData.h"
#include "MouseKeyboard.h"

int pixelSpacing = 7;

void openPaint()
{
    Mouse.begin();
    Keyboard.begin();

    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_ESC);
    delay(250);
    keyRelease();
    
    Keyboard.write('p');
    delay(250);
    Keyboard.write('a');
    delay(250);
       
    Keyboard.press(KEY_RETURN);
    keyRelease();
    delay(2500);
    
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press((char) 32);
    Keyboard.press('x'); 
    keyRelease();
    delay(2500);;
}

void readyImage()
{
  mouseMove(-2500,-2500); //Move to Origin
  mouseMove(1100,140); // Move to Thickness Select
  Mouse.press(); //Select Thickness
  mouseMove(0,280);
  delay(250);
  Mouse.release();
  mouseMove(-500,-150); //Move to Start Position
  delay(2500); 
}

int imageRead(int imageBitmap[], int pixelNumber)
{
    int byteIndex = 0;
    int bitIndex = -1;

    for (int i = 0; i < pixelNumber+1; i++) //Determines a Pixel's Bit and Byte Location (Ex: Byte 20, Bit 0)
    {
      bitIndex++;
      
      if (bitIndex == 8)
      {
        byteIndex++;
        bitIndex = 0;
      }
    }
    
    int imageByte = pgm_read_byte_near(imageBitmap+byteIndex); //Reads Correct Byte from Array
    int imageBit = bitRead(imageByte, bitIndex); // Reads Bit from Byte
    return imageBit;
}

void drawImage(int imageBitmap[], int bitmapWidth, int bitmapHeight)
{
  long imageSize = bitmapWidth * bitmapHeight;
  int imageRowLength = bitmapWidth;
  long rowCounter = 0;

  for (int thisPixel = 0 ; thisPixel < imageSize; thisPixel++)
  {
    int imageBit = imageRead(imageBitmap,thisPixel); //Reads Pixel Value
    
    if (imageBit == 1) //Dot if 1
    {
      dot(pixelSpacing);
      rowCounter++;
    }
    else if (imageBit == 0) //No Dot if 0
    {
      noDot(pixelSpacing);
      rowCounter++;
    }

   if (rowCounter == imageRowLength)
    {
      mouseMove((-pixelSpacing*imageRowLength), pixelSpacing);
      rowCounter = 0;
    }    
  }
}

void openPaintDrawImage(int imageNumber)
{
      delay(1000);
      openPaint();
      readyImage();
      Serial.println(imageNumber);
      
    switch(imageNumber) 
   {
    case 1:
        drawImage(image1, image1Width, image1Height);
        break;
    case 2:
        drawImage(image2, image2Width, image2Height);
        break;
    case 3:
        drawImage(image3, image3Width, image3Height);
        break;
    }

      delay(2000);
}

