#include"../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"
#include <stdio.h>

#define _XTAL_FREQ 8000000

void __interrupt(high_priority) INT0_INT(void){
    static int incrementa = 0;
    char screenBuff[3];

    incrementa++;
    sprintf(screenBuff, "%02d", incrementa).

    lcdClean();
    lcdString("INT = ");
    lcdString(screenBuff);
    __delay_ms(2000);
    lcdClean();
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
        lcdString("Ola mundo");
        __delay_ms(500);
    }
}