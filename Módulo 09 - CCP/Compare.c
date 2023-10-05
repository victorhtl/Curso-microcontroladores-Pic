#include <xc.h>
#include <stdio.h>

#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"

#define _XTAL_FREQ 8000000

#define uchar unsigned char
#define uint unsigned int

void __interrupt() modo_compare(){
    TMR1H = 0;
    TMR1L = 0;
    CCP1IF = 0;
}

void main(void) {
    TRISCbits.TRISC2 = 0;
    ANSELC = 0;
    ANSELD = 0;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    CCP1IE = 1;
    CCP1IF = 0;
    
    CCP1CON = 0x02;
    CCPR1L = 0xE8;
    CCPR1H = 0x03;
    
    T1CON = 0x12;
    TMR1H = 0;
    TMR1L = 0;
    T1CONbits.TMR1ON = 1;
    
    lcdInit();
    lcdString("Compare");
    
    while(1);
}
