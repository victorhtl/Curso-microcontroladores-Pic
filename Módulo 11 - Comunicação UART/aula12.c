/*
 * Entendendo o erro de overflow
 */

#include "../Bibliotecas/config.h"
#include "../Bibliotecas/UART.h"
#include <xc.h>
#define _XTAL_FREQ 8000000

void __interrupt(high_priority) interrupcao_alta(void){   
    
    char dado;

    // Tratamento de Erro
    if(RCSTA1bits.OERR){
        RCSTA1bits.CREN = 0;
        RCSTA1bits.CREN = 1;
        uartString("erro");
    }

    // dado = uartReceive();
    
    PIR1bits.RC1IF = 0;
}

void main(void) {
    uartInit(9600);
    
    // Interrupções global
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    RCONbits.IPEN = 1;   // Niveis de prioridades
    
    // Interrupção por Recepção
    PIE1bits.RC1IE = 1;  // Habilita a interrupção por Recepção Serial
    IPR1bits.RC1IP = 1;  // Alta prioridade
    PIR1bits.RC1IF = 0;  // Flag de interrupção
    
    while(1);
}