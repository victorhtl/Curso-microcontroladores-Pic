// RECEPTOR

#include "config.h"
#include "UART.h"

#define _XTAL_FREQ 8000000
#define ADDR 66  // Colocar 66 para microcontrolador e 33 para outro

void __interrupt(high_priority) INTER(void){
    char data = RCREG;
    
    if(RCSTAbits.RX9D && RCREG == ADDR){
        PORTD = 0xFF;
        PIR1bits.RC1IF = 0;
        RCSTAbits.ADDEN = 0;  // Interrupção para qualquer byte
    }
    else{
        PORTD = 0;
        PIR1bits.RC1IF = 0;
        RCSTAbits.ADDEN = 1;
    }
}

void main(void) {
    TRISD = 0;
    PORTD = 0;
    OSCCON = 0b01110011;
    uartInit(9600);
    ADCON1 = 0x0F;
    
    uartInit(9600);
    
    // Configuração global das interrupções
    INTCONbits.GIEH = 1;
    INTCONbits.GIEL = 1;
    RCONbits.IPEN = 1;
    
    // Interrupção UART
    PIR1bits.RC1IF = 0;
    IPR1bits.RC1IP = 1;
    PIE1bits.RC1IE = 1;
    
    // Habilita nono bit
    RCSTAbits.RX9 = 1;
    RCSTAbits.ADDEN = 1;  // Interrupção somente quando RX9D é setado
    
    while(1);
}