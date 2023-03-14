/*
Controle do Duty Cycle via trimpot
*/

#include <xc.h>
#include <stdio.h>

#include "../Bibliotecas/PWM.h"
#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/ADC.h"
#include "../Bibliotecas/config.h"

#define _XTAL_FREQ 8000000

void main(void) {
    int leitura_adc;
    char screenBuff[10];
    
    pwmInit(25000);
    pwmDutyCycle(10);
    pwmStart();
    
    adcInit();
    
    lcdInit();
    
    while(1){
        leitura_adc = adcRead();
        sprintf(screenBuff, "%04d", leitura_adc);
        lcdStringCursor(1, 1, screenBuff);
        
        leitura_adc = leitura_adc * 100./1023.;
        sprintf(screenBuff, "%04d", leitura_adc);
        lcdStringCursor(2, 1, screenBuff);
        
        pwmDutyCycle(leitura_adc);
        
        __delay_ms(100);
    }
}
