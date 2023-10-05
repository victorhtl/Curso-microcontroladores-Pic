#line 1 "C:/Users/user/Desktop/osa/apps/04_Mensagens/main.c"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../osacfg.h"
#line 1068 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
typedef  unsigned char  _OST_SMSG;
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../port/osa_include.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../port/pic18/osa_pic18_mikroc.h"
#line 41 "c:/users/user/desktop/osa/apps/04_mensagens/../../port/pic18/osa_pic18_mikroc.h"
typedef unsigned char OST_UINT8;
typedef unsigned int OST_UINT16;
typedef unsigned long OST_UINT32;
typedef unsigned char OST_BOOL;

typedef OST_UINT8 OST_UINT;
#line 93 "c:/users/user/desktop/osa/apps/04_mensagens/../../port/pic18/osa_pic18_mikroc.h"
extern volatile unsigned int _fsr;
extern volatile char _indf;
extern volatile char _postinc;
extern volatile char _postdec;
extern volatile char _preinc;

extern volatile unsigned char _fsr1l;

extern volatile char _pcl;
extern volatile char _pclath;
extern volatile char _pclatu;
extern volatile char _status;
extern volatile char _tosl;
extern volatile char _tosh;
extern volatile char _tosu;
extern volatile char _bsr;
extern volatile char _wreg;
extern volatile char _intcon;
extern volatile char _rcon;
extern volatile char _stkptr;
#line 251 "c:/users/user/desktop/osa/apps/04_mensagens/../../port/pic18/osa_pic18_mikroc.h"
void _OS_JumpToTask (void);
#line 288 "c:/users/user/desktop/osa/apps/04_mensagens/../../port/pic18/osa_pic18_mikroc.h"
extern void _OS_ReturnSave (void);
extern void _OS_ReturnNoSave (void);
extern void _OS_EnterWaitMode (void);
extern void _OS_EnterWaitModeTO (void);

extern void _OS_SET_FSR_CUR_TASK (void);
#line 397 "c:/users/user/desktop/osa/apps/04_mensagens/../../port/pic18/osa_pic18_mikroc.h"
char OS_DI (void);
void OS_RI (char);
#line 419 "c:/users/user/desktop/osa/apps/04_mensagens/../../port/pic18/osa_pic18_mikroc.h"
extern void _OS_CheckEvent (OST_UINT);
#line 1092 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
typedef  unsigned char  OST_SMSG;
#line 1110 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
typedef  char *  OST_MSG;







typedef

 volatile

 struct _OST_MSG_CB
{
 OST_UINT status;
 OST_MSG msg;

} OST_MSG_CB;
#line 1139 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
typedef struct
{
 OST_UINT cSize;
 OST_UINT cFilled;
 OST_UINT cBegin;

} OST_QUEUE_CONTROL;




typedef struct
{
 OST_QUEUE_CONTROL Q;
 OST_MSG *pMsg;

} OST_QUEUE;




typedef struct
{
 OST_QUEUE_CONTROL Q;
 OST_SMSG *pSMsg;

} OST_SQUEUE;
#line 1190 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
typedef struct
{
 OST_UINT bEventError : 1;
 OST_UINT bError : 1;

 OST_UINT bInCriticalSection : 1;

 OST_UINT bCheckingTasks : 1;


 OST_UINT bBestTaskFound : 1;





  OST_UINT bTimeout : 1; OST_UINT bGIE_CTemp : 1; OST_UINT bGIEL_CTemp : 1; 
#line 1218 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
} OST_SYSTEM_FLAGS;
#line 1235 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
typedef struct
{
 OST_UINT cPriority : 3;
 OST_UINT bReady : 1;
 OST_UINT bDelay : 1;


 OST_UINT bCanContinue: 1;
 OST_UINT bEnable : 1;
 OST_UINT bPaused : 1;


  


} OST_TASK_STATE;
#line 1270 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
typedef struct
{
 OST_TASK_STATE State;
  unsigned long  pTaskPointer;




  



  OST_UINT32  Timer;


} OST_TCB;
#line 1477 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
typedef OST_UINT8 OST_CSEM;
#line 1506 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
extern volatile   OST_SYSTEM_FLAGS _OS_Flags;
extern   OST_UINT _OS_Temp;


extern volatile   OST_UINT _OS_TempH;




extern volatile   OST_TASK_STATE _OS_State;
#line 1527 "c:/users/user/desktop/osa/apps/04_mensagens/../../osa.h"
extern   OST_TCB *    volatile _OS_CurTask;





 extern   OST_UINT _OS_Best_Priority;






 extern   OST_TCB *    volatile _OS_BestTask;
 extern   OST_TCB *    volatile _OS_LastTask;
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/osa_oldnames.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/system/osa_system.h"
#line 48 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/system/osa_system.h"
extern void OS_Init (void);



extern void OS_EnterCriticalSection (void);
extern void OS_LeaveCriticalSection (void);
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/system/osa_tasks.h"
#line 37 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/system/osa_tasks.h"
extern   OST_TCB _OS_Tasks[ 3 ];






void _OS_Task_Create(OST_UINT priority,  unsigned long  TaskAddr);
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/events/osa_bsem.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/events/osa_csem.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/events/osa_flag.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/events/osa_msg.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/events/osa_queue.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/events/osa_smsg.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/events/osa_squeue.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/timers/osa_stimer.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/timers/osa_stimer_old.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/timers/osa_dtimer.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/timers/osa_qtimer.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/timers/osa_ttimer.h"
#line 53 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/timers/osa_ttimer.h"
void _OS_InitDelay( OST_UINT32  Delay);
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/../../kernel/timers/osa_timer.h"
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/config.h"



void Init_MCU(void);
void TickTimerIE(void);

void Task_LED(void);
void Task_ADC(void);
void Task_LCD(void);
#pragma funcall main Task_LED
#pragma funcall main Task_ADC
#pragma funcall main Task_LCD
#line 16 "c:/users/user/desktop/osa/apps/04_mensagens/config.h"
void Init_MCU(void){
 ANSELA = 0;
 ANSELB = 0;
 ANSELC = 0;
 ANSELD = 0;
 ANSELE = 0;

 TRISC.TRISC2 = 1;
 ANSELC.ANSC2 = 1;

 TRISD = 0;
 PORTD = 0;
}


void TickTimerIE(void){
 T0CON =  0B01000100 ;
 TMR0L =  194 ;
 INTCON.GIEH = 1;
 INTCON.GIEL = 1;
 RCON.IPEN = 1;
 TMR0IE_bit = 1;
 TMR0IP_bit = 1;
 T0CON.TMR0ON = 1;
}
#line 1 "c:/users/user/desktop/osa/apps/04_mensagens/lcd.h"




sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
#line 5 "C:/Users/user/Desktop/osa/apps/04_Mensagens/main.c"
OST_MSG_CB msg_adc;


void INTERRUPT_HIGH() iv 0x0008 ics ICS_AUTO {
 if (TMR0IF_bit){
 TMR0L =  194 ;
 TMR0IF_bit = 0;

  { { ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;  { ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; } } ; { ; ; if (_OS_Tasks[0].State.bDelay) { if(!++_OS_Tasks[0].Timer) _OS_Tasks[0].State.bDelay = 0; } ; if (_OS_Tasks[1].State.bDelay) { if(!++_OS_Tasks[1].Timer) _OS_Tasks[1].State.bDelay = 0; } ; if (_OS_Tasks[2].State.bDelay) { if(!++_OS_Tasks[2].Timer) _OS_Tasks[2].State.bDelay = 0; } ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; } ; ; ; ; } ;
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


  { _OS_Task_Create(0, ( unsigned long )&(Task_LED)); } ;
  { _OS_Task_Create(0, ( unsigned long )&(Task_ADC)); } ;
  { _OS_Task_Create(0, ( unsigned long )&(Task_LCD)); } ;

  { GIE_bit  = 1; if ( IPEN_bit ) GIEL_bit  = 1;} ;

  for(;;) { _OS_Flags.bBestTaskFound = 0; _OS_Flags.bCheckingTasks = 1; _OS_Best_Priority = 7  + 1; ; _OS_CurTask = _OS_LastTask; do { if (_OS_CurTask >= (  OST_TCB * )_OS_Tasks + ( 3 -1)) _OS_CurTask = (  OST_TCB * )_OS_Tasks; else _OS_CurTask++;  _OS_State = _OS_CurTask->State ; if (! _OS_State.bEnable  || _OS_State.bPaused ) goto _OS_SCHED_CONTINUE; ; if (_OS_Best_Priority <= (_OS_Temp = _OS_State.cPriority )) goto _OS_SCHED_CONTINUE; if (! _OS_State.bReady )  { _OS_SCHED_RUN:; _OS_JumpToTask() ; _OS_SET_FSR_CUR_TASK(); _indf &= ~( 0x08  | 0x20 ); _indf |= *((char*)&_OS_State) & ( 0x08  | 0x20 ); ; if (!_OS_Flags.bCheckingTasks) goto SCHED_END; ; } if ( _OS_State.bDelay  && ! _OS_State.bCanContinue ) goto _OS_SCHED_CONTINUE; ; if ( _OS_State.bReady )  { _OS_Flags.bBestTaskFound = 1; _OS_BestTask = _OS_CurTask; _OS_Best_Priority = _OS_State.cPriority ; if (_OS_Best_Priority == 0 ) break; } _OS_SCHED_CONTINUE:;  } while ( 1  && _OS_CurTask != _OS_LastTask); if (_OS_Flags.bBestTaskFound) { _OS_Flags.bCheckingTasks = 0; _OS_LastTask = _OS_CurTask = _OS_BestTask; _OS_State = _OS_CurTask->State ; if ( _OS_State.bEnable  && ! _OS_State.bPaused ) goto _OS_SCHED_RUN; } SCHED_END:; } ;

}

void Task_LCD(void){
 static int count = 0;

 OST_MSG msg;

 for(;;){
 if( ((msg_adc).status & 1) ){
   { ; msg = (msg_adc).msg; (msg_adc).status = 0 ; ; } ;
 Lcd_Out(1,1,msg);
 }
  { _OS_InitDelay(20); { _OS_ReturnSave(); asm{ nop } ; } ; } ;
 }
}

void Task_ADC(void){
 static int leitura_adc;
 static char str[10];


   { ; (msg_adc).status = 0; (msg_adc).msg = (OST_MSG)  0; ; } ;
 for(;;){
 leitura_adc = ADC_Read(14);
 WordToStr(leitura_adc, str);

   { if ( ((msg_adc).status & 1) ) { { _OS_EnterWaitMode(); asm{ nop } ; } ; _OS_CheckEvent((!((msg_adc).status & 1)) != 0) ; } ; (msg_adc).status = 1; (msg_adc).msg = (OST_MSG)  (str); } ;

  { { _OS_EnterWaitMode(); asm{ nop } ; } ; _OS_CheckEvent((!((msg_adc).status & 1)) != 0) ; } ;

  { _OS_InitDelay(50); { _OS_ReturnSave(); asm{ nop } ; } ; } ;
 }
}

void Task_LED(void){
 for(;;)
 {
 LATD.RD0 = ~LATD.RD0;
  { _OS_InitDelay(300); { _OS_ReturnSave(); asm{ nop } ; } ; } ;
 }
}
