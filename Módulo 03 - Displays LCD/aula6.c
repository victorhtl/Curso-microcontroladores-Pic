#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"

void main(void) {
    OSCCON = 0x63; // Oscilador interno 8MHz
    
    TRISD = 0;
    PORTD = 0;
    ANSELD = 0;
    
    lcdInit();
    
    for(char i; i<3; i++){
        lcdStringCursor(1,1,"Atencao!!!");
        __delay_ms(500);
        lcdClean();
        __delay_ms(500);        
    }
    
    lcdStringCursor(1,3,"Voce precisa");
    lcdStringCursor(2,5,"aprender");
    __delay_ms(500);
    lcdComando(1, '.');
    __delay_ms(500);
    lcdComando(1, '.');
    __delay_ms(500);
    lcdComando(1, '.');
    __delay_ms(500);
    lcdClean();
    lcdStringCursor(1,5,"Displays");
    lcdStringCursor(2,6,"LCD!!!");
    
    while(1);
}
