/*
PIC18F45K22
Canal UART
*/

#ifndef UART_H
#define	UART_H

#include <xc.h> 
#define _XTAL_FREQ 8000000

/*
Recebe um dado pela UART
@return: dado
*/
char uartReceive(void);

/*
Envia um dado pela UART
*/
void uartSend(char dado);

/*
Inicia o canal UART
@param: baudrate pode ser de 9600 ou 57600
*/
void uartInit(unsigned int baudrate);

/*
Envia uma string pelo canal UART
*/
void uartString(char *string);

#endif

