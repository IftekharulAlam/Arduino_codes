#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global start
.global led

start:
    SBI DDRB,5
    RET
led:
    CPI R24, 0x00
    BREQ ledOFF
    SBI PORTB,5
    RET
ledOFF:
    CBI PORTB,5
    RET
   
