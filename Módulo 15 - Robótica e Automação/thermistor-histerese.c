#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/ADC.h"

#include <stdio.h>
#include <math.h>

#define _XTAL_FREQ 8000000

#define Vin 5.0          // define constante igual a 5.0
#define T0 298.15        // define constante igual a 298.15 Kelvin 
#define Rt 10000         // Resistor do divisor de tensao 
#define R0 10000         // Valor da resistencia inicial do NTC 
#define T1 273.15        // [K] in datasheet 0º C
#define T2 373.15        // [K] in datasheet 100° C 
#define RT1 35563        // [ohms] resistencia in T1 
#define RT2 549          // [ohms] resistencia in T2 

void main(void){
    float beta;        // parametros iniciais [K]
    float Rinf;        // parametros iniciais [ohm]
    float TempKelvin;  // variable output
    float TempCelsius; // variable output
    float Vout;        // Vout in A0
    float Rout;        // Rout in A0
    
    char estado = 0;
    TRISCbits.TRISC0 = 0;
    PORTCbits.RC0 = 0;
    
    char screen[16];
    
    lcdInit();
    adcInit();
    
    // Calculo temperatura
    beta = (log(RT1 / RT2)) / ((1 / T1) - (1 / T2)); // calculo de beta
    Rinf = R0 * exp(-beta / T0);                     // calculo de Rinf
    
    while(1){
        // Calculo temperatura
        Vout = Vin * ((float)(adcRead()) / 1023.0); // calculo de V0 e leitura de A0
        Rout = (Rt * Vout / (Vin - Vout));          // calculo de Rout
        TempKelvin = (beta / log(Rout / Rinf));     // calculo da temp. em Kelvins
        TempCelsius = TempKelvin - 273.15;          // calculo da temp. em Celsius
        
        // Acionamento com histerese
        if(TempCelsius > 28 && estado == 0){
            PORTCbits.RC0 = 1;
            estado = 1;
        }
        if(TempCelsius < 25 && estado == 1){
            PORTCbits.RC0 = 0;
            estado = 0;
        }
        
        sprintf(screen, "%.2f", TempCelsius);
        
        lcdStringCursor(1,1,screen);
        
        __delay_ms(100);
    }
}