#include "ADC.h"

union {
    char leitura[2];
    int result;
} adc;

void adcInit(void){
    ADCON1 = 0x00;
    ADCON2 = 0xAA;
}

/**
 * @Params: ch -> canal de leitura analógica
 * 
 * @Descrição: Passe como argumento o canal analógico
 * que será feita a leitura
 * 
 * Lembrar de configurar o pino como entrada (TRIS) e
 * configurar seu circuito analogico (ANSEL)
*/
int adcRead(char ch){
    ADCON0 = ch;        // Canal de leitura analogica

    ADCON0bits.ADON = 1;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);

    adc.leitura[1] = ADRESH;
    adc.leitura[0] = ADRESL;
    
    ADCON0bits.ADON = 0;
    return adc.result;
}