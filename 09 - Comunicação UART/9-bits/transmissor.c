// Transmissor - Opera��o em 9 bits
// Botoes no RA4 e RA5 enviam um dado pela UART

#include "../Bibliotecas/config.h"
#include "../Bibliotecas/UART.h"
#define _XTAL_FREQ 8000000

void main(void)
{
    ANSELA = 0;

    uartInit(9600);

    TXSTA1bits.TX9 = 1;  // Habilita modo 9 bits
    TXSTA1bits.TX9D = 1; // Nono bit em 1

    while (1)
    {
        if (!PORTAbits.RA4)
        {
            while (!PORTAbits.RA4)
                __delay_ms(20);
            // Manda endere�o
            TXREG1 = 66;
            __delay_ms(2000);

            // Comunica��o
            TXSTA1bits.TX9D = 0; // Nono bit em 0
            TXREG1 = 'a';
            TXSTA1bits.TX9D = 1;
        }

        if (!PORTAbits.RA5)
        {
            while (!PORTAbits.RA5)
                __delay_ms(20);
            // Manda endere�o
            TXREG1 = 33;
            __delay_ms(2000);

            // Comunica��o
            TXSTA1bits.TX9D = 0; // Nono bit em 0
            TXREG1 = 'a';
            TXSTA1bits.TX9D = 1;
        }
    }
}