#include "config.h"
#define _XTAL_FREQ 8000000

// RA4 -> Botao 1
// RC0 -> Botao 2

void main(void) {
    
    // Todos os pinos como entradas digitais
    ANSELA = 0;
    ANSELC = 0;
    ANSELD = 0;
    
    // Definindo os pinos como entrada
    TRISAbits.TRISA4 = 1;
    TRISCbits.TRISC0 = 1;

    // Definindo PORTD como saida
    TRISD = 0;
    
    // Definindo nivel logico dos pinos dos PORTD
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
