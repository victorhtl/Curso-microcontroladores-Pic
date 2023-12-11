#include "config.h"

#define PRESSIONADO 0
#define BOTAO PORTCbits.RC0

void main(void) {
    OSCCON = 0x63; // Seleciona o oscilador interno no modo 8MHz
    
    char incrementador = 0;
    
    TRISD = 0;
    PORTD = 0;
    
    // Configura o pino RC0 como input digital
    ANSELC = 0;
    TRISCbits.TRISC0 = 1;
    
    while(1){
        if(BOTAO == PRESSIONADO){ // Se o pino for pressionado
            incrementador++;
            PORTD = incrementador;
            
            // Travo até que o botão seja solto
            while(BOTAO == PRESSIONADO) __delay_ms(20);
        }
    }
}
