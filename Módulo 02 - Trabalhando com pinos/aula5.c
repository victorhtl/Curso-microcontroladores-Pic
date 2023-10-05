#include "config.h"
#define _XTAL_FREQ 8000000

void main(void) {
    
    TRISD = 0;
    
    while(1){
        PORTD = 0x0F;
        __delay_ms(1000);
    
        PORTD = 0xF0;
        __delay_ms(1000);
    }
}
