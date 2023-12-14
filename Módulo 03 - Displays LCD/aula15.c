#include "../Bibliotecas/config.h"

#define RS PORTDbits.RD4
#define E  PORTDbits.RD5
#define D4 PORTDbits.RD0
#define D5 PORTDbits.RD1
#define D6 PORTDbits.RD2
#define D7 PORTDbits.RD3

void lcdComando(char tipo, char com);
void lcdInit(void);
void clock(void);
void lcdString(char *str);
void lcdClean(void);
void lcdSetCursor(char linha, char coluna);
void lcdStringCursor(char linha, char coluna, char *str);
void lcdShiftLeft(void);
void lcdShiftRight(void);

void main(void) {
    OSCCON = 0x63;
    
    TRISD = 0;
    PORTD = 0;
    ANSELD = 0;
    
    char string[] = "Ola mundo";
    
    lcdInit();

    lcdComando(0, 0x40); // Primeiro endereço da CGRAM
    
    lcdComando(1, 0);
    lcdComando(1, 0x0A);
    lcdComando(1, 0x0A);
    lcdComando(1, 0);
    lcdComando(1, 0x11);
    lcdComando(1, 0x0E);
    lcdComando(1, 0);
    lcdComando(1, 0);

    lcdSetCursor(1, 8);
    
    lcdComando(1, 0x00); // Printa o caractere do endereço 1 na tela

    lcdComando(0, 0x48); // Segundo endereço da CGRAM
    
    lcdComando(1, 0);
    lcdComando(1, 0x0A);
    lcdComando(1, 0x0A);
    lcdComando(1, 0);
    lcdComando(1, 0x11);
    lcdComando(1, 0x0E);
    lcdComando(1, 0);
    lcdComando(1, 0);

    lcdSetCursor(1, 9);
    
    lcdComando(1, 0x01); // Printa o caractere do endereço 2 na tela
    
    while(1);
}

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

void lcdStringCursor(char linha, char coluna, char *str){
    lcdSetCursor(linha, coluna);
    lcdString(str);
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
    __delay_ms(60);
    
    D4 = 1;
    D5 = 1;
    D6 = 0;
    D7 = 0;
    
    for(char i = 0; i<3; i++){
        clock();
        __delay_ms(5);
    }
    
    D4 = 0;
    D5 = 1;
    D6 = 0;
    D7 = 0;
    
    for(char i = 0; i<2; i++){
        clock();
        __delay_ms(5);
    }
    
    D4 = 0;
    D5 = 0;
    D6 = 0;
    D7 = 0;
    clock();
    
    lcdComando(0, 0x28);
    __delay_ms(1);
    
    lcdComando(0, 0x0C);
    __delay_ms(1);
    
    lcdComando(0, 0x01);
    __delay_ms(1);
    
    lcdComando(0, 0x06);
    __delay_ms(1);
    
}

void clock(void){
    E = 1;
    __delay_us(2);
    E = 0;
}

void lcdComando(char tipo, char com){
    RS = tipo;
    __delay_us(5);
    E = 0;
    D4 = com & 0x10 ? 1 : 0;
    D5 = com & 0x20 ? 1 : 0;        
    D6 = com & 0x40 ? 1 : 0;
    D7 = com & 0x80 ? 1 : 0; 
    clock();
    D4 = com & 0x01 ? 1 : 0;
    D5 = com & 0x02 ? 1 : 0;        
    D6 = com & 0x04 ? 1 : 0;
    D7 = com & 0x08 ? 1 : 0; 
    clock();
    RS = 0;
}