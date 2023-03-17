#ifndef _EEPROM_H_
#define	_EEPROM_H_

// Escreve 1 byte na EEPROM interna
// ADDR -> endereço de memória
// DATA -> byte a ser gravado
void eepromWrite(char ADDR, char DATA);

// Lê 1 byte da EEPROM interna
// ADDR -> endereço da memória
char eepromRead(char ADDR);

// Escreve um Inteiro na EEPROM interna
// ADDR -> endereço de memória
// DATA -> Inteiro a ser gravado
void eepromWriteInt(char ADDR, int DATA);

// Lê um Inteiro na EEPROM interna
// ADDR -> endereço a ser lido
int eepromReadInt(char ADDR);

// Escreve um Long Int na EEPROM interna
void eepromWriteLong(char ADDR, long int DATA);

// Le um Long Int da EEPROM interna
long int eepromReadLong(char ADDR);

// Escreve um float na EEPROM
void eepromWriteFloat(char ADDR, float DATA);

// Le um float da EEPROM
float eepromReadFloat(char ADDR);

// Escreve um array na memória
// Necessário passar o tamanho exato do array
void eepromWriteArray(char ADDR, char tamanho, char *ARRAY);

// Le um array da memória
// Necessário passar o tamnho exato do array
// Recebe o array que será populado
void eepromReadArray(char ADDR, char tamanho, char *ARRAY);

#include <xc.h>

#endif

