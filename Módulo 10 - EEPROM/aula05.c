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

// Escreve um Inteiro na EEPROM interna
// ADDR -> endereço de memória
// DATA -> Inteiro a ser gravado
void eepromWriteInt(char ADDR, int DATA);

// Lê um Inteiro na EEPROM interna
// ADDR -> endereço a ser lido
int eepromReadInt(char ADDR);

// Escreve um Long Int na EEPROM interna
void eepromWriteLong(char ADDR, long int DATA);

// Le um Long Int da EEPROM interna
long int eepromReadLong(char ADDR);

void main(void) {
    long int conta;
    char screen[12];
    
    TRISAbits.TRISA4 = 1;
    
    conta = eepromReadLong(0);
    
    lcdInit();
    
    while(1){
        if(!PORTAbits.RA4){
            while(!PORTAbits.RA4) __delay_ms(20);
            conta = 1000000;
            eepromWriteLong(0, conta);
        }
        sprintf(screen, "%010lu", conta);
        lcdStringCursor(1, 1, screen);
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
    EECON1bits.WR = 1;     // Inicia escrita 
    while(EECON1bits.WR);  // Aguarda escrita
    
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

void eepromWriteInt(char ADDR, int DATA){
    union{
        char valores[2];
        int valor;
    } data;
    
    data.valor = DATA;
    eepromWrite(ADDR, data.valores[0]);
    eepromWrite(ADDR+1, data.valores[1]);
}

int eepromReadInt(char ADDR){
    union{
        char valores[2];
        int valor;
    } data;
    
    data.valores[0] = eepromRead(ADDR);
    data.valores[1] = eepromRead(ADDR+1);
    
    return data.valor;
}

void eepromWriteLong(char ADDR, long int DATA){
    union{
        char valores[4];
        long int valor;
    } data;
    
    data.valor = DATA;
    
    for(char i = 0; i<4; i++){
        eepromWrite(ADDR + i, data.valores[i]);
    }
}

long int eepromReadLong(char ADDR){
    union{
        char valores[4];
        long int valor;
    } data;
    
    for(char i = 0; i<4; i++){
        data.valores[i] = eepromRead(ADDR+i);
    }
    
    return data.valor;
}