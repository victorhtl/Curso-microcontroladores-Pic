#include "config.h"
#define _XTAL_FREQ 8000000

// RA4 -> Botao 1
// RC0 -> Botao 2

void main(void) {
    
    ANSELA = 0;
    ANSELC = 0;
    ANSELD = 0;
    
    TRISAbits.TRISA4 = 1;
    TRISCbits.TRISC0 = 1;
    TRISD = 0;
    
    PORTD = 0x0F;
    
    while(1){
        if(PORTAbits.RA4 == 0){
            PORTD = PORTD<<1;
            __delay_ms(300);
        }
        if(PORTCbits.RC0 == 0){
            PORTD = PORTD>>1;
            __delay_ms(300);
        }
    }
}
