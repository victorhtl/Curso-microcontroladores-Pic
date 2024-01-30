#include "../Bibliotecas/config.h"
#define _XTAL_FREQ 8000000

void __interrupt(high_priority) interrupcao_alta(void){  
    // Tratamento de Erro
    if(RCSTA1bits.OERR){
        RCSTA1bits.CREN = 0;
        RCSTA1bits.CREN = 1;
    }
    
    TXREG1 = RCREG1;
    PIR1bits.RC1IF = 0;
}

void main(void) {
    ANSELCbits.ANSC6 = 0;
    ANSELCbits.ANSC7 = 0;

    RCSTA1bits.SPEN = 1;  // Habilita canal UART
    TXSTA1bits.TXEN = 1;  // Habilita a transmissão
    RCSTA1bits.CREN = 1;  // Habilita a recepção

    BAUDCON1bits.BRG16 = 0;
    TXSTA1bits.BRGH = 0;
    TXSTA1bits.SYNC = 0;
    SPBRG1 = 12;
    
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