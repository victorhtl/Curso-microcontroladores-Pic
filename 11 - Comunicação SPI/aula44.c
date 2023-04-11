// Comunicação SPI Master - PIC18F45k22

#include "../Bibliotecas/config.h"
#include "../Bibliotecas/SPI.h"
#define _XTAL_FREQ 8000000

#define SS1_DIR TRISCbits.RC6
#define SS1 PORTCbits.RC6

void main(void){
    char status_led = 0;
    char leitura_spi;
    
    ANSELA = 0;
    
    // Btn
    TRISAbits.TRISA4 = 1;
    
    // Led
    TRISAbits.TRISA0 = 0;
    PORTAbits.RA0 = 0;
  
    SS1_DIR = 0;
    SS1 = 1; 
    
    SPI_Init();
    
    while(1){
        if(!PORTAbits.RA4 && !status_led){
            while(!PORTAbits.RA4) __delay_ms(20);
            SS1 = 0;
            leitura_spi = SPI_Write(0xAA);
            status_led = 1;
            PORTAbits.RA0 = 1;
            SS1 = 1;
        }
        else if(!PORTAbits.RA4 && status_led){
            while(!PORTAbits.RA4) __delay_ms(20);
            SS1 = 0;
            leitura_spi = SPI_Write(0xFF);
            status_led = 0;
            PORTAbits.RA0 = 0;
            SS1 = 1;
        }
    }
}
