/*
 Encontrando Duty Cycle com Capture
 Frequencia
 */

#include <xc.h>
#include <stdio.h>

#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"

#define _XTAL_FREQ 8000000

#define u_char unsigned char
#define u_int unsigned int

// Estrutura que salva as 2 medidas (t1 e t2) do capture
struct {
    // Medida t1
    union {
        u_char medida[2];
        u_int resultado;
    } t1;
    // Medida t2
    union {
        u_char medida[2];
        u_int resultado;
    } t2;
    // Medida t3
    union {
        u_char medida[2];
        u_int resultado;
    } t3;
} capture;

// Variavel de controle sobre qual borda está sendo feito a captura
volatile u_char borda = 1;

// Esta interrução será chamada 2 vezes
void __interrupt() capture_mode(void){
    
    // Se for a primeira borda, salva em T1
    if(borda == 1) {
        capture.t1.medida[0] = CCPR1L;
        capture.t1.medida[1] = CCPR1H;
        borda = 2;
        
        // Próxima captura na borda de descida
        CCP1CON = 0b00000100;
    }
    
    // Se for a segunda borda, salva em T2
    else if(borda == 2){             
        capture.t2.medida[0] = CCPR1L;
        capture.t2.medida[1] = CCPR1H; 
        borda = 3;
        
        // Próxima captura na borda de subida
        CCP1CON = 0b00000101;
    } 
    
    // Se for a terceira borda, salva em T3
    else if(borda == 3){
        capture.t3.medida[0] = CCPR1L;
        capture.t3.medida[1] = CCPR1H; 
        borda = 1;
        
        TMR1H = 0;
        TMR1L = 0;
    }
    
    CCP1IF = 0;
}

void main(void) {
    u_int largura;
    u_int periodo;
    u_int duty_cycle;
    u_int frequencia;
    float f_periodo;
    
    char screenBuff[6];
    
    ANSELC = 0;
    ANSELD = 0;
    
    // Pino CCP1 como entrada
    TRISC2 = 1;
    
    // Interrupção por CCP
    GIE = 1;
    PEIE = 1;
    
    // Timer1 configurado para 0,5 us em cada incremento
    T1CON = 0x02;
    TMR1H = 0;
    TMR1L = 0;
    TMR1ON = 1;
    
    // Modo capture configurado para cada borda de subida
    CCP1CON = 0b00000101;
    CCP1IF = 0;
    CCP1IE = 1;
    
    lcdInit();
    lcdString("DC: ");
    lcdSetCursor(2, 1);
    lcdString("Freq: ");
    
    while(1){
        largura = capture.t2.resultado - capture.t1.resultado;
        largura = largura / 2;
        periodo = capture.t3.resultado - capture.t1.resultado;
        periodo = periodo / 2;
        duty_cycle = ((float) largura / periodo) * 100;
        
        f_periodo = (float) periodo / 1000000;
        frequencia = 1. / f_periodo;

        sprintf(screenBuff, "%03u%%", duty_cycle);
        lcdSetCursor(1, 5);
        lcdString(screenBuff);

        sprintf(screenBuff, "%05u Hz", frequencia);
        lcdSetCursor(2, 7);
        lcdString(screenBuff);
        
        __delay_ms(100);            
    }
}
