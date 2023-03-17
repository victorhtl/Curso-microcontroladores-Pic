#include "EEPROM.h"

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

void eepromWriteFloat(char ADDR, float DATA){
    union{
        char valores[4];
        float valor;
    } data;
    
    data.valor = DATA;
    
    for(char i = 0; i<4; i++){
        eepromWrite(ADDR + i, data.valores[i]);
    }
}

float eepromReadFloat(char ADDR){
    union{
        char valores[4];
        float valor;
    } data;
    
    for(char i = 0; i<4; i++){
        data.valores[i] = eepromRead(ADDR+i);
    }
    
    return data.valor;
}

void eepromWriteArray(char ADDR, char tamanho, char *ARRAY){
    for(char i = 0; i<tamanho; i++){
        eepromWrite(ADDR+i, *ARRAY);
        ARRAY++;
    }
}

void eepromReadArray(char ADDR, char tamanho, char *ARRAY){
    for(char i = 0; i<tamanho; i++){
        *ARRAY = eepromRead(ADDR + i);
        ARRAY++;
    }
}