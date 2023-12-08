#include "xc.h"

void main(void){
    OSCCON = 0x63;  // Habilita o oscilador interno a 8MHz
                    // Somente para o PIC18F45k22
    
    ANSELD = 0;     // Desabilita os canais analógicos do PORTD
                    // Somente para o PIC18F45k22

    TRISDbits.TRISD2 = 0; // Configura o pino RD2 do PORTD como saida
    PORTDbits.RD2 = 1;    // Seta o pino RD2 do PORTD em nível lógico alto

    while(1);
}