
/*  MAX7219 Dot Matrix Display Panel 32x8 P3.75 V2
 *  
 *  CONNECTION:
 *    L-Shape Header (5 Pins)     Arduino Uno                 Arduino Mega
 *   VCC   <----------------------->  5V  <-----------------------> 5V
 *   GND   <----------------------->  GND <-----------------------> GND              
 *   DIN   <----------------------->  11  <-----------------------> 51               
 *   LOAD  <----------------------->  10  <-----------------------> 10               
 *   CLOCK <----------------------->  13  <-----------------------> 52
 *  
 *  DEVELOPER:
 *    Nur Mohammad
 *    Asst. Production Engineer
 *    Techshop Bangladesh
 *    http://roboticsarena.blogspot.com/
 *    rasel.mahmud1919@gmail.com
 *  
 *  Product Code:SL082NM291116
 */

/* Include the HCMAX7219 and SPI library */
#include <HCMAX7219.h>
#include "SPI.h"

/* Set the LOAD (CS) digital pin number*/
#define LOAD 10
 
/* Create an instance of the library */
HCMAX7219 HCMAX7219(LOAD);

void setup() 
{ 
}

/* Main program */
void loop() 
{
  byte Loopcounter;
  int Position;

  /* Clear the output buffer */
  HCMAX7219.Clear();
  HCMAX7219.Invert(INVERTON);
  /* SCROLL All TEXT 2 TIMES */
  for (Loopcounter = 0; Loopcounter <= 1; Loopcounter++)
  {
    for(Position=0; Position <= 408; Position++)
    {
    HCMAX7219.printMatrix("MAX7219 Dot Matrix Display Panel 32x8 P3.75", Position);
    HCMAX7219.Refresh();
    delayMicroseconds(100);
    }
  }
}
