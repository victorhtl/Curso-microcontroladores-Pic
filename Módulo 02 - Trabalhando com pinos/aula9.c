#include "config.h"

#define PRESSIONADO 0
#define B1 PORTCbits.RC0
#define B2 PORTCbits.RC1

void main(void) {
    OSCCON = 0x63; // Seleciona o oscilador interno no modo 8MHz
    
    char incrementador = 1;
    
    TRISD = 0;
    PORTD = 1;
    
    // Configura o pino RC0 como input digital
    ANSELC = 0;
    TRISCbits.TRISC0 = 1;
    
    // Configura pino RC1 como input digital
    TRISCbits.TRISC1 = 1;
    
    while(1){
        if(B1 == PRESSIONADO){ // Se o pino for pressionado
            
            incrementador = incrementador<<1;
            
            if(incrementador >= 128) incrementador = 128;
            
            PORTD = (char) incrementador;
            
            // Travo até que o botão seja solto
            while(B1 == PRESSIONADO) __delay_ms(20);
        }
        if(B2 == PRESSIONADO){ // Se o pino for pressionado
            incrementador = incrementador>>1;
            if(incrementador <= 1) incrementador = 1;
            PORTD = (char) incrementador;
            
            // Travo até que o botão seja solto
            while(B2 == PRESSIONADO) __delay_ms(20);
        }
    }
}
