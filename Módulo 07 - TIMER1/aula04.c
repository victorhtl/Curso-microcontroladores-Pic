#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include <xc.h>
#include <stdio.h>

#define _XTAL_FREQ 8000000

int overflow = 0;

union {
    char valores[2];
    int result;
} timer1_data;

void __interrupt() timer1(){
    overflow++;
    TMR1H = 0xFF;
    TMR1L = 0XFA;
    PIR1bits.TMR1IF = 0;
}

void main(void) {
    ANSELC = 0;
    TRISCbits.TRISC0 = 1;
    
    char screenBuff[5];
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;
    
    T1CON = 0x86;
    TMR1H = 0xFF;
    TMR1L = 0XFA;
    T1CONbits.TMR1ON = 1;
    
    ANSELD = 0;
    lcdInit();
    
    while(1){
        sprintf(screenBuff, "%04u", overflow);
        lcdString("Overflow = ");
        lcdString(screenBuff);
        lcdSetCursor(2, 1);
        
        timer1_data.valores[0] = TMR1L;
        timer1_data.valores[1] = TMR1H;
        sprintf(screenBuff, "%05u", timer1_data.result);
        lcdString("TMR1 = ");
        lcdString(screenBuff);
        lcdSetCursor(1, 1);
        __delay_ms(100);
    }
}

