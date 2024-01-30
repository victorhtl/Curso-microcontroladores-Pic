#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"
#include <stdio.h>

#define _XTAL_FREQ 8000000

// Escreve 1 byte na EEPROM interna
// ADDR -> endereço de memória
// DATA -> byte a ser gravado
void eepromWrite(char ADDR, char DATA);

// Lê 1 byte da EEPROM interna
// ADDR -> endereço da memória
char eepromRead(char ADDR);

void main(void) {
    char conta = 0;
    char screen[6];

    TRISAbits.TRISA4 = 1;

    conta = eepromRead(0);

    LcdInit();
    
    while(1){
        if(!PORTAbits.RA4){
            while(!PORTAbits.RA4) __delay_ms(100);
            conta++;
            eepromWrite(0, conta);
        }
        sprintf(screen, "%03u", conta);
        lcdStringCursor(1,1,screen);
        __delay_ms(20);
    }
}

void eepromWrite(char ADDR, char DATA){
    char int_status = INTCONbits.GIE;
    
    EEADR = ADDR;          // Endereço a ser gravado
    EEDATA = DATA;         // Byte a ser gravado
    EECON1bits.CFGS = 0;   // Seleciona memórias
    EECON1bits.EEPGD = 0;  // Memória EEPROM
    EECON1bits.WREN = 1;   // Habilita Escrita
    
    INTCONbits.GIE = 0;    // Desabilita as interrupções
    
    EECON2 = 0x55;         // Procedimento padrão
    EECON2 = 0xAA;         // Procedimento padrão
    EECON1bits.WR = 1;     // Inicia leitura 
    while(EECON1bits.WR);  // Aguarda leitura
    
    INTCONbits.GIE = int_status; // Habilita as interrupções
    EECON1bits.WREN = 0;
}

char eepromRead(char ADDR){
    EEADR = ADDR;
    EECON1bits.CFGS = 0;   // Seleciona memórias
    EECON1bits.EEPGD = 0;  // Memória EEPROM
    
    EECON1bits.RD = 1;     // Inicia Leitura
    while(EECON1bits.RD);  // Aguarda Leitura
    
    _delay(2);
    
    return EEDATA;
}

