/* Deve-se verificar 12 pressionamentos
 * em um botão e incrementar uma variável. A
 * verificação deverá ser através da interrupção 
 * por INT0. No processamento, deve-se
 * acender e apagar um LED conectado o pino RB0 em 
 * intervalos de 1 segundo 
 */

#include <xc.h>
#include <stdio.h>
#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"

#define _XTAL_FREQ 8000000

char contaPress;
char conta = 0;

void __interrupt() int_ext(void) 
{
    if(TMR0IF)  // A cada 2 pressionadas no botão este FLAG vale 1.
    {
        conta++;
        if(conta >= 100) conta=0;
    
    // Retorna a interrupção para zero
    }
    TMR0IF = 0;
    TMR0 = 255;
    // 
}

void main(void) {
    char buffer[16];
    
    TRISAbits.TRISA4 = 1;
    TRISCbits.TRISC0 = 1;
    
    TRISCbits.TRISC2 = 0;
    LATCbits.LATC2 = 0;
    
    ADCON1 = 0x0F; 
    // Desabilita todos os canais A/D;
    
    INTCON = 0b10100000;
    // Interrupção global habilitada;
    // Interrupção por TIMER0 Habilitada;
    
    T0CON = 0b11100000;
    // TMR0ON = 1 - Habilita TIMER0;
    // T08BIT = 1 - Modo de operação em 8 bits;
    // T0CS = 1 - Incremento por sinal externo;
    // T0SE = 0 - Incremento em TMR0 será na borda de subida do sinal;
    // PSA = 0 - Prescaler habilitado;
    // PS2, PS1, PS0 = 1 - Prescaler de 1:2;
    
    TMR0L = 255;
    // Inicia o registrador TMR0 com o valor 250
    
    iniciaLcd();
    enviaBuffer(1, 6, "TIMER0");
    enviaBuffer(2, 3, "CONTAGEM: 00");
    
    while(1)
    {
        __delay_ms(1000);
        
        LATCbits.LATC2 = ~LATCbits.LATC2;
        sprintf(buffer, "%02d", conta);
        enviaBuffer(2, 13, buffer);
    }
}