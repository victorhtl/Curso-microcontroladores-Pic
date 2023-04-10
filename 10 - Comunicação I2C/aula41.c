// Comunicação I2C Modo Master

#include "../Bibliotecas/config.h"
#include "../Bibliotecas/LCD4bits.h"
#include "../Bibliotecas/I2C.h"
#define _XTAL_FREQ 8000000

void main(void) {
    char leitura[12];
    
    I2C_Init();
    lcdInit();
    
    // Escrita
    I2C_Start();            // Start bit
    I2C_Write(0b10101000);  // Endereço do dispositivo modo escrita
    I2C_Write(0);           // Endereço de memória do dispositivo
    I2C_Write('O');         // Dados a serem escritos no dispositivo
    I2C_Write('l');
    I2C_Write('a');
    I2C_Write(' ');
    I2C_Write('M');
    I2C_Write('u');
    I2C_Write('n');
    I2C_Write('d');
    I2C_Write('o');
    I2C_Stop();             // Stop bit
    
    __delay_ms(100);
    
    // Leitura
    I2C_Start();            // Start Bit
    I2C_Write(0b10101000);  // Endereço do dispositivo modo escrita
    I2C_Write(0);           // Endereço de memória do dispositivo
    I2C_Rep_Start();        // Repeated Start
    I2C_Write(0b10101001);  // Endereço do dispositivo modo leitura
    
    for(char i = 0; i < 8; i++){
        leitura[i] = I2C_Read(1);
    }
    leitura[8] = I2C_Read(0);
    leitura[9] = '\0';
    
    I2C_Stop();              // Stop bit
    
    lcdClean();
    lcdStringCursor(1,1, leitura);
    while(1);
}
