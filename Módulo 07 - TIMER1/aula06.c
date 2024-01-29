/*
 Relógio digital programável
 Utilizando o timer1 como base de tempo
 Display lcd no PORTD no modo 4 bits
 
 Pino RA4 incrementa minutos
 Pino RC0 incrementa horas
 
 */

#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/config.h"
#include <xc.h>
#include <stdio.h>

#define _XTAL_FREQ 8000000

int seg = 0, min = 0, hora = 0;          

void __interrupt() int_TMR(void) {
    static int count = 0;
    count++;

        if(count == 4){
            count = 0;
            seg++;                  
            if (seg == 60){
                seg = 0;            
                min++;         
                if (min == 60){
                    min = 0;         
                    hora++;            
                    if (hora == 24){      
                        hora = 0;       
                    }
                }
            }
        }
        TMR1H = 0x0B; 
        TMR1L = 0xDC; 
        TMR1IF = 0;            
}

void main(void){
    char screenBuff[16];
    
    TRISAbits.TRISA4 = 1;
    TRISCbits.TRISC0 = 1;;
    
    ANSELA = 0;
    ANSELC = 0;
    ANSELD = 0;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    TMR1IE = 1;
    
    T1CON = 0b00110010;
    
    TMR1H = 0x0B;           
    TMR1L = 0xDC;      
    
    T1CONbits.TMR1ON = 1;
    
    lcdInit();              
    lcdSetCursor(1, 4);
    lcdString("RTC TIMER1");     
    lcdSetCursor(2, 5);
    lcdString("00:00:00"); 
       
    while(1){    
        if (!PORTCbits.RC0){
            hora++; 
            if (hora == 24) hora = 0;  
            __delay_ms(300);
        }
        
        if (!PORTAbits.RA4){
            min++;                
            if(min == 60) min = 0;   
            __delay_ms(300);
        }
            
        sprintf(screenBuff, "%02d:%02d:%02d", hora, min, seg); 	 
        
        lcdSetCursor(2, 5);
        lcdString(screenBuff); 
        
        __delay_ms(100);
    }
}