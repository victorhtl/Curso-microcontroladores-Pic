// Teclado matricial de membrana

#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"
#include <stdio.h>

// Altere o PORT aqui
#define TECLADO_TRIS TRISC
#define TECLADO_PORT PORTC

char leTeclado(void);

void main(void) {
    char tecla;
    
    ANSELC = 0;
    TECLADO_TRIS = 0x0F; // Colunas como entrada, linhas como saida
    
    lcdInit();
    
    while(1){

        // Algoritmo que aguarda o pressionamento
        // do teclado
        do{
            tecla = 0x00;
            tecla = leTeclado();
        } while(tecla == 0x00);
        
        lcdComando(1, tecla);
        __delay_ms(200);
    }
}

char leTeclado(void){
    char tecla;

    // Energiza a primeira linha e lê colunas
    TECLADO_PORT = 0x10;
    if(TECLADO_PORT & 0x01){
        tecla = '1';
        while(TECLADO_PORT & 0x01) __delay_ms(20);
    }
    else if(TECLADO_PORT & 0x02){
        tecla = '2';
        while(TECLADO_PORT & 0x02) __delay_ms(20);
    } 
    else if(TECLADO_PORT & 0x04){
        tecla = '3';
        while(TECLADO_PORT & 0x04) __delay_ms(20);
    }
    else if(TECLADO_PORT & 0x08){
        tecla = 'A';
        while(TECLADO_PORT & 0x08) __delay_ms(20);
    } 

    // Energiza a segunda linha e lê colunas
    TECLADO_PORT = 0x20;
    if(TECLADO_PORT & 0x01){
        tecla = '4';
        while(TECLADO_PORT & 0x01) __delay_ms(20);
    }
    else if(TECLADO_PORT & 0x02){
        tecla = '5';
        while(TECLADO_PORT & 0x02) __delay_ms(20);
    } 
    else if(TECLADO_PORT & 0x04){
        tecla = '6';
        while(TECLADO_PORT & 0x04) __delay_ms(20);
    }
    else if(TECLADO_PORT & 0x08){
        tecla = 'B';
        while(TECLADO_PORT & 0x08) __delay_ms(20);
    }   

    // Energiza a terceira linha e lê colunas     
    TECLADO_PORT = 0x40;
    if(TECLADO_PORT & 0x01){
        tecla = '7';
        while(TECLADO_PORT & 0x01) __delay_ms(20);
    }
    else if(TECLADO_PORT & 0x02){
        tecla = '8';
        while(TECLADO_PORT & 0x02) __delay_ms(20);
    } 
    else if(TECLADO_PORT & 0x04){
        tecla = '9';
        while(TECLADO_PORT & 0x04) __delay_ms(20);
    }
    else if(TECLADO_PORT & 0x08){
        tecla = 'C';
        while(TECLADO_PORT & 0x08) __delay_ms(20);
    }     

    // Energiza a quarta linha e lê colunas  
    TECLADO_PORT = 0x80;
    if(TECLADO_PORT & 0x01){
        tecla = '*';
        while(TECLADO_PORT & 0x01) __delay_ms(20);
    }
    else if(TECLADO_PORT & 0x02){
        tecla = '0';
        while(TECLADO_PORT & 0x02) __delay_ms(20);
    } 
    else if(TECLADO_PORT & 0x04){
        tecla = '#';
        while(TECLADO_PORT & 0x04) __delay_ms(20);
    }
    else if(TECLADO_PORT & 0x08){
        tecla = 'D';
        while(TECLADO_PORT & 0x08) __delay_ms(20);
    } 
    return tecla;
}