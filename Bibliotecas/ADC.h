/*
 PIC18F45K22
 Codigo leitura canal AD
 */

#ifndef _ADC_H_
#define _ADC_H_

#include <xc.h>

// Inicializa o canal AN0
void adcInit(void);

// Realiza a leitura
// @return: resultado da leitura (1023bits)
int adcRead(void);

#endif