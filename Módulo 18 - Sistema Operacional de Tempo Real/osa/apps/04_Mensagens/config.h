#define T0CON_CONST     0B01000100  //Timer0 ON, Prescaler 1:32
#define TMR0_CONST      194         //1ms para 8Mhz

void Init_MCU(void);
void TickTimerIE(void);

void Task_LED(void);
void Task_ADC(void);
void Task_LCD(void);

// Crie um pragma para cada thread
#pragma funcall main Task_LED
#pragma funcall main Task_ADC
#pragma funcall main Task_LCD

void Init_MCU(void){
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;

    TRISC.TRISC2 = 1;
    ANSELC.ANSC2 = 1;
    
    TRISD = 0;        //PORTD configurado como Sa?da
    PORTD = 0;        //LEDs OFF
}


void TickTimerIE(void){
    T0CON = T0CON_CONST;
    TMR0L = TMR0_CONST;
    INTCON.GIEH = 1;
    INTCON.GIEL = 1;
    RCON.IPEN = 1;
    TMR0IE_bit = 1;
    TMR0IP_bit = 1;
    T0CON.TMR0ON = 1;
}