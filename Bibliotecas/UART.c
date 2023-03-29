#include "UART.h"

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