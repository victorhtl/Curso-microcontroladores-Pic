#include <xc.h>
#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include <stdio.h>

#define _XTAL_FREQ 8000000

void main(void){
    int valor = 0;
    int segundo = 0;
    char screenBuff[5];

    ANSELD = 0;
    lcdInit();

    T0CON = 0xC7;
    TMR0L = 61;
    TMR0IF = 0;

    while(1){
        if(TMR0IF){
            valor++
            TMR0IF = 0;
            TMR0L = 61;
        }
        if(valor == 40){
            segundo++;
            valor = 0;
        }
        sprintf(screenBuff, "%04d", valor);
        lcdString("Overflow = ");
        lcdString(screenBuff);
        lcdSetCursor(1, 1);
    }
}