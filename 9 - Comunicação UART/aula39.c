// PROTOCOLO DE COMUNICAÇÃO SERIAL
// Esta comunicação faz o acionamento de pinos do PORTB
// - {PINxS}    Retorna o estado do LED
// - {PINxON}   Liga o LED
// - {PINxOFF}  Desliga o LED
// NOVAS FUNCIONALIDADES DESTE PROTOCOLO
// - {LEADC}

#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include "../Bibliotecas/ADC.h"
#include <stdio.h>

#define _XTAL_FREQ 8000000

// Array que vai salvar o protocolo
volatile char pacote[10], * protocolo;
volatile unsigned char salvando = 0, decodificar = 0;

// Prototipos de funções
void uartSend(char dado);
char uartReceive(void);
void uartInit(void);
void uartString(char *string);
void decode(void);

void __interrupt(high_priority) UARTINT(void){
    char data;
    static char controle = 0;
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
    else if (controle >= 10){
        // Se passar da quantidade maxima de caracteres
        // Esvazia o buffer
        data = RCREG1;
        // Envia mensagem de erro
        uartString("Erro");
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
    adcInit();
    
    // Configuração global das interrupções
    INTCONbits.GIEH = 1;
    INTCONbits.GIEL = 1;
    RCONbits.IPEN = 1;
    
    // Interrupção UART
    PIR1bits.RC1IF = 0;
    IPR1bits.RC1IP = 1;
    PIE1bits.RC1IE = 1;
    
    lcdString("UART mode");
    
    while(1){
        // Quando a interrupção alterar esta variavel
        // a função decode será chamada
        if(decodificar){
            decode();
        }
    }
}

void decode(void){
    INTCONbits.GIEH = 0;
    int leitura_adc;
    float tensao;
    char string[8];
    // Pinos
    if(pacote[0] == 'P' && pacote[1] == 'I' && pacote[2] == 'N'){
        switch (pacote[3]){
            case '0':
                if (pacote[4] == 'S'){
                    if(PORTBbits.RB0)
                        uartString("Ligado");
                    else
                        uartString("Desligado");
                }
                if (pacote[4] == 'O' && pacote[5] == 'N'){
                    PORTBbits.RB0 = 1;
                }
                if (pacote[4] == 'O' && pacote[5] == 'F' && pacote[6] == 'F'){
                    PORTBbits.RB0 = 0;
                }
                break;
            case '1':
                if (pacote[4] == 'S'){
                    if(PORTBbits.RB1)
                        uartString("Ligado");
                    else
                        uartString("Desligado");
                }
                if (pacote[4] == 'O' && pacote[5] == 'N'){
                    PORTBbits.RB1 = 1;
                }
                if (pacote[4] == 'O' && pacote[5] == 'F' && pacote[6] == 'F'){
                    PORTBbits.RB1 = 0;
                }    
                break;
        }
    }
    // Conversor AD {LEADC}
    if(pacote[0] == 'L' && pacote[1] == 'E' && pacote[2] == 'A' && pacote[3] == 'D' && pacote [4] == 'C'){
        leitura_adc = adcRead();
        tensao = (float) leitura_adc * 5./1023.;
        sprintf(string, "Tensao: %.2f - ", tensao);
        uartString(string);
    }
    
    decodificar = 0;
    INTCONbits.GIEH = 1;
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