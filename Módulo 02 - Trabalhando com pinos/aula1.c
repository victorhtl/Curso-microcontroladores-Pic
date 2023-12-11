// Inclua o arquivo com os bits de configuracao
#include "config.h"

void main(void){
    
    TRISD = 0b00000000;  // Pinos do PORTD como saida
    PORTD = 0b10000000;  // Pino RD8 do PORTD com nivel logico alto
                         // Os demais pinos em nivel logico baixo
    
    while(1);            // Loop infinito
}