#ifndef _LCD4BITS_H_
#define _LCD4BITS_H_

#include <xc.h>
#define _XTAL_FREQ 8000000

/**
 Configure o PORT de ligação do display
 */
#define RS PORTDbits.RD4
#define CLOCK PORTDbits.RD5
#define D4 PORTDbits.RD0
#define D5 PORTDbits.RD1
#define D6 PORTDbits.RD2
#define D7 PORTDbits.RD3

// tipo 1-> Caracter, tipo 0 -> Comando
void lcdComando(unsigned char tipo, unsigned char com);

// Chama esta função para iniciar o display
void lcdInit(void);

// Envia uma String ao display
void lcdString(char *str);

// Limpa o Display
void lcdClean(void);

// Posiciona o cursor do display
void lcdSetCursor(char linha, char coluna);

// Faz o shift do conteudo para a direita
void lcdShiftRight(void);

// Faz o shift do conteudo para a esquerda
void lcdShiftLeft(void);

// Envia uma String ao display em uma posição específica
void lcdStringCursor(char linha, char coluna, char *str);

#endif