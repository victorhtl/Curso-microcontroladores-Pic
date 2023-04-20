#include <xc.h>
#include <stdio.h>
#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"

#define _XTAL_FREQ 8000000

// Pino de disparo do sensor
#define TRIG_PIN TRISCbits.TRISC0
#define TRIG_NIV PORTCbits.RC0

// Pino de recebimento do sensor
#define ECHO_PIN TRISCbits.TRISC2

#define uchar unsigned char
#define uint unsigned int

// Estrutura que salva as 2 medidas (t1 e t2) do capture
struct {
    // Medida t1
    union {
        uchar medida[2];
        uint resultado;
    } t1, t2;
} sensor;

volatile uchar borda = 1;

void __interrupt() capture_mode(void){
    
    // Se for a primeira borda, salva em T1
    if(borda == 1) {
        sensor.t1.medida[0] = CCPR1L;
        sensor.t1.medida[1] = CCPR1H;
        borda = 2;
        
        // Próxima captura na borda de descida
        CCP1CON = 0b00000100;
    }
    
    // Se for a segunda borda, salva em T2
    else if(borda == 2){             
        sensor.t2.medida[0] = CCPR1L;
        sensor.t2.medida[1] = CCPR1H; 
        borda = 1;
        
        // Próxima captura na borda de subida
        CCP1CON = 0b00000101;
        
        TMR1H = 0;
        TMR1L = 0; 
    }
    
    CCP1IF = 0;
}

void disparo(void){
    TRIG_NIV = 1;
    __delay_us(10);
    TRIG_NIV = 0;
}

void main(void) {
    char lcdBuff[5];
    double largura;
    
    ANSELC = 0;
    ANSELD = 0;
    
    TRIG_PIN = 0;
    TRIG_NIV = 0;
    
    ECHO_PIN = 1;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    CCP1CON = 0b0000101;
    CCP1IF = 0;
    CCP1IE = 1;
    
    T1CON = 0b00010010;
    TMR1H = 0;
    TMR1L = 0;
    TMR1ON = 1;
    
    lcdInit();
    lcdString("Distancia mm");
    
    while(1){
        disparo();
        
        largura = (double) sensor.t2.resultado - sensor.t1.resultado;
        
        sprintf(lcdBuff, "%0.2f", (largura * 0.170));
        
        lcdSetCursor(2, 1);
        lcdString(lcdBuff);
        
        __delay_ms(200);
    }
}
