/* Exercício de pisca */

// Inclua o arquivo com os bits de configuracao
#include "config.h"

void main(void) {
    OSCCON = 0x63; // Seleciona o oscilador interno no modo 8MHz
                   // Somente se você quiser utilizar o oscilador interno !!!
    
    TRISD = 0;
    
    while(1){
        PORTD = 0x0F;
        __delay_ms(1000);
    
        PORTD = 0xF0;
        __delay_ms(1000);
    }
}
