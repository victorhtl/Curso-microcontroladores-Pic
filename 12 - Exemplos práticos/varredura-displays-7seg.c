#include "../Bibliotecas/config.h"

#define _XTAL_FREQ 8000000

#define DISPLAY_TRISD TRISD
#define DISPLAY_PORT PORTD
#define DISPLAYU_T TRISAbits.TRISA0
#define DISPLAYU_P PORTAbits.RA0
#define DISPLAYD_T TRISAbits.TRISA1
#define DISPLAYD_P PORTAbits.RA1

unsigned char numeros_7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

// As interrup��es chaveiam os displays de 7 seg
void __interrupt() INT_TIMER(void){
  
    static enum {
        display1 = 1,
        display2,
        // display3,
        // display4,
    } displays = display2;
    
    DISPLAYU_P = 0;
    DISPLAYD_P = 0;
    
    switch(displays){
        // Unidade
        case display1:
            DISPLAY_PORT = numeros_7seg[0];
            DISPLAYU_P = 1;
            displays = display2;
            break;
            
        // Dezena 
        case display2:
            DISPLAY_PORT = numeros_7seg[1];
            DISPLAYD_P = 1;
            displays = display1;
            break; 
        /*
         
        // Centena 
        case display3:
            DISPLAY_PORT = numeros_7seg[0];
            DISPLAYC_P = 1;
            break;
        
        // Milhar
        case display4:
            DISPLAY_PORT = numeros_7seg[0];
            DISPLAYM_P = 1;
            break;
        */  
    }
    
    INTCONbits.TMR0IF = 0;    
    TMR0H = 0xFE;
    TMR0L = 0x0C;
} 

void main(void) {
    OSCCON = 0b01100000;
    
    ANSELD = 0;
    ANSELAbits.ANSA0 = 0;
    ANSELAbits.ANSA1 = 0;
    
    // Pinos dos displays
    DISPLAY_TRISD = 0;
    DISPLAY_PORT = 0;
    DISPLAYU_T = 0;
    DISPLAYU_P = 0;
    DISPLAYD_T = 0;
    DISPLAYD_P = 0;
    
    // Timer0 gerando interrup��es a cada 2ms
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    T0CON = 0x02;
    TMR0H = 0xFE;
    TMR0L = 0x0C;
    T0CONbits.TMR0ON = 1;
    
    while(1);
}
