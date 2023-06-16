// Retorna o mesmo dado que foi recebido pela serial

// A linha comentada dentro do while envia "ola mundo"
// pela serial a cada 2 segundos

#include "../Bibliotecas/config.h"
#define _XTAL_FREQ 8000000

char uartReceive(void);
void uartSend(char dado);
void uartInit(unsigned int baudrate);
void uartString(char *string);

void __interrupt(high_priority) interrupcao_alta(void){
    char data;
    
    // Tratamento de Erro
    if(RCSTA1bits.OERR){
        RCSTA1bits.CREN = 0;
        RCSTA1bits.CREN = 1;
    }

    data = uartReceive();
    uartSend(data + 1);
    
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
    
    while(1){
        //uartString("Ola mundo");
        __delay_ms(2000);
    }
}

void uartInit(unsigned int baudrate){
    ANSELCbits.ANSC6 = 0;
    ANSELCbits.ANSC7 = 0;
     
    RCSTA1bits.SPEN = 1;  // Habilita canal UART
    TXSTA1bits.TXEN = 1;  // Habilita a transmissão
    RCSTA1bits.CREN = 1;  // Habilita a recepção
       
    // Definindo BaudRate
    if(baudrate == 9600){
        BAUDCON1bits.BRG16 = 0;
        TXSTA1bits.BRGH = 0;
        TXSTA1bits.SYNC = 0;
        SPBRG1 = 12;
    }
    
    else if(baudrate == 57600){
        BAUDCON1bits.BRG16 = 1;
        TXSTA1bits.BRGH = 1;
        TXSTA1bits.SYNC = 0;
        SPBRG1 = 34;
        SPBRGH1 = 0;
    }
}

void uartSend(char dado){
    while(!TXSTA1bits.TRMT);
    TXREG1 = dado;
}

char uartReceive(void){
    while(!PIR1bits.RC1IF);
    return RCREG1;
}

void uartString(char *string){
    while(*string){
        uartSend(*string);
        string++;
    }
}