#include <xc.h>
#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"

#define _XTAL_FREQ 8000000

void main(void){
    ANSELD = 0;
    lcdInit();

    T0CON = 0xF8;
    TMR0L = 254;

    while(1){
        if(TMR0IF){
            lcdString("Overflow");
            TMR0IF = 0;
            TMR0L = 254;
        }
    }
}