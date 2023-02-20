#ifndef _ADC_H_
#define _ADC_H_

#include <xc.h>
// Inicia conversor analógico no canal AN0
void adcInit(void);
// Faz a conversão analógica e retorna o resultado
// de 10 bits
int adcRead(void);

#endif