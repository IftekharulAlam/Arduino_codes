#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include<SPI.h>
char buff[15];
volatile byte indx;
volatile boolean process;

LiquidCrystal_I2C lcd(0x27, 16, 2);
ISR (SPI_STC_vect) // SPI interrupt routine
{
  byte c = SPDR; // read byte from SPI Data Register
  if (indx < sizeof buff) {
    buff [indx++] = c; // save data in the next index in the array buff
    if (c == 'C') //check for the end of the word{
    {
      process = true;}
    

  }

}
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  pinMode(MISO, OUTPUT); // have to send on master in so it set as output
  SPCR |= _BV(SPE); // turn on SPI in slave mode
  indx=0;
  process = false;
  SPI.attachInterrupt(); // turn on interrupt
}

void loop() {
  lcd.setCursor(0, 0);

  // put your main code here, to run repeatedly:
  if (process) {
    process = false; //reset the process
    lcd.print(buff); //print the array on serial monitor
    indx = 0; //reset button to zero
  }




}
