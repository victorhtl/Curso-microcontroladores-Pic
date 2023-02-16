#include "LCD4bits.h"

void lcdShiftRight(void){
    lcdComando(0, 0x1C);
    __delay_ms(1);
}

void lcdShiftLeft(void){
    lcdComando(0, 0x18);
    __delay_ms(1);
}

void lcdSetCursor(char linha, char coluna){
    char posicao;
    
    if(linha == 1) posicao = 0x80 + (coluna - 1);
    if(linha == 2) posicao = 0xC0 + (coluna - 1);
    
    lcdComando(0, posicao);
    
}

void lcdString(char *str){ 
    while(*str){
        lcdComando(1, *str);
        str++;
    }
}

void lcdClean(void){
    lcdComando(0, 0x01);
    __delay_ms(1);
}

void lcdInit(void){
    DATA_TRIS = 0;
    DATA_PORT = 0;
    
    __delay_ms(60);
    
    DATA_PORT = 0x03;
    
    for(char i = 0; i<3; i++){
        CLOCK = 1;
        CLOCK = 0;
        __delay_ms(5);
    }
    
    DATA_PORT = 0x02;
    
    for(char i = 0; i<2; i++){
        CLOCK = 1;
        CLOCK = 0;
        __delay_ms(5);
    }
    
    DATA_PORT = 0;
    CLOCK = 1;
    CLOCK = 0;
    
    lcdComando(0, 0x28);
    __delay_ms(1);

    lcdComando(0, 0x0C);
    __delay_ms(1);

    lcdComando(0, 0x01);
    __delay_ms(1);

    lcdComando(0, 0x06);
    __delay_ms(1);
}

void lcdComando(unsigned char tipo, unsigned char com){
    RS = tipo;
    __delay_ms(1);
    CLOCK = 0;
    D4 = com & 0x10 ? 1 : 0;
    D5 = com & 0x20 ? 1 : 0;
    D6 = com & 0x40 ? 1 : 0;
    D7 = com & 0x80 ? 1 : 0;
    CLOCK = 1;
    CLOCK = 0;
    __delay_ms(1);
    D4 = com & 0x01 ? 1 : 0;
    D5 = com & 0x02 ? 1 : 0;
    D6 = com & 0x04 ? 1 : 0;
    D7 = com & 0x08 ? 1 : 0;
    CLOCK = 1;
    CLOCK = 0;
    __delay_ms(1);
    RS = 0;
}
