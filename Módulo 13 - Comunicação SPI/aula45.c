// SPI SLAVE - PIC18F4431
// O MASTER VAI ENVIAR UM BYTE 0xAA
// ACENDER O LED COM ESTE BYTE

#include "config.h"

char leitura_spi = 0;

void __interrupt() SPIDATA(void){   
    leitura_spi = SSPBUF;
    PIR1bits.SSPIF = 0;
}

void main(void) {
    OSCCON = 0b01110011;
    char lixo;
    
    TRISDbits.TRISD2 = 0; // LED
    PORTDbits.RD2 = 0;
    
    ADCON1 = 0x0F;
    
    TRISCbits.TRISC4 = 1; // SDI
    TRISCbits.TRISC5 = 0; // SDO
    TRISCbits.TRISC3 = 1; // SCK
    TRISAbits.TRISA5 = 1; // SS
    
    SSPSTAT = 0;
    SSPCON1 = 0b00100100;
    lixo = SSPBUF;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    PIE1bits.SSPIE = 1;
    PIR1bits.SSPIF = 0;
    
    while(1){
        if(leitura_spi == 0xAA){
            PORTDbits.RD2 = 1;
        } else if (leitura_spi == 0xFF){
            PORTDbits.RD2 = 0;
        }
    }
}
