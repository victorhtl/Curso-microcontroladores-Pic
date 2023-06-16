
_Init_MCU:

;config.h,18 :: 		void Init_MCU(void){
;config.h,19 :: 		ANSELA = 0;
	CLRF        ANSELA+0 
;config.h,20 :: 		ANSELB = 0;
	CLRF        ANSELB+0 
;config.h,21 :: 		ANSELC = 0;
	CLRF        ANSELC+0 
;config.h,22 :: 		ANSELD = 0;
	CLRF        ANSELD+0 
;config.h,23 :: 		ANSELE = 0;
	CLRF        ANSELE+0 
;config.h,25 :: 		TRISC.TRISC0 = 1;
	BSF         TRISC+0, 0 
;config.h,26 :: 		TRISD = 0;        //PORTD configurado como Sa?da
	CLRF        TRISD+0 
;config.h,27 :: 		PORTD = 0;        //LEDs OFF
	CLRF        PORTD+0 
;config.h,28 :: 		}
L_end_Init_MCU:
	RETURN      0
; end of _Init_MCU

_TickTimerIE:

;config.h,31 :: 		void TickTimerIE(void){
;config.h,32 :: 		T0CON = T0CON_CONST;
	MOVLW       68
	MOVWF       T0CON+0 
;config.h,33 :: 		TMR0L = TMR0_CONST;
	MOVLW       194
	MOVWF       TMR0L+0 
;config.h,34 :: 		INTCON.GIEH = 1;
	BSF         INTCON+0, 7 
;config.h,35 :: 		INTCON.GIEL = 1;
	BSF         INTCON+0, 6 
;config.h,36 :: 		RCON.IPEN = 1;
	BSF         RCON+0, 7 
;config.h,37 :: 		TMR0IE_bit = 1;
	BSF         TMR0IE_bit+0, BitPos(TMR0IE_bit+0) 
;config.h,38 :: 		TMR0IP_bit = 1;
	BSF         TMR0IP_bit+0, BitPos(TMR0IP_bit+0) 
;config.h,39 :: 		T0CON.TMR0ON = 1;
	BSF         T0CON+0, 7 
;config.h,40 :: 		}
L_end_TickTimerIE:
	RETURN      0
; end of _TickTimerIE

_INTERRUPT_HIGH:

;main.c,5 :: 		void INTERRUPT_HIGH() iv 0x0008 ics ICS_AUTO {
;main.c,6 :: 		if (TMR0IF_bit){
	BTFSS       TMR0IF_bit+0, BitPos(TMR0IF_bit+0) 
	GOTO        L_INTERRUPT_HIGH0
;main.c,7 :: 		TMR0L = TMR0_CONST;
	MOVLW       194
	MOVWF       TMR0L+0 
;main.c,8 :: 		TMR0IF_bit = 0;
	BCF         TMR0IF_bit+0, BitPos(TMR0IF_bit+0) 
;main.c,10 :: 		OS_Timer();
	BTFSS       __OS_Tasks+0, 4 
	GOTO        L_INTERRUPT_HIGH1
	MOVLW       1
	ADDWF       __OS_Tasks+5, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      __OS_Tasks+6, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      __OS_Tasks+7, 0 
	MOVWF       R2 
	MOVLW       0
	ADDWFC      __OS_Tasks+8, 0 
	MOVWF       R3 
	MOVF        R0, 0 
	MOVWF       __OS_Tasks+5 
	MOVF        R1, 0 
	MOVWF       __OS_Tasks+6 
	MOVF        R2, 0 
	MOVWF       __OS_Tasks+7 
	MOVF        R3, 0 
	MOVWF       __OS_Tasks+8 
	MOVF        __OS_Tasks+5, 0 
	IORWF       __OS_Tasks+6, 0 
	IORWF       __OS_Tasks+7, 0 
	IORWF       __OS_Tasks+8, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_INTERRUPT_HIGH2
	BCF         __OS_Tasks+0, 4 
L_INTERRUPT_HIGH2:
L_INTERRUPT_HIGH1:
	BTFSS       __OS_Tasks+9, 4 
	GOTO        L_INTERRUPT_HIGH3
	MOVLW       1
	ADDWF       __OS_Tasks+14, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      __OS_Tasks+15, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      __OS_Tasks+16, 0 
	MOVWF       R2 
	MOVLW       0
	ADDWFC      __OS_Tasks+17, 0 
	MOVWF       R3 
	MOVF        R0, 0 
	MOVWF       __OS_Tasks+14 
	MOVF        R1, 0 
	MOVWF       __OS_Tasks+15 
	MOVF        R2, 0 
	MOVWF       __OS_Tasks+16 
	MOVF        R3, 0 
	MOVWF       __OS_Tasks+17 
	MOVF        __OS_Tasks+14, 0 
	IORWF       __OS_Tasks+15, 0 
	IORWF       __OS_Tasks+16, 0 
	IORWF       __OS_Tasks+17, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_INTERRUPT_HIGH4
	BCF         __OS_Tasks+9, 4 
L_INTERRUPT_HIGH4:
L_INTERRUPT_HIGH3:
	BTFSS       __OS_Tasks+18, 4 
	GOTO        L_INTERRUPT_HIGH5
	MOVLW       1
	ADDWF       __OS_Tasks+23, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      __OS_Tasks+24, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      __OS_Tasks+25, 0 
	MOVWF       R2 
	MOVLW       0
	ADDWFC      __OS_Tasks+26, 0 
	MOVWF       R3 
	MOVF        R0, 0 
	MOVWF       __OS_Tasks+23 
	MOVF        R1, 0 
	MOVWF       __OS_Tasks+24 
	MOVF        R2, 0 
	MOVWF       __OS_Tasks+25 
	MOVF        R3, 0 
	MOVWF       __OS_Tasks+26 
	MOVF        __OS_Tasks+23, 0 
	IORWF       __OS_Tasks+24, 0 
	IORWF       __OS_Tasks+25, 0 
	IORWF       __OS_Tasks+26, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_INTERRUPT_HIGH6
	BCF         __OS_Tasks+18, 4 
L_INTERRUPT_HIGH6:
L_INTERRUPT_HIGH5:
	BTFSS       __OS_Tasks+27, 4 
	GOTO        L_INTERRUPT_HIGH7
	MOVLW       1
	ADDWF       __OS_Tasks+32, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      __OS_Tasks+33, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      __OS_Tasks+34, 0 
	MOVWF       R2 
	MOVLW       0
	ADDWFC      __OS_Tasks+35, 0 
	MOVWF       R3 
	MOVF        R0, 0 
	MOVWF       __OS_Tasks+32 
	MOVF        R1, 0 
	MOVWF       __OS_Tasks+33 
	MOVF        R2, 0 
	MOVWF       __OS_Tasks+34 
	MOVF        R3, 0 
	MOVWF       __OS_Tasks+35 
	MOVF        __OS_Tasks+32, 0 
	IORWF       __OS_Tasks+33, 0 
	IORWF       __OS_Tasks+34, 0 
	IORWF       __OS_Tasks+35, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_INTERRUPT_HIGH8
	BCF         __OS_Tasks+27, 4 
L_INTERRUPT_HIGH8:
L_INTERRUPT_HIGH7:
;main.c,11 :: 		}
L_INTERRUPT_HIGH0:
;main.c,12 :: 		}
L_end_INTERRUPT_HIGH:
L__INTERRUPT_HIGH62:
	RETFIE      1
; end of _INTERRUPT_HIGH

_main:

;main.c,14 :: 		void main() {
;main.c,15 :: 		OSCCON = 0b01100011;
	MOVLW       99
	MOVWF       OSCCON+0 
;main.c,17 :: 		OS_Init();                         //Inicializa RTO's
	CALL        _OS_Init+0, 0
;main.c,18 :: 		Init_MCU();
	CALL        _Init_MCU+0, 0
;main.c,19 :: 		TickTimerIE();
	CALL        _TickTimerIE+0, 0
;main.c,22 :: 		OS_Task_Create(0, Task_LED0);
	CLRF        FARG__OS_Task_Create_priority+0 
	MOVLW       _Task_LED0+0
	MOVWF       FARG__OS_Task_Create_TaskAddr+0 
	MOVLW       hi_addr(_Task_LED0+0)
	MOVWF       FARG__OS_Task_Create_TaskAddr+1 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+2 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+3 
	CALL        __OS_Task_Create+0, 0
;main.c,23 :: 		OS_Task_Create(0, Task_LED1);
	CLRF        FARG__OS_Task_Create_priority+0 
	MOVLW       _Task_LED1+0
	MOVWF       FARG__OS_Task_Create_TaskAddr+0 
	MOVLW       hi_addr(_Task_LED1+0)
	MOVWF       FARG__OS_Task_Create_TaskAddr+1 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+2 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+3 
	CALL        __OS_Task_Create+0, 0
;main.c,24 :: 		OS_Task_Create(0, Task_LED2);
	CLRF        FARG__OS_Task_Create_priority+0 
	MOVLW       _Task_LED2+0
	MOVWF       FARG__OS_Task_Create_TaskAddr+0 
	MOVLW       hi_addr(_Task_LED2+0)
	MOVWF       FARG__OS_Task_Create_TaskAddr+1 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+2 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+3 
	CALL        __OS_Task_Create+0, 0
;main.c,25 :: 		OS_Task_Create(0, Task_BTN);
	CLRF        FARG__OS_Task_Create_priority+0 
	MOVLW       _Task_BTN+0
	MOVWF       FARG__OS_Task_Create_TaskAddr+0 
	MOVLW       hi_addr(_Task_BTN+0)
	MOVWF       FARG__OS_Task_Create_TaskAddr+1 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+2 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+3 
	CALL        __OS_Task_Create+0, 0
;main.c,28 :: 		OS_Bsem_Reset(BS_LED0);
	BCF         __OS_Bsems+0, 0 
;main.c,29 :: 		OS_Bsem_Reset(BS_LED1);
	BCF         __OS_Bsems+0, 1 
;main.c,30 :: 		OS_Bsem_Reset(BS_LED2);
	BCF         __OS_Bsems+0, 2 
;main.c,32 :: 		OS_EI();
	BSF         GIE_bit+0, BitPos(GIE_bit+0) 
	BTFSS       IPEN_bit+0, BitPos(IPEN_bit+0) 
	GOTO        L_main9
	BSF         GIEL_bit+0, BitPos(GIEL_bit+0) 
L_main9:
;main.c,34 :: 		OS_Run();
L_main10:
	BCF         __OS_Flags+0, 4 
	BSF         __OS_Flags+0, 3 
	MOVLW       8
	MOVWF       __OS_Best_Priority+0 
	MOVF        __OS_LastTask+0, 0 
	MOVWF       __OS_CurTask+0 
	MOVF        __OS_LastTask+1, 0 
	MOVWF       __OS_CurTask+1 
L_main13:
	MOVLW       hi_addr(__OS_Tasks+27)
	SUBWF       __OS_CurTask+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main64
	MOVLW       __OS_Tasks+27
	SUBWF       __OS_CurTask+0, 0 
L__main64:
	BTFSS       STATUS+0, 0 
	GOTO        L_main16
	MOVLW       __OS_Tasks+0
	MOVWF       __OS_CurTask+0 
	MOVLW       hi_addr(__OS_Tasks+0)
	MOVWF       __OS_CurTask+1 
	GOTO        L_main17
L_main16:
	MOVLW       9
	ADDWF       __OS_CurTask+0, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      __OS_CurTask+1, 0 
	MOVWF       R1 
	MOVF        R0, 0 
	MOVWF       __OS_CurTask+0 
	MOVF        R1, 0 
	MOVWF       __OS_CurTask+1 
L_main17:
	MOVF        __OS_CurTask+0, 0 
	MOVWF       FSR0L+0 
	MOVF        __OS_CurTask+1, 0 
	MOVWF       FSR0L+1 
	MOVLW       1
	MOVWF       R0 
	MOVLW       __OS_State+0
	MOVWF       FSR1L+0 
	MOVLW       hi_addr(__OS_State+0)
	MOVWF       FSR1L+1 
L_main18:
	MOVF        POSTINC0+0, 0 
	MOVWF       POSTINC1+0 
	DECF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_main18
	BTFSS       __OS_State+0, 6 
	GOTO        L__main58
	BTFSC       __OS_State+0, 7 
	GOTO        L__main58
	GOTO        L_main21
L__main58:
	GOTO        ___main__OS_SCHED_CONTINUE
L_main21:
	MOVF        __OS_State+0, 0 
	MOVWF       R0 
	MOVLW       7
	ANDWF       R0, 1 
	MOVF        R0, 0 
	MOVWF       __OS_Temp+0 
	MOVF        __OS_Best_Priority+0, 0 
	SUBWF       __OS_Temp+0, 0 
	BTFSS       STATUS+0, 0 
	GOTO        L_main22
	GOTO        ___main__OS_SCHED_CONTINUE
L_main22:
	BTFSC       __OS_State+0, 3 
	GOTO        L_main23
___main__OS_SCHED_RUN:
	CALL        __OS_JumpToTask+0, 0
	CALL        __OS_SET_FSR_CUR_TASK+0, 0
	MOVLW       215
	ANDWF       __indf+0, 1 
	MOVLW       40
	ANDWF       __OS_State+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	IORWF       __indf+0, 1 
	BTFSC       __OS_Flags+0, 3 
	GOTO        L_main24
	GOTO        ___main_SCHED_END
L_main24:
L_main23:
	BTFSS       __OS_State+0, 4 
	GOTO        L_main27
	BTFSC       __OS_State+0, 5 
	GOTO        L_main27
L__main57:
	GOTO        ___main__OS_SCHED_CONTINUE
L_main27:
	BTFSS       __OS_State+0, 3 
	GOTO        L_main28
	BSF         __OS_Flags+0, 4 
	MOVF        __OS_CurTask+0, 0 
	MOVWF       __OS_BestTask+0 
	MOVF        __OS_CurTask+1, 0 
	MOVWF       __OS_BestTask+1 
	MOVF        __OS_State+0, 0 
	MOVWF       R0 
	MOVLW       7
	ANDWF       R0, 1 
	MOVF        R0, 0 
	MOVWF       __OS_Best_Priority+0 
	MOVF        __OS_Best_Priority+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main29
	GOTO        L_main14
L_main29:
L_main28:
___main__OS_SCHED_CONTINUE:
	MOVF        __OS_CurTask+1, 0 
	XORWF       __OS_LastTask+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main65
	MOVF        __OS_LastTask+0, 0 
	XORWF       __OS_CurTask+0, 0 
L__main65:
	BTFSC       STATUS+0, 2 
	GOTO        L__main56
	GOTO        L_main13
L__main56:
L_main14:
	BTFSS       __OS_Flags+0, 4 
	GOTO        L_main32
	BCF         __OS_Flags+0, 3 
	MOVF        __OS_BestTask+0, 0 
	MOVWF       __OS_CurTask+0 
	MOVF        __OS_BestTask+1, 0 
	MOVWF       __OS_CurTask+1 
	MOVF        __OS_CurTask+0, 0 
	MOVWF       __OS_LastTask+0 
	MOVF        __OS_CurTask+1, 0 
	MOVWF       __OS_LastTask+1 
	MOVF        __OS_CurTask+0, 0 
	MOVWF       FSR0L+0 
	MOVF        __OS_CurTask+1, 0 
	MOVWF       FSR0L+1 
	MOVLW       1
	MOVWF       R0 
	MOVLW       __OS_State+0
	MOVWF       FSR1L+0 
	MOVLW       hi_addr(__OS_State+0)
	MOVWF       FSR1L+1 
L_main33:
	MOVF        POSTINC0+0, 0 
	MOVWF       POSTINC1+0 
	DECF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_main33
	BTFSS       __OS_State+0, 6 
	GOTO        L_main36
	BTFSC       __OS_State+0, 7 
	GOTO        L_main36
L__main55:
	GOTO        ___main__OS_SCHED_RUN
L_main36:
L_main32:
___main_SCHED_END:
	GOTO        L_main10
;main.c,36 :: 		}
L_end_main:
	GOTO        $+0
; end of _main

_Task_BTN:

;main.c,38 :: 		void Task_BTN(void){
;main.c,39 :: 		for(;;){
L_Task_BTN37:
;main.c,41 :: 		do{
L_Task_BTN40:
;main.c,42 :: 		OS_Cond_Wait(!RC0_bit);
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	BTFSC       RC0_bit+0, BitPos(RC0_bit+0) 
	GOTO        L__Task_BTN67
	BSF         STATUS+0, 0 
	GOTO        L__Task_BTN68
L__Task_BTN67:
	BCF         STATUS+0, 0 
L__Task_BTN68:
	MOVLW       0
	BTFSC       STATUS+0, 0 
	MOVLW       1
	MOVWF       FARG__OS_CheckEvent+0 
	MOVF        FARG__OS_CheckEvent+0, 0 
	XORLW       0
	MOVLW       0
	BTFSS       STATUS+0, 2 
	MOVLW       1
	MOVWF       FARG__OS_CheckEvent+0 
	CALL        __OS_CheckEvent+0, 0
;main.c,43 :: 		OS_Delay(40);
	MOVLW       40
	MOVWF       FARG__OS_InitDelay_Delay+0 
	MOVLW       0
	MOVWF       FARG__OS_InitDelay_Delay+1 
	MOVWF       FARG__OS_InitDelay_Delay+2 
	MOVWF       FARG__OS_InitDelay_Delay+3 
	CALL        __OS_InitDelay+0, 0
	CALL        __OS_ReturnSave+0, 0
	NOP
;main.c,44 :: 		} while(RC0_bit);
	BTFSC       RC0_bit+0, BitPos(RC0_bit+0) 
	GOTO        L_Task_BTN40
;main.c,46 :: 		RD7_bit = ~RD7_bit;
	BTG         RD7_bit+0, BitPos(RD7_bit+0) 
;main.c,48 :: 		do{
L_Task_BTN43:
;main.c,49 :: 		OS_Cond_Wait(RC0_bit);
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	MOVLW       0
	BTFSC       RC0_bit+0, BitPos(RC0_bit+0) 
	MOVLW       1
	MOVWF       FARG__OS_CheckEvent+0 
	MOVF        FARG__OS_CheckEvent+0, 0 
	XORLW       0
	MOVLW       0
	BTFSS       STATUS+0, 2 
	MOVLW       1
	MOVWF       FARG__OS_CheckEvent+0 
	CALL        __OS_CheckEvent+0, 0
;main.c,50 :: 		OS_Delay(40);
	MOVLW       40
	MOVWF       FARG__OS_InitDelay_Delay+0 
	MOVLW       0
	MOVWF       FARG__OS_InitDelay_Delay+1 
	MOVWF       FARG__OS_InitDelay_Delay+2 
	MOVWF       FARG__OS_InitDelay_Delay+3 
	CALL        __OS_InitDelay+0, 0
	CALL        __OS_ReturnSave+0, 0
	NOP
;main.c,51 :: 		} while(!RC0_bit);
	BTFSS       RC0_bit+0, BitPos(RC0_bit+0) 
	GOTO        L_Task_BTN43
;main.c,53 :: 		}
	GOTO        L_Task_BTN37
;main.c,54 :: 		}
L_end_Task_BTN:
	RETURN      0
; end of _Task_BTN

_Task_LED0:

;main.c,56 :: 		void Task_LED0(void)
;main.c,59 :: 		OS_Bsem_Set(BS_LED0);
	BSF         __OS_Bsems+0, 0 
;main.c,61 :: 		for(;;)
L_Task_LED046:
;main.c,64 :: 		OS_Bsem_Wait(BS_LED0);
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	MOVLW       1
	ANDWF       __OS_Bsems+0, 0 
	MOVWF       R0 
	MOVLW       0
	ANDLW       0
	MOVWF       R1 
	MOVLW       0
	XORWF       R1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Task_LED070
	MOVLW       0
	XORWF       R0, 0 
L__Task_LED070:
	MOVLW       0
	BTFSS       STATUS+0, 2 
	MOVLW       1
	MOVWF       FARG__OS_CheckEvent+0 
	CALL        __OS_CheckEvent+0, 0
	MOVLW       254
	ANDWF       __OS_Bsems+0, 1 
;main.c,66 :: 		LATD.RD0 = ~LATD.RD0;
	BTG         LATD+0, 0 
;main.c,67 :: 		OS_Delay(300);
	MOVLW       44
	MOVWF       FARG__OS_InitDelay_Delay+0 
	MOVLW       1
	MOVWF       FARG__OS_InitDelay_Delay+1 
	MOVLW       0
	MOVWF       FARG__OS_InitDelay_Delay+2 
	MOVWF       FARG__OS_InitDelay_Delay+3 
	CALL        __OS_InitDelay+0, 0
	CALL        __OS_ReturnSave+0, 0
	NOP
;main.c,69 :: 		OS_Bsem_Reset(BS_LED0);
	MOVLW       254
	ANDWF       __OS_Bsems+0, 1 
;main.c,70 :: 		OS_Bsem_Set(BS_LED1);
	BSF         __OS_Bsems+0, 1 
;main.c,72 :: 		}
	GOTO        L_Task_LED046
;main.c,73 :: 		}
L_end_Task_LED0:
	RETURN      0
; end of _Task_LED0

_Task_LED1:

;main.c,75 :: 		void Task_LED1(void)
;main.c,77 :: 		for(;;)
L_Task_LED149:
;main.c,79 :: 		OS_Bsem_Wait(BS_LED1);
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	MOVLW       2
	ANDWF       __OS_Bsems+0, 0 
	MOVWF       R0 
	MOVLW       0
	ANDLW       0
	MOVWF       R1 
	MOVLW       0
	XORWF       R1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Task_LED172
	MOVLW       0
	XORWF       R0, 0 
L__Task_LED172:
	MOVLW       0
	BTFSS       STATUS+0, 2 
	MOVLW       1
	MOVWF       FARG__OS_CheckEvent+0 
	CALL        __OS_CheckEvent+0, 0
	MOVLW       253
	ANDWF       __OS_Bsems+0, 1 
;main.c,81 :: 		LATD.RD1 = ~LATD.RD1;
	BTG         LATD+0, 1 
;main.c,82 :: 		OS_Delay(300);
	MOVLW       44
	MOVWF       FARG__OS_InitDelay_Delay+0 
	MOVLW       1
	MOVWF       FARG__OS_InitDelay_Delay+1 
	MOVLW       0
	MOVWF       FARG__OS_InitDelay_Delay+2 
	MOVWF       FARG__OS_InitDelay_Delay+3 
	CALL        __OS_InitDelay+0, 0
	CALL        __OS_ReturnSave+0, 0
	NOP
;main.c,84 :: 		OS_Bsem_Reset(BS_LED1);
	MOVLW       253
	ANDWF       __OS_Bsems+0, 1 
;main.c,85 :: 		OS_Bsem_Set(BS_LED2);
	BSF         __OS_Bsems+0, 2 
;main.c,86 :: 		}
	GOTO        L_Task_LED149
;main.c,87 :: 		}
L_end_Task_LED1:
	RETURN      0
; end of _Task_LED1

_Task_LED2:

;main.c,89 :: 		void Task_LED2(void)
;main.c,91 :: 		for(;;)
L_Task_LED252:
;main.c,93 :: 		OS_Bsem_Wait(BS_LED2);
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	MOVLW       4
	ANDWF       __OS_Bsems+0, 0 
	MOVWF       R0 
	MOVLW       0
	ANDLW       0
	MOVWF       R1 
	MOVLW       0
	XORWF       R1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Task_LED274
	MOVLW       0
	XORWF       R0, 0 
L__Task_LED274:
	MOVLW       0
	BTFSS       STATUS+0, 2 
	MOVLW       1
	MOVWF       FARG__OS_CheckEvent+0 
	CALL        __OS_CheckEvent+0, 0
	MOVLW       251
	ANDWF       __OS_Bsems+0, 1 
;main.c,95 :: 		LATD.RD2 = ~LATD.RD2;
	BTG         LATD+0, 2 
;main.c,96 :: 		OS_Delay(300);
	MOVLW       44
	MOVWF       FARG__OS_InitDelay_Delay+0 
	MOVLW       1
	MOVWF       FARG__OS_InitDelay_Delay+1 
	MOVLW       0
	MOVWF       FARG__OS_InitDelay_Delay+2 
	MOVWF       FARG__OS_InitDelay_Delay+3 
	CALL        __OS_InitDelay+0, 0
	CALL        __OS_ReturnSave+0, 0
	NOP
;main.c,98 :: 		OS_Bsem_Reset(BS_LED2);
	MOVLW       251
	ANDWF       __OS_Bsems+0, 1 
;main.c,99 :: 		OS_Bsem_Set(BS_LED0);
	BSF         __OS_Bsems+0, 0 
;main.c,100 :: 		}
	GOTO        L_Task_LED252
;main.c,101 :: 		}
L_end_Task_LED2:
	RETURN      0
; end of _Task_LED2
