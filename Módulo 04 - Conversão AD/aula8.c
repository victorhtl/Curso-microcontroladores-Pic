#include <stdio.h>
#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"

union {
    char leitura[2];
    int res;
} adc;

void main(void) {
    char lcdBuff[5];
    float volt;
    
    ANSELD = 0;
    lcdInit();
    
    TRISAbits.TRISA0 = 1;
    ANSELA = 0x01;
    
    // Seleção do canal analógico
    ADCON0 = 0X00;
    ADCON1 = 0X00;
    ADCON2 = 0XAA;
    
    lcdString("Tensao: ");
    
    while(1){
        ADCON0bits.ADON = 1;
        ADCON0bits.GO = 1;
        while(ADCON0bits.GO);
        adc.leitura[1] = ADRESH;
        adc.leitura[0] = ADRESL;
        
        volt = (float) adc.res * (5./1023.);
        //volt = volt / 100;
        
        sprintf(lcdBuff, "%02.1f V", volt);
        lcdSetCursor(1, 9);
        lcdString(lcdBuff);
        __delay_ms(100);
    }
}