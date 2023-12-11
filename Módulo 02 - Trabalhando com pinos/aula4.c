/* funcionamento do delay */

#include "config.h"

void main(void) {
    OSCCON = 0x63; // Seleciona o oscilador interno no modo 8MHz
                   // Somente se você quiser utilizar o oscilador interno !!!
    
    TRISD = 0;
    
    while(1){
        PORTD = 0xff; // Acende
        __delay_ms(500); // TRAVA
        PORTD = 0;    // Apaga
        __delay_ms(500); // TRAVA
    }
}