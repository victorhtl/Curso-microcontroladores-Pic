#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include <stdio.h>

#define _XTAL_FREQ 8000000

void __interrupt(high_priority) INT0_interrupt(void){ 
    
    // INT0
    if(INTCONbits.INT0IF){
        PORTDbits.RD7 = 1;
        __delay_ms(5000);
        PORTDbits.RD7 = 0;
        INTCONbits.INT0IF = 0;  
    }
    
    // INT1
    if(INTCON3bits.INT1IF){
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
}

void main(void){
    TRISD = 0;
    ANSELD = 0;
    lcdInit();
    
    // Habilita níveis de prioridade
    RCONbits.IPEN = 1;
    
    // Habilita interrupções
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    // Habilita interrupção por INT0
    INTCONbits.INT0IE = 1;
    INTCON2bits.INTEDG0 = 1;
    
    // Habilita interrupção por INT1
    INTCON3bits.INT1IE = 1;
    INTCON3bits.INT1IP = 1;
    INTCON2bits.INTEDG1 = 1;
    
    while(1){
        lcdSetCursor(1, 1);
        lcdString("Ola mundo");
        __delay_ms(500);
    }
}

