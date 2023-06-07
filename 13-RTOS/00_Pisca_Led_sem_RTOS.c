/*
 * File: Conceito Sistema operacional de tempo real
 * Este software nao esta implementando o RTOS,
 * esta apenas mostrando os efeitos
 * 
 * Realizando contagem de tempo de tasks com 
 * o timer
 * 
 * Este software simula uma funcao delay, porem
 * durante a piscagem dos leds e possivel executar
 * qualquer outra funcao dentro do while
 */

#include <xc.h>
#include "../Bibliotecas/config.h"
#define _XTAL_FREQ 8000000

#define TRUE 1
#define FALSE 0

#define TMR0_VALUE 0xFE0C  // Tempo de incremento do timer em 1ms
#define TASK_TIME 300      // Tempo em milissegundos de cada task

// Variavel incrementada a cada estouro do TIMER0
volatile unsigned long int ticks = 0;

// Variavel de contagem das tarefas
volatile unsigned long int t0, t1, t2;

void MCU_Init(void);
void tick_Init(void);
void tick_ISR(void);

void task_1(void);
void task_2(void);
void task_3(void);

void __interrupt(high_priority) relogioTempoReal(void){
    if(TMR0IF){
        tick_ISR();
    }
}

void main(void) {
    
    MCU_Init();
    tick_Init();
    
    t0 = t1 = t2 = ticks;
    
    while(TRUE){
				// Pisca leds
        task_1();
        task_2();
        task_3();

				// .... continuacao do codigo
    }
}

void MCU_Init(void){
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    
    TRISD = 0;
}

/**
 * Sistema de tick
 */
void tick_ISR(void){
    INTCONbits.TMR0IF = 0;
    
    ticks++;
    TMR0H = TMR0_VALUE >> 8;
    TMR0L = TMR0_VALUE & 0xff;
}

/**
 * Inicia um processo de geracao de interrupcoes
 * O tempo de cada interrupcao e definido por TMR0_VALUE
 */
void tick_Init(void){
    T0CON = 0b00000001;
    TMR0H = TMR0_VALUE >> 8;
    TMR0L = TMR0_VALUE & 0xff;
    T0CONbits.TMR0ON = 1;
    
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    INTCON2bits.TMR0IP = 1;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    RCONbits.IPEN = 1;
}

/**
 * As tasks sao simuladas por acionamento dos LEDS no PORTD
 * Cada task e executada depois de ticks incrementar 
 * acima de TASK_TIME
 */
void task_1(void){
    if(ticks - t0 >= TASK_TIME){
        t0 = ticks;
        PORTDbits.RD0 = !PORTDbits.RD0;
    }
}
void task_2(void){
    if(ticks - t1 >= TASK_TIME){
        t1 = ticks;
        PORTDbits.RD1 = !PORTDbits.RD1;
    }
}
void task_3(void){
    if(ticks - t2 >= TASK_TIME){
        t2 = ticks;
        PORTDbits.RD2 = !PORTDbits.RD2;
    }
}