/*
 PWM 10KHZ com Duty Cycle 50%
 
 */

#include <xc.h>
#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"

#define _XTAL_FREQ 8000000

void main(void) {
    ANSELC = 0;
    ANSELD = 0;
    
    TRISCbits.TRISC2 = 0;
    
    CCP1CON = 0x0F;
    
    // Duty Cycle 50%
    CCP1CONbits.DC1B0 = 0;
    CCP1CONbits.DC1B1 = 0;
    CCPR1L = 0x64;
    
    T2CON = 0x04;
    
    // Frequencia 10KHz
    PR2 = 0xC7;
    
    lcdInit();
    lcdString("PWM");
    
    while(1);
}
