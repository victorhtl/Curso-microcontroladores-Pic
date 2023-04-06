#include "I2C.h"

// Inicializa comunica��o I2C modo master
void I2C_Init(void){
    ANSELCbits.ANSC4 = 0;
    ANSELCbits.ANSC3 = 0;
    
    SSP1ADD = (_XTAL_FREQ/1000000/4) - 1; // baudrate para 100KHz
    SSP1STATbits.SMP = 1;                 // Velocidade 100KHz
    SSP1CON1 = 0b00101000;
    while(SSP1STATbits.R_W);              // Verifica se h� alguma transmissao
    while(SSP1CON2 & 0x1F);               // Status da comunica��o 00011111
}

// Envia o bit de START na rede
void I2C_Start(void){
    SSP1CON2bits.SEN = 1;    // Envia o bit de start
    while(SSP1CON2bits.SEN); // Depois do bit de start este bit � limpo
}

// Envia um dado para a rede
void I2C_Write(char data){
    SSP1BUF = data;
    while(SSP1STATbits.R_W);      // Aguarda a transmissao
    while(SSP1CON2bits.ACKSTAT);  // Aguarda o ACK 
}

// @Params: ack - 1->ACK - 0->NACK
// @Returns: dado
char I2C_Read(char ack){
    char data;
    
    SSP1CON2bits.RCEN = 1;    // Habilita o recebimento
    while(SSP1CON2bits.RCEN); // Aguarda o dado chegar 
    
    data = SSP1BUF;
    
    // Envio do bit ACK ou NACK
    if(ack){
        SSP1CON2bits.ACKDT = 0;
        SSP1CON2bits.ACKEN = 1;
    } else {
        SSP1CON2bits.ACKDT = 1;
        SSP1CON2bits.ACKEN = 1;
    }
    while(SSP1CON2bits.ACKEN);
    return data;
}

// Envia o bit de STOP para a rede
void I2C_Stop(void){
    SSP1CON2bits.PEN = 1;     // Envia o bit de Stop
    while(SSP1CON2bits.PEN);  // Aguarda
}

// Envia o bit de Repeated Start para a rede
void I2C_Rep_Start(void){
    SSP1CON2bits.RSEN = 1;    // Envia o bit de restart
    while(SSP1CON2bits.RSEN); // Aguarda
}
