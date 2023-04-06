/*
 PIC18F45K22
 Codigo I2C modo master
 */

#ifndef I2C_H
#define	I2C_H

#define _XTAL_FREQ 8000000
#include <xc.h>

// Inicializa comunica��o I2C canal 1
void I2C_Init(void);

// Envia bit de start na rede
void I2C_Start(void);

// Escreve um dado na rede I2C
void I2C_Write(char data);

// Realiza a leitura de um dado recebido
// @params: 1->envia ACK 0->Envia NACK
//@return: dado recebido
char I2C_Read(char ack);

// Envia bit de stop na rede
void I2C_Stop(void);

// Envia bit de Repeated Start na rede
void I2C_Rep_Start(void);

#endif

