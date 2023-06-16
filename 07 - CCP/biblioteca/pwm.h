#ifndef _PWM_H_
#define	_PWM_H_

void pwmInit(double freq);
void pwmDutyCycle(double DC);
void pwmStart();
void pwmStop();

#define _XTAL_FREQ 8000000
#include <xc.h>

#endif