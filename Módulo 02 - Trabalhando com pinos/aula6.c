/* Exercício 2 */

#include "config.h"

void main(void) {
    OSCCON = 0x63; // Seleciona o oscilador interno no modo 8MHz
                   // Somente se você quiser utilizar o oscilador interno !!!
    
    char incrementador = 0;
    
    TRISD = 0;
    PORTD = 0;
    
    while(1){
        incrementador++;
        PORTD = incrementador;
        __delay_ms(50);
    }
}