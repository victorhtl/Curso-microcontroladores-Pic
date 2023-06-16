#include "UART.h"

void uartInit(unsigned int baudrate){
     
    RCSTAbits.SPEN = 1;  // Habilita canal UART
    TXSTAbits.TXEN = 1;  // Habilita a transmiss�o
    RCSTAbits.CREN = 1;  // Habilita a recep��o
       
    // Definindo BaudRate
    if(baudrate == 9600){
        BAUDCTLbits.BRG16 = 0;
        TXSTAbits.BRGH = 0;
        TXSTAbits.SYNC = 0;
        SPBRG = 12;
    }
    
}