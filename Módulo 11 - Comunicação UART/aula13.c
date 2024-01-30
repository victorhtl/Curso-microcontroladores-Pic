/* Printa uma mensagem de ate 16 caracteres no display

Protocolo:
    { -> INICIO
    } -> FIM

 * Quando encontra o inicio, salva os caracteres recebidos em um array
 * Quando encontra o fim, printa os caracteres no display
*/

#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include "../Bibliotecas/UART.h"

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

void main(void) {
    
    uartInit(57600);
    lcdInit();
    
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
        if(decodificar){
            INTCONbits.GIEH = 0;
            lcdClean();
            lcdStringCursor(1,1, pacote);
            INTCONbits.GIEH = 1;
            decodificar = 0;
        }
    }
}
