/*
 * Envia a leitura do Canal AD via UART
 */


#include "../Bibliotecas/config.h"
// Utilizar a bibliteca UART
#include "../Bibliotecas/UART.h"
#include "../Bibliotecas/ADC.h"
#include <stdio.h>

#include <xc.h>
#define _XTAL_FREQ 8000000

void main(void) {
    int leitura_adc;
    float tensao;
    char screen[16];
    
    uartInit(9600);
    adcInit();
    
    while(1){
        leitura_adc = adcRead();
        tensao = (float) leitura_adc * 5./1023.;
        sprintf(screen, "Tensao: %.2f - ", tensao);
        uartString(screen);
        __delay_ms(1000);
    }
}