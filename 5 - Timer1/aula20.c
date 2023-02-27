#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include <xc.h>
#include <stdio.h>

#define _XTAL_FREQ 8000000

int overflow = 0;

void __interrupt() timer1(){
    overflow++;
    TMR1H = 0;
    TMR1L = 0;
    PIR1bits.TMR1IF = 0;
}

void main(void) {
    char screenBuff[5];
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;
    
    T1GCON = 0x80;
    
    T1CON = 0x32;
    TMR1H = 0;
    TMR1L = 0;
    T1CONbits.TMR1ON = 1;
    
    ANSELD = 0;
    lcdInit();
    
    while(1){
        sprintf(screenBuff, "%04u", overflow);
        lcdString("Inc = ");
        lcdString(screenBuff);
        lcdSetCursor(1, 1);
        __delay_ms(100);
    }
}
