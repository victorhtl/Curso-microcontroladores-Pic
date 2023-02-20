#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include <stdio.h>

#define _XTAL_FREQ 8000000

void __interrupt(high_priority) INT0_interrupt(void){   
    PORTDbits.RD7 = 1;
    __delay_ms(5000);
    PORTDbits.RD7 = 0;
    INTCONbits.INT0IF = 0;
}

void __interrupt(low_priority) INT1_interrupt(void){
    lcdClean();
    
    lcdComando(1, 'I');
    __delay_ms(1000);
    lcdComando(1, 'N');
    __delay_ms(1000);
    lcdComando(1, 'T');
    __delay_ms(1000);
    lcdComando(1, '1');
    __delay_ms(1000);
    lcdClean();
    INTCON3bits.INT1IF = 0;
}

void main(void){
    TRISD = 0;
    ANSELD = 0;
    lcdInit();
    
    RCONbits.IPEN = 1;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    INTCONbits.INT0IE = 1;
    INTCON2bits.INTEDG0 = 1;
    
    INTCON3bits.INT1IE = 1;
    INTCON3bits.INT1IP = 0;
    INTCON2bits.INTEDG1 = 1;
    
    while(1){
        lcdSetCursor(1, 1);
        lcdString("Ola mundo");
        __delay_ms(500);
    }
}

