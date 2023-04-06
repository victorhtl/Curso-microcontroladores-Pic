/*
PIC18F45K22
Gera PWM pelo canal CCP1
*/

#ifndef _PWM_H_
#define	_PWM_H_

/*
Inicializa o CCP no modo PWM
@param: freq -> frequência do PWM
*/
void pwmInit(double freq);

/*
Define o Duty Cycle do PWM
@param: DC -> DutyCycle, valor de 0 a 100
*/
void pwmDutyCycle(double DC);

/*
Inicia o PWM
*/
void pwmStart();

/*
Para o PWM
*/
void pwmStop();

#define _XTAL_FREQ 8000000
#include <xc.h>

#endif