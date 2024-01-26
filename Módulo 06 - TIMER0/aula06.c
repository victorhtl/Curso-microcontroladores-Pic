#include <xc.h>
#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include <stdio.h>

#define _XTAL_FREQ 8000000

int segundo = 0;

void __interrupt(high_priority) timer0(){
    static int valor = 0;
    valor++;
    if(valor == 40){
        segundo++;
        valor = 0;
    }
	TMR0L = 61;
    TMR0IF = 0;
}

void main(void){
    char screenBuff[5];

    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;

    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IP = 1;
    INTCONbits.TMR0IF = 0;

    T0CON = 0xC7;
    TMR0L = 61;

    ANSELD = 0;
    lcdInit();

    while(1){
        sprintf(screenBuff, "%04d", valor);
        lcdString("Overflow = ");
        lcdString(screenBuff);
        lcdSetCursor(1, 1);
        __delay_ms(100);
    }
}