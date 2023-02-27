#ifndef _LCD4BITS_H_
#define _LCD4BITS_H_

#include <xc.h>
#define _XTAL_FREQ 8000000

#define DATA_TRIS TRISD
#define DATA_PORT PORTD
#define RS PORTDbits.RD4
#define CLOCK PORTDbits.RD5

#define D4 PORTDbits.RD0
#define D5 PORTDbits.RD1
#define D6 PORTDbits.RD2
#define D7 PORTDbits.RD3

// @tipo -> 0 = comando, 1 = caractere
// @com -> byte a ser enviado
void lcdComando(unsigned char tipo, unsigned char com);

// Inicialização obrigatória do display modo 4 bits
void lcdInit(void);

// Envia uma string ao display
void lcdString(char *str);

// Limpa o dislay e retorna o cursor em DDRAM = 0
void lcdClean(void);

// Posiciona o cursor
void lcdSetCursor(char linha, char coluna);

// Realiza shift à direita do display
void lcdShiftRight(void);

// Realiza shift à esquerda do display
void lcdShiftLeft(void);

#endif