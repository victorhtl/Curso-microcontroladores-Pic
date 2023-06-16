#include"../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"

#define _XTAL_FREQ 8000000

void __interrupt(high_priority) INT0_INT(void){
    lcdClean();
    lcdString("Interrompi");
    __delay_ms(2000);
    INTCONbits.INT0IF = 0;
}

void main(void) {
    ANSELD = 0;
    TRISD = 0;
    
    lcdInit();
    
    RCONbits.IPEN = 1;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    INTCONbits.INT0IE = 1;
    INTCONbits.INT0IF = 0;
    INTCON2bits.INTEDG0 = 1;
    
    while(1){
        lcdSetCursor(1, 1);
        lcdString("Rotina normal...");
        __delay_ms(500);
    }
}