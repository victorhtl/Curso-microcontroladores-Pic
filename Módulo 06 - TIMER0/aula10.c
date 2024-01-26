#include <xc.h>
#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include <stdio.h>

#define _XTAL_FREQ 8000000

union {
    unsigned char valores[2];
    unsigned int result;
} timer_data;

void __interrupt(high_priority) timer0(void){
    TMR0H = 0;
    TMR0L = 0;
    TMR0IF = 0;
}

void main(void) {
    char screenBuff[5];
    
    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    INTCONbits.TMR0IE = 1;
    INTCON2bits.TMR0IP = 1;
    INTCONbits.TMR0IF = 0;
    
    T0CON = 0x87;
    TMR0H = 0;
    TMR0L = 0;
    
    ANSELD = 0;
    lcdInit();

    while(1){
        timer_data.valores[0] = TMR0L;
        timer_data.valores[1] = TMR0H;
        
        sprintf(screenBuff, "%05u", timer_data.result);
        lcdString("Timer = ");
        lcdString(screenBuff);
        lcdSetCursor(1, 1);
        __delay_ms(100);
    }
}