/*
Manipulação display LCD controlador HITACHI
Modo 4 bits
*/

#ifndef _LCD4BITS_H_
#define _LCD4BITS_H_

#include <xc.h>
#define _XTAL_FREQ 8000000

// Altere as conexões de acordo com sua placa
#define DATA_TRIS TRISD
#define DATA_PORT PORTD
#define RS PORTDbits.RD4
#define CLOCK PORTDbits.RD5

// Altere as conexões de acordo com sua placa
#define D4 PORTDbits.RD0
#define D5 PORTDbits.RD1
#define D6 PORTDbits.RD2
#define D7 PORTDbits.RD3

/*
@param: tipo = 1 -> caractere
        tipo = 0 -> comando
        com -> byte a ser enviado
*/
void lcdComando(unsigned char tipo, unsigned char com);

// Inicialização obrigatória do display modo 4 bits
void lcdInit(void);

// Envia uma string ao display
void lcdString(char *str);

// Limpa o dislay e retorna o cursor em DDRAM = 0
void lcdClean(void);

/* Posiciona o cursor
@param: linha -> linha do display
        coluna -> coluna do display
*/
void lcdSetCursor(char linha, char coluna);

// Realiza shift à direita do display
void lcdShiftRight(void);

// Realiza shift à esquerda do display
void lcdShiftLeft(void);

// Seta o cursor e envia uma string ao display LCD
void lcdStringCursor(char linha, char coluna, char *str);

#endif