
_Init_MCU:

;config.h,16 :: 		void Init_MCU(void){
;config.h,17 :: 		ANSELA = 0;
	CLRF        ANSELA+0 
;config.h,18 :: 		ANSELB = 0;
	CLRF        ANSELB+0 
;config.h,19 :: 		ANSELC = 0;
	CLRF        ANSELC+0 
;config.h,20 :: 		ANSELD = 0;
	CLRF        ANSELD+0 
;config.h,21 :: 		ANSELE = 0;
	CLRF        ANSELE+0 
;config.h,23 :: 		TRISD = 0;        //PORTD configurado como Sa?da
	CLRF        TRISD+0 
;config.h,24 :: 		PORTD = 0;        //LEDs OFF
	CLRF        PORTD+0 
;config.h,25 :: 		}
L_end_Init_MCU:
	RETURN      0
; end of _Init_MCU

_TickTimerIE:

;config.h,28 :: 		void TickTimerIE(void){
;config.h,29 :: 		T0CON = T0CON_CONST;
	MOVLW       68
	MOVWF       T0CON+0 
;config.h,30 :: 		TMR0L = TMR0_CONST;
	MOVLW       194
	MOVWF       TMR0L+0 
;config.h,31 :: 		INTCON.GIEH = 1;
	BSF         INTCON+0, 7 
;config.h,32 :: 		INTCON.GIEL = 1;
	BSF         INTCON+0, 6 
;config.h,33 :: 		RCON.IPEN = 1;
	BSF         RCON+0, 7 
;config.h,34 :: 		TMR0IE_bit = 1;
	BSF         TMR0IE_bit+0, BitPos(TMR0IE_bit+0) 
;config.h,35 :: 		TMR0IP_bit = 1;
	BSF         TMR0IP_bit+0, BitPos(TMR0IP_bit+0) 
;config.h,36 :: 		T0CON.TMR0ON = 1;
	BSF         T0CON+0, 7 
;config.h,37 :: 		}
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
;main.c,11 :: 		}
L_INTERRUPT_HIGH0:
;main.c,12 :: 		}
L_end_INTERRUPT_HIGH:
L__INTERRUPT_HIGH51:
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
;main.c,25 :: 		OS_EI();                         // Enable interrupts
	BSF         GIE_bit+0, BitPos(GIE_bit+0) 
	BTFSS       IPEN_bit+0, BitPos(IPEN_bit+0) 
	GOTO        L_main7
	BSF         GIEL_bit+0, BitPos(GIEL_bit+0) 
L_main7:
;main.c,28 :: 		OS_Run();                       //Executa o scheduler
L_main8:
	BCF         __OS_Flags+0, 4 
	BSF         __OS_Flags+0, 3 
	MOVLW       8
	MOVWF       __OS_Best_Priority+0 
	MOVF        __OS_LastTask+0, 0 
	MOVWF       __OS_CurTask+0 
	MOVF        __OS_LastTask+1, 0 
	MOVWF       __OS_CurTask+1 
L_main11:
	MOVLW       hi_addr(__OS_Tasks+18)
	SUBWF       __OS_CurTask+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main53
	MOVLW       __OS_Tasks+18
	SUBWF       __OS_CurTask+0, 0 
L__main53:
	BTFSS       STATUS+0, 0 
	GOTO        L_main14
	MOVLW       __OS_Tasks+0
	MOVWF       __OS_CurTask+0 
	MOVLW       hi_addr(__OS_Tasks+0)
	MOVWF       __OS_CurTask+1 
	GOTO        L_main15
L_main14:
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
L_main15:
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
L_main16:
	MOVF        POSTINC0+0, 0 
	MOVWF       POSTINC1+0 
	DECF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_main16
	BTFSS       __OS_State+0, 6 
	GOTO        L__main47
	BTFSC       __OS_State+0, 7 
	GOTO        L__main47
	GOTO        L_main19
L__main47:
	GOTO        ___main__OS_SCHED_CONTINUE
L_main19:
	MOVF        __OS_State+0, 0 
	MOVWF       R0 
	MOVLW       7
	ANDWF       R0, 1 
	MOVF        R0, 0 
	MOVWF       __OS_Temp+0 
	MOVF        __OS_Best_Priority+0, 0 
	SUBWF       __OS_Temp+0, 0 
	BTFSS       STATUS+0, 0 
	GOTO        L_main20
	GOTO        ___main__OS_SCHED_CONTINUE
L_main20:
	BTFSC       __OS_State+0, 3 
	GOTO        L_main21
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
	GOTO        L_main22
	GOTO        ___main_SCHED_END
L_main22:
L_main21:
	BTFSS       __OS_State+0, 4 
	GOTO        L_main25
	BTFSC       __OS_State+0, 5 
	GOTO        L_main25
L__main46:
	GOTO        ___main__OS_SCHED_CONTINUE
L_main25:
	BTFSS       __OS_State+0, 3 
	GOTO        L_main26
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
	GOTO        L_main27
	GOTO        L_main12
L_main27:
L_main26:
___main__OS_SCHED_CONTINUE:
	MOVF        __OS_CurTask+1, 0 
	XORWF       __OS_LastTask+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main54
	MOVF        __OS_LastTask+0, 0 
	XORWF       __OS_CurTask+0, 0 
L__main54:
	BTFSC       STATUS+0, 2 
	GOTO        L__main45
	GOTO        L_main11
L__main45:
L_main12:
	BTFSS       __OS_Flags+0, 4 
	GOTO        L_main30
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
L_main31:
	MOVF        POSTINC0+0, 0 
	MOVWF       POSTINC1+0 
	DECF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_main31
	BTFSS       __OS_State+0, 6 
	GOTO        L_main34
	BTFSC       __OS_State+0, 7 
	GOTO        L_main34
L__main44:
	GOTO        ___main__OS_SCHED_RUN
L_main34:
L_main30:
___main_SCHED_END:
	GOTO        L_main8
;main.c,30 :: 		}
L_end_main:
	GOTO        $+0
; end of _main

_Task_LED0:

;main.c,32 :: 		void Task_LED0(void){
;main.c,33 :: 		for(;;)
L_Task_LED035:
;main.c,35 :: 		LATD.RD0 = ~LATD.RD0;
	BTG         LATD+0, 0 
;main.c,36 :: 		OS_Delay(300);
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
;main.c,37 :: 		}
	GOTO        L_Task_LED035
;main.c,38 :: 		}
L_end_Task_LED0:
	RETURN      0
; end of _Task_LED0

_Task_LED1:

;main.c,40 :: 		void Task_LED1(void){
;main.c,41 :: 		for(;;)
L_Task_LED138:
;main.c,43 :: 		LATD.RD1 = ~LATD.RD1;
	BTG         LATD+0, 1 
;main.c,44 :: 		OS_Delay(300);
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
;main.c,45 :: 		}
	GOTO        L_Task_LED138
;main.c,46 :: 		}
L_end_Task_LED1:
	RETURN      0
; end of _Task_LED1

_Task_LED2:

;main.c,48 :: 		void Task_LED2(void){
;main.c,49 :: 		for(;;)
L_Task_LED241:
;main.c,51 :: 		LATD.RD2 = ~LATD.RD2;
	BTG         LATD+0, 2 
;main.c,52 :: 		OS_Delay(300);
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
;main.c,53 :: 		}
	GOTO        L_Task_LED241
;main.c,54 :: 		}
L_end_Task_LED2:
	RETURN      0
; end of _Task_LED2
