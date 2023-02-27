#include <pic18f45k22.h>

#include "config.h"
#define _XTAL_FREQ 8000000

// RA4 -> Botao 1
// RC0 -> Botao 2

void main(void) {

    ANSELA = 0;
    ANSELD = 0;
    
    TRISAbits.TRISA4 = 1;
    TRISD = 0;
    
    while(1){
        PORTD = 0xFF;
        
        if(PORTAbits.RA4 == 0){
            PORTD = 0;
            __delay_ms(1000);
        }
    }
}
