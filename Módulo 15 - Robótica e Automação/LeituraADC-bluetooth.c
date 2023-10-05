/*  
  Codigo para envio de temperatura ambiente pelo bluetooth
  com os dispositivos Sensor de temperatura NTC e HC-06

 * {TEMPON} inicia leitura de temperatura
 * {TEMPOF} encerra leitura de temperatura
 
 * { - Inicio
 * } - Fim
 * TEMP - leitura de temperatura
 * ON - Inicia
 * OF - Desliga
*/

#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/ADC.h"
#include "../Bibliotecas/UART.h"

#include <stdio.h>
#include <math.h>

#define _XTAL_FREQ 8000000

#define MAX 16

// *****************************************
// Interrup��o que recebe a comunica��o UART
volatile char pacote[MAX], *protocolo;
volatile char decodificar = 0;

char envia_temp = 0;

void __interrupt(high_priority) UARTINT(void){
    
    char data;
    static char salvando = 0, controle = 0;
    
    if(RCSTA1bits.OERR == 1){ 
        RCSTA1bits.CREN = 0;  
        RCSTA1bits.CREN = 1;
    }
    
    data = RCREG1;
    
    // Inicia o protocolo
    if(data == '{' && !salvando){
        protocolo = pacote;
        salvando = 1;
    }
    
    // Finaliza o protocolo
    else if(data == '}' && salvando){
        *protocolo = '\0';
        salvando = 0;
        decodificar = 1;
        controle = 0;
    }
    
    // Salva o protocolo
    else if(salvando && controle < MAX){
        *protocolo = data;
        protocolo++;
        controle++;
    }
    
    // Controle do tamanhos
    else if (controle >= MAX){
        TXREG1 = 'E';
        while(!TXSTA1bits.TRMT);
        TXREG1 = 'R';
        while(!TXSTA1bits.TRMT);
        TXREG1 = 'R';
        while(!TXSTA1bits.TRMT);
        TXREG1 = 'O';
        while(!TXSTA1bits.TRMT);
        salvando = 0;
        controle = 0;
    }
    
    PIR1bits.RC1IF = 0;
}

// Decodifica string recebida pela UART
void decode(void);

#define Vin 5.0          // define constante igual a 5.0
#define T0 298.15        // define constante igual a 298.15 Kelvin 
#define Rt 10000         // Resistor do divisor de tensao 
#define R0 10000         // Valor da resistencia inicial do NTC 
#define T1 273.15        // [K] in datasheet 0? C
#define T2 373.15        // [K] in datasheet 100? C 
#define RT1 35563        // [ohms] resistencia in T1 
#define RT2 549          // [ohms] resistencia in T2 

void main(void){
    float beta;        // parametros iniciais [K]
    float Rinf;        // parametros iniciais [ohm]
    float TempKelvin;  // variable output
    float TempCelsius; // variable output
    float Vout;        // Vout in A0
    float Rout;        // Rout in A0
    
    char screen[16];
    
    adcInit();
    lcdInit();
    uartInit(9600); 
    
    // Configura��o geral UART e interrup��es
    INTCONbits.GIEH = 1;
    INTCONbits.GIEL = 1;
    RCONbits.IPEN = 1;  
    PIR1bits.RC1IF = 0;
    IPR1bits.RC1IP = 1;
    PIE1bits.RC1IE = 1;
    
    // Calculo temperatura
    beta = (log(RT1 / RT2)) / ((1 / T1) - (1 / T2)); // calculo de beta
    Rinf = R0 * exp(-beta / T0);                     // calculo de Rinf
    
    while(1){
        // Calculo temperatura
        Vout = Vin * ((float)(adcRead(0)) / 1023.0); // calculo de V0 e leitura de A0
        Rout = (Rt * Vout / (Vin - Vout));           // calculo de Rout
        TempKelvin = (beta / log(Rout / Rinf));      // calculo da temp. em Kelvins
        TempCelsius = TempKelvin - 273.15;           // calculo da temp. em Celsius
        
        // Decodifica a mensagem UART
        if(decodificar){
            decode();
        }
        
        sprintf(screen, "%.2f", TempCelsius);
        lcdStringCursor(1,1,screen);
        
        // Inicia envio da leitura ADC (termistor)
        if(envia_temp){
            sprintf(screen, "%.2f\r\n", TempCelsius);
            uartString(screen);
        }
        
        __delay_ms(700);
    }
}

void decode(void){
    INTCONbits.GIEH = 0;
    
    if(pacote[0] == 'T' && pacote[1] == 'E' && pacote[2] == 'M' && pacote[3] == 'P' && pacote [4] == 'O' && pacote [5] == 'N'){
        envia_temp = 1;
    }
    else if(pacote[0] == 'T' && pacote[1] == 'E' && pacote[2] == 'M' && pacote[3] == 'P' && pacote [4] == 'O' && pacote [5] == 'F'){
        envia_temp = 0;
    }
    
    decodificar = 0;
    INTCONbits.GIEH = 1;
}