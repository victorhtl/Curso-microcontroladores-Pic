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

void lcdComando(unsigned char tipo, unsigned char com);
void lcdInit(void);
void lcdString(char *str);
void lcdClean(void);
void lcdSetCursor(char linha, char coluna);
void lcdShiftRight(void);
void lcdShiftLeft(void);

#endif