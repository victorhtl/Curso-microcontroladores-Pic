#include "config.h"

void main(void){
    
    TRISB = 0b00000000;  // Pinos do PORTB como saída
    PORTB = 0b10000000;  // Pino 8 do PORTB com nível lógico alto
    
    while(1);
}