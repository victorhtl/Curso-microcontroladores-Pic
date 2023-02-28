#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include <xc.h>
#include <stdio.h>

unsigned char overflow = 0;

void __interrupt() timer2(void){
    overflow++;
    TMR2IF = 0;
}

void main(void){
    char screenBuff[4];
    
    ANSELA = 0;
    ANSELD = 0;
    
    TRISAbits.TRISA4 = 1;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    TMR2IE = 1;
    TMR2IF = 0;
    
    T2CON = 0x7A;
    PR2 = 0xFF;
    
    lcdInit();
    
    while(1){
        // Botao RA4 liga e desliga o timer2
        if(!PORTAbits.RA4){
            T2CONbits.TMR2ON = ~T2CONbits.TMR2ON;
            __delay_ms(300);
        }
        
        // Printa a quantidade de overflows na tela
        lcdSetCursor(1, 1);
        lcdString("INT = ");
        sprintf(screenBuff, "%03d", overflow);
        lcdString(screenBuff);
        __delay_ms(100);
    }
}