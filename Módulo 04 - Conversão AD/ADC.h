#ifndef _ADC_H_
#define _ADC_H_

#include <xc.h>

// Inicializa ADC no canal AN0
void adcInit(void);

// Leitura e conversão do canal ch (0 a 27)
// Retorna um valor de 10 bits
int adcRead(char ch);

#endif