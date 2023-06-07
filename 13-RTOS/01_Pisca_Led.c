#include "../../osa.h"

#define T2CON_CONST     0B01001101   //Timer2 ON, Prescaler 1:4 e Postscaler 1:10
#define PR2_CONST       (49)         //1us para FOSC

//Prot�tipos
void Init_MCU(void);
void TickTimerIE(void);

void Task_LED0(void);
void Task_LED1(void);
void Task_LED2(void);

//Informa para o Linker do compilador mikroC que as fun��es (tasks) ser�o chamadas
//Indiretamentes pelo SO.
#pragma funcall main Task_LED0
#pragma funcall main Task_LED1
#pragma funcall main Task_LED2

void INTERRUPT_HIGH() iv 0x0008 ics ICS_AUTO {
    if (TMR2IF_bit){
        TMR2IF_bit = 0;
        OS_Timer();
    }
}

void main() {
  OSCCON = 0b01100011;

  OS_Init();                         //Inicializa RTO's
  Init_MCU();
  TickTimerIE();

  //Cria as tasks. M�xima prioridade = 0. M�nima prioridade = 7. d
  OS_Task_Create(0, Task_LED0);      //Cria task LE0 (m�xima prioridade)
  OS_Task_Create(0, Task_LED1);      //Cria task LE1 (m�xima prioridade)
  OS_Task_Create(0, Task_LED2);      //Cria task LE2 (m�xima prioridade)

  //� poss�vel editar a fun��o OS_EI() "Operacional System Enable Interrupt"
  //OS_EI();                         // Enable interrupts

  //.....
  OS_Run();                          //Executa o scheduler
}

void Init_MCU(void){
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;

    TRISD = 0;        //PORTD configurado como Sa�da
    PORTD = 0;        //LEDs OFF
}


void TickTimerIE(void){
     //Carrega configura��o do TIMER2 (OS_TickTimer)
    T2CON = T2CON_CONST;
    PR2 = PR2_CONST;
    //Configura��o geral das Interrup��es
    INTCON.GIEH = 1;
    INTCON.GIEL = 1;
    RCON.IPEN = 1;
    //Habilita a interrup��o do TIMER2  (OS_TickTimer)
    TMR2IE_bit = 1;
    TMR2IP_bit = 1;
    T2CON.TMR2ON = 1;
}

void Task_LED0(void){
    for(;;) //loop infinito
    {
        LATD.RD0 = ~LATD.RD0;
        OS_Delay(300);
    }
}

void Task_LED1(void){
    for(;;)
    {
        LATD.RD1 = ~LATD.RD1;
        OS_Delay(300);
    }
}

void Task_LED2(void){
    for(;;)
    {
        LATD.RD2 = ~LATD.RD2;
        OS_Delay(300);
    }
}