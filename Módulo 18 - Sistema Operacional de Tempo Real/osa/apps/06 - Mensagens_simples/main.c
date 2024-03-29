#include "../../osa.h"
#include "config.h"
#include "lcd.h"

OST_SMSG msg_adc1;
OST_SMSG msg_adc2;

// Nos PIC 18,16,12,etc. � ness�rio criar essa funcao interrupcao
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

  OS_Init();
  Init_MCU();
  TickTimerIE();
  ADC_Init();
  LCD_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);

  // Criacao de TASKS (maxima prioridade)
  OS_Task_Create(0, Task_LED);
  OS_Task_Create(0, Task_ADC1)
  OS_Task_Create(0, Task_ADC2);
  OS_Task_Create(0, Task_LCD);
    
  OS_EI();

  OS_Run();
  
}

void Task_LCD(void){
    OST_SMSG msg; // unsigned int
    char str[10];
    
    for(;;){
         if(OS_Smsg_Check(msg_adc1)){
               OS_Smsg_Accept(msg_adc1, msg);
               WordToStr(msg, str);
               Lcd_Out(1,1,str);
         }
         if(OS_Smsg_Check(msg_adc2)){
               OS_Smsg_Accept(msg_adc2, msg);
               WordToStr(msg, str);
               Lcd_Out(2,1,str);
         }
         OS_Delay(20);
    }
}

void Task_ADC1(void){
    static int leitura_adc;
    
    // Cria a mensagem
    OS_Smsg_Create(msg_adc1);
    
    for(;;){
         leitura_adc = ADC_Read(14);
         //WordToStr(leitura_adc, str);
         // A mensagem esta criada
         OS_Smsg_Send(msg_adc1, leitura_adc);
         
         OS_Cond_Wait(!OS_Smsg_Check(msg_adc1));
         
         OS_Delay(50);
    }
}

void Task_ADC2(void){
    static int leitura_adc;

    // Cria a mensagem
    OS_Smsg_Create(msg_adc2);

    for(;;){
         leitura_adc = ADC_Read(15);
         //WordToStr(leitura_adc, str);
         // A mensagem esta criada
         OS_Smsg_Send(msg_adc2, leitura_adc);

         OS_Cond_Wait(!OS_Smsg_Check(msg_adc2));

         OS_Delay(50);
    }
}

void Task_LED(void){
    for(;;)
    {
        LATD.RD0 = ~LATD.RD0;
        OS_Delay(300);
    }
}