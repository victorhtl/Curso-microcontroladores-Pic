/*
 * DETERMINAR PERÍODO DE UM SINAL

 * Pino CCP como entrada
 * Habilitar as interrupções globais e periférico
 * Configurar registrador CCP1CON
 * Configurar o timer1
 * Habilitar interrupção pelo módulo CCP
 * Criar a função interrupção
 * Determinar o Período do sinal
 */

#include <xc.h>
#include <stdio.h>

#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"

#define _XTAL_FREQ 8000000
#define uchar unsigned char
#define uint unsigned int

union {
    uchar medida[2];
    uint resultado;
} t1, t2;

volatile uchar borda = 1;

void __interrupt() capture_mode(void){
    
    // Salva leitura da primeira borda
    if(borda == 1){
        t1.medida[0] = CCPR1L;
        t1.medida[1] = CCPR1H;
        borda = 2;
    }
    // Salva leitura da segunda borda
    else {
        t2.medida[0] = CCPR1L;
        t2.medida[1] = CCPR1H;
        borda = 1;
        
        TMR1H = 0;
        TMR1L = 0;
    }
    CCP1IF = 0;
}

void main(void){
    uint periodo;
    char screenBuff[16];
    
    ANSELD = 0;
    ANSELC = 0;
    TRISCbits.TRISC2 = 1;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    CCP1CON = 0x05;
    
    T1CON = 0x12;
    TMR1H = 0;
    TMR1L = 0;
    T1CONbits.TMR1ON = 1;
    
    CCP1IF = 0;
    CCP1IE = 1;
    
    lcdInit();
    lcdString("Periodo: ");
    lcdSetCursor(2, 1);
    
    while(1){
        periodo = t2.resultado - t1.resultado;
        
        sprintf(screenBuff, "%05u us", periodo);
        
        lcdSetCursor(2, 1);
        lcdString(screenBuff);
        
        __delay_ms(100);
    }
}
