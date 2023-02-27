#include "ADC.h"

union {
    char leitura[2];
    int result;
} adc;

void adcInit(void){
    TRISAbits.TRISA0 = 1;
    ANSELAbits.ANSA0 = 1;
    
    ADCON0 = 0x00;
    ADCON1 = 0x00;
    ADCON2 = 0xAA;
}

int adcRead(void){
    ADCON0bits.ADON = 1;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);

    adc.leitura[1] = ADRESH;
    adc.leitura[0] = ADRESL;
    
    return adc.result;
}