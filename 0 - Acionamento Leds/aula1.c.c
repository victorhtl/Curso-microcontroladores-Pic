#include "config.h"

void main(void){
    
    TRISB = 0b00000000;  // Pinos do PORTB como sa�da
    PORTB = 0b10000000;  // Pino 8 do PORTB com n�vel l�gico alto
    
    while(1);
}