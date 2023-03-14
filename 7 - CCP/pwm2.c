/*
 PWM 2KHZ com Duty Cycle 30%
 
 */

#include <xc.h>
#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"

#define _XTAL_FREQ 8000000

void main(void) {
    ANSELD = 0;
    ANSELC = 0;
    
    TRISCbits.TRISC2 = 0;
    
    CCP1CON = 0x0F;
    CCP1CONbits.DC1B0 = 0;
    CCP1CONbits.DC1B1 = 0;
    CCPR1L = 0xAF;
    
    T2CON = 0x05;
    PR2 = 0xF9;
    
    lcdInit();
    lcdString("PWM");
    
    while(1);
}
