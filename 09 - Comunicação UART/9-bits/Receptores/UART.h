#ifndef UART_H
#define	UART_H

#include <xc.h> 
#define _XTAL_FREQ 8000000

char uartReceive(void);
void uartSend(char dado);
void uartInit(unsigned int baudrate);
void uartString(char *string);

#endif

