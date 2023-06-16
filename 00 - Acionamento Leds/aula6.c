#include "config.h"
#define _XTAL_FREQ 8000000

void main(void) {
    ANSELD = 0;
    ANSELA = 0;
    
    TRISD = 0;
    TRISAbits.TRISA4 = 1;
    
    char count = 0;
    
    while(1){
        if(PORTAbits.RA4 == 0){
            PORTD = count;
            count++;
            if(count == 255) count = 0;
            __delay_ms(300);
        }
    }
}
