#include <avr/io.h>

int main(void) {
  DDRB = 0x20;
  PORTB = 0;


  while (1) {
    PORTB = 0x20;
    _delay_ms(1000);
    PORTB = 0;
    _delay_ms(1000);

  }

}
