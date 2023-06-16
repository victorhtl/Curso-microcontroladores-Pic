#include "PWM.h"

void pwmInit(double freq){
    ANSELC = 0;
    TRISCbits.TRISC2 = 0;
    
    CCP1CON = 0x0F;
    T2CON = 0x01;
    
    PR2 = _XTAL_FREQ / (4.*freq*4.) - 1.;
}

void pwmDutyCycle(double DC){
    unsigned int CCPR;
    double _PR2 = PR2;
    
    CCPR = (100.-DC)*(_PR2+1.)*4./100.;
 
    CCPR1L = (unsigned char)(CCPR >> 2);
    CCP1CONbits.DC1B1 = CCPR & 0x02;
    CCP1CONbits.DC1B0 = CCPR & 0x01;
}

void pwmStart(){
    T2CONbits.TMR2ON = 1;
}

void pwmStop(){
    T2CONbits.TMR2ON = 0;
}