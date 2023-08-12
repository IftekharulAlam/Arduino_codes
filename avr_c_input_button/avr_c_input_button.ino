#include <avr/io.h>
int main(void) {
  DDRB = 0x01;
  PORTB = 0x02;
  while (1) {
    if (!(PINB & 0X02)) {
      PORTB |= 0x01;


    } else {
      PORTB &= 0xFE;

    }


  }



}
