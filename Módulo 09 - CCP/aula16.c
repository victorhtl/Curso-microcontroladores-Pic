/*
 PWM automático com chave RA4
 */

#include "../Bibliotecas/PWM.h"
#include "../Bibliotecas/config.h"
#include <xc.h>

#define _XTAL_FREQ 8000000

void main(void) {
    ANSELA = 0;  
    TRISAbits.TRISA4 = 1;  

    char dc = 0;
    
    pwmInit(25000);
    pwmDutyCycle(10);
    
    while(1){      
        // Início do PWM se RA4 for acionado
        if(PORTAbits.RA4 == 0){
            while(PORTAbits.RA4 == 0) __delay_ms(100);
            pwmStart();  
            while(dc < 100){
                pwmDutyCycle(dc);
                dc++;
                __delay_ms(200);
            }
            pwmStop();
            dc = 0;
        }
       
        __delay_ms(100);
    }
}
