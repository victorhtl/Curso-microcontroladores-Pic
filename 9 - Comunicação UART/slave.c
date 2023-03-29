// Slave

#include "config.h"
#include "../Bibliotecas/UART.h"
#include "../Bibliotecas/ADC.h"
#include <stdio.h>

#define _XTAL_FREQ 8000000
#define MAX 16

volatile char pacote[MAX], *protocolo;
volatile char decodificar = 0;

void __interrupt(high_priority) UARTINT(void){
    
    char data;
    static char salvando = 0, controle = 0;
    
    if(RCSTA1bits.OERR == 1){ 
        RCSTA1bits.CREN = 0;  
        RCSTA1bits.CREN = 1;
    }
    
    data = RCREG1;
    
    // Inicia o protocolo
    if(data == '{' && !salvando){
        protocolo = pacote;
        salvando = 1;
    }
    
    // Finaliza o protocolo
    else if(data == '}' && salvando){
        *protocolo = '\0';
        salvando = 0;
        decodificar = 1;
        controle = 0;
    }
    
    // Salva o protocolo
    else if(salvando && controle < MAX){
        *protocolo = data;
        protocolo++;
        controle++;
    }
    
    // Controle do tamanhos
    else if (controle >= MAX){
        TXREG1 = 'E';
        while(!TXSTA1bits.TRMT);
        TXREG1 = 'R';
        while(!TXSTA1bits.TRMT);
        TXREG1 = 'R';
        while(!TXSTA1bits.TRMT);
        TXREG1 = 'O';
        while(!TXSTA1bits.TRMT);
        salvando = 0;
        controle = 0;
    }
    
    PIR1bits.RC1IF = 0;
}

void decode(void);

void main(void) {
    OSCCON = 0b01100011;
    
    uartInit(9600);
    adcInit();
    
    // Configuração global das interrupções
    INTCONbits.GIEH = 1;
    INTCONbits.GIEL = 1;
    RCONbits.IPEN = 1;
    
    // Interrupção UART
    PIR1bits.RC1IF = 0;
    IPR1bits.RC1IP = 1;
    PIE1bits.RC1IE = 1;
    
    while(1){
        // Quando a interrupção alterar esta variavel
        // a função decode será chamada
        if(decodificar){
            decode();
        }
    }
}

void decode(void){
    char string[16];
    int leitura_adc;
    float tensao;
    
    INTCONbits.GIEH = 0;
    
    if(pacote[0] == 'L' && pacote[1] == 'E' && pacote[2] == 'A' && pacote[3] == 'D' && pacote [4] == 'C'){
        leitura_adc = adcRead();
        tensao = (float) leitura_adc * 5./1023.;
        sprintf(string, "{Tensao %.2f}", tensao);
        uartString(string);
    }
    
    decodificar = 0;
    INTCONbits.GIEH = 1;
}