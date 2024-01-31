// Comunicação SPI Master

#include "../Bibliotecas/config.h"

void SPI_Init();

void main(){
    SPI_Init();

    while(1);
}

void SPI_Init(){
    ANSELCbits.ANSC3 = 0;
    ANSELCbits.ANSC4 = 0;
    ANSELCbits.ANSC5 = 0;
    
    TRISCbits.TRISC3 = 0; // CLOCK OUTPUT
    PORTCbits.RC3 = 0;
    TRISCbits.TRISC4 = 1; // DATA INPUT
    PORTCbits.RC4 = 1;
    TRISCbits.TRISC5 = 0; // DATA OUTPUT
    PORTCbits.RC5 = 0;
    
    SSP1STAT = 0;
    SSP1CON1 = 0b00100000;
}