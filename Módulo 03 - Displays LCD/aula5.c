#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"
#include <stdio.h>

void main(void) {
    OSCCON = 0x63; // Oscilador interno 8MHz
    char lcdTxt[6];
    
    int valorInteiro = 1;
    
    TRISD = 0;
    PORTD = 0;
    ANSELD = 0;
    
    lcdInit();
    
    while(1){
        valorInteiro++;
        sprintf(lcdTxt, "%d", valorInteiro);
        lcdStringCursor(1,1,lcdTxt);
        __delay_ms(500);
    }
}
