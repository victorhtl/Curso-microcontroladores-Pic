#include "config.h"
#define _XTAL_FREQ 8000000

// LAT
// ANSEL

void main(void) {
    // PIC18F45K22
    ANSELD = 0;
    
    TRISD = 0;
    LATD = 1;
    
    while(1);
}
