#include "config.h"
#define _XTAL_FREQ 8000000

void main(void) {
    ANSELD = 0;
    ANSELA = 0;
    
    TRISD = 0;

    // Define o pino 4 do PORTA como entrada
    TRISAbits.TRISA4 = 1;
    
    char count = 0;
    
    // Loop infinito
    while(1){
        if(PORTAbits.RA4 == 0){  // Se o botao for pressionado
            PORTD = count;       // Altera o nivel logico do PORTD
            count++;             // Incrementa count

            if(count == 255) count = 0; // Controle da variavel para nao passar de 255

            // Funcao delay para tratar o debouncing do botao
            __delay_ms(300);          
        }
    }
}
