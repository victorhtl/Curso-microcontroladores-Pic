// Inclua o arquivo com os bits de configuracao
#include "config.h"

void main(void){
    
    TRISB = 0b00000000;  // Pinos do PORTB como saida
    PORTB = 0b10000000;  // Pino 8 do PORTB com nivel logico alto
                         // Os demais pinos em nivel logico baixo
    
    while(1);            // Loop infinito
}