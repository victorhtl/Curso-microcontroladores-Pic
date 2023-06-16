#include "../../osa.h"
#include "config.h"

// Nos PIC 18,16,12,etc. É nessário criar essa funcao interrupcao
void INTERRUPT_HIGH() iv 0x0008 ics ICS_AUTO {
    if (TMR0IF_bit){
        TMR0L = TMR0_CONST;
        TMR0IF_bit = 0;
        // Incremento do timer do sistema operacional
        OS_Timer();
    }
}

void main() {
  OSCCON = 0b01100011;

  OS_Init();                         //Inicializa RTO's
  Init_MCU();
  TickTimerIE();

  // Criacao de TASKS (maxima prioridade)
  OS_Task_Create(0, Task_LED0);
  OS_Task_Create(0, Task_LED1);
  OS_Task_Create(0, Task_LED2);
  
  // Bloquear todas as tasks
  OS_Bsem_Reset(BS_LED0);
  OS_Bsem_Reset(BS_LED1);
  OS_Bsem_Reset(BS_LED2);
    
  OS_EI();

  OS_Run();
  
}

void Task_LED0(void)
{
    // Desbloquear a task_led0
    OS_Bsem_Set(BS_LED0);

    for(;;)
    {
        // Espera a task desbloquear
        OS_Bsem_Wait(BS_LED0);

        LATD.RD0 = ~LATD.RD0;
        OS_Delay(300);

        OS_Bsem_Reset(BS_LED0);
        OS_Bsem_Set(BS_LED1);

    }
}

void Task_LED1(void)
{
    for(;;)
    {
        OS_Bsem_Wait(BS_LED1);

        LATD.RD1 = ~LATD.RD1;
        OS_Delay(300);

        OS_Bsem_Reset(BS_LED1);
        OS_Bsem_Set(BS_LED2);
    }
}

void Task_LED2(void)
{
    for(;;)
    {
        OS_Bsem_Wait(BS_LED2);

        LATD.RD2 = ~LATD.RD2;
        OS_Delay(300);

        OS_Bsem_Reset(BS_LED2);
        OS_Bsem_Set(BS_LED0);
    }
}