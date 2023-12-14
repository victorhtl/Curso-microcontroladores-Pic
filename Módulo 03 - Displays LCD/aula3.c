#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"

void main(void) {
    OSCCON = 0x63; // Oscilador interno 8MHz
    
    TRISD = 0;
    PORTD = 0;
    ANSELD = 0;
    
    lcdInit();
    lcdString("Ola pessoal");
    
    while(1);
}
