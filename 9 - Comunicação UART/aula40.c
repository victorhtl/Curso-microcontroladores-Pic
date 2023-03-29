/*
O codigo do slave vai ser o da aula 39. Nele, estara
conectado o trimpot onde a leitura estara sendo realizada

O MASTER (este código) só vai enviar o pacote {LEADC}
e esperar receber a string de resposta
A string sera enviada para o display lcd
*/

// Master
// Solicita leitura ADC e recebe a resposta
// em intervalos de 200ms
// O slave vai ser o ultimo codigo

#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"

#define _XTAL_FREQ 8000000
#define ARRAY_MAX 12

// Array que vai salvar o protocolo
volatile char pacote[ARRAY_MAX], * protocolo;
volatile unsigned char decodificar = 0;

// Prototipos de funções
void uartSend(char dado);
char uartReceive(void);
void uartInit(void);
void uartString(char *string);
void decode(void);

void __interrupt(high_priority) UARTINT(void){
    char data;
    static char controle = 0, salvando = 0;
    
    if(RCSTA1bits.OERR == 1){ 
        RCSTA1bits.CREN = 0;  
        RCSTA1bits.CREN = 1;
    }
    
    data = RCREG1;
    if(data == '{' && !salvando){
        // Inicia o protocolo
        protocolo = pacote;
        salvando = 1;
    }
    else if(data == '}' && salvando){
        // Encerra o protocolo
        salvando = 0;
        decodificar = 1;
    }
    else if (salvando && controle < 10){
        // Salva o protocolo
        *protocolo = data;
        protocolo++;
        controle++;
    }
    else if (controle >= ARRAY_MAX){
        // Se passar da quantidade maxima de caracteres
        // Esvazia o buffer
        data = RCREG1;
        // Reinicia o processo
        salvando = 0;
        controle = 0;
    }
    RC1IF = 0;
}

void main(void) {
    TRISB = 0;
    PORTB = 0;
    ANSELB = 0;
    
    uartInit();
    lcdInit();
    
    // Configuração global das interrupções
    INTCONbits.GIEH = 1;
    INTCONbits.GIEL = 1;
    RCONbits.IPEN = 1;
    
    // Interrupção UART
    PIR1bits.RC1IF = 0;
    IPR1bits.RC1IP = 1;
    PIE1bits.RC1IE = 1;
    
    lcdStringCursor(1, 1, "Aguardando");
    while(1){
        uartString("{LEADC}");
        __delay_ms(100);
        if(decodificar){
            lcdStringCursor(1, 1, pacote);
            decodificar = 0;
        }
    }
}

void uartInit(void){
    ANSELC = 0;
    
    // Config pinos de comunicação
    TRISCbits.RC6 = 0; // Pino RX
    TRISCbits.RC7 = 1; // Pino TX
    
    RCSTA1bits.SPEN = 1; // Chave geral
    TXSTA1bits.TXEN = 1; // Habilita a transmissão
    RCSTA1bits.CREN = 1; // Habilita recepção
    
    // BaudRate 9600
    BAUDCON1bits.BRG16 = 0; // Modo 8-bits
    TXSTA1bits.BRGH = 0;    // low speed
    TXSTA1bits.SYNC = 0;    // Modo assíncrono
    SPBRG1 = 12;
    SPBRGH1 = 0;
    
    // Apagar os buffers
    RC1REG = 0;
    TX1REG = 0;
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