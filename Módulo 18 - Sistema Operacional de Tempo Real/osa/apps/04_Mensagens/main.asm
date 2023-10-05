
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
;config.h,23 :: 		TRISC.TRISC2 = 1;
	BSF         TRISC+0, 2 
;config.h,24 :: 		ANSELC.ANSC2 = 1;
	BSF         ANSELC+0, 2 
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

;main.c,8 :: 		void INTERRUPT_HIGH() iv 0x0008 ics ICS_AUTO {
;main.c,9 :: 		if (TMR0IF_bit){
	BTFSS       TMR0IF_bit+0, BitPos(TMR0IF_bit+0) 
	GOTO        L_INTERRUPT_HIGH0
;main.c,10 :: 		TMR0L = TMR0_CONST;
	MOVLW       194
	MOVWF       TMR0L+0 
;main.c,11 :: 		TMR0IF_bit = 0;
	BCF         TMR0IF_bit+0, BitPos(TMR0IF_bit+0) 
;main.c,13 :: 		OS_Timer();
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
;main.c,14 :: 		}
L_INTERRUPT_HIGH0:
;main.c,15 :: 		}
L_end_INTERRUPT_HIGH:
L__INTERRUPT_HIGH53:
	RETFIE      1
; end of _INTERRUPT_HIGH

_main:

;main.c,17 :: 		void main() {
;main.c,18 :: 		OSCCON = 0b01100011;
	MOVLW       99
	MOVWF       OSCCON+0 
;main.c,20 :: 		OS_Init();
	CALL        _OS_Init+0, 0
;main.c,21 :: 		Init_MCU();
	CALL        _Init_MCU+0, 0
;main.c,22 :: 		TickTimerIE();
	CALL        _TickTimerIE+0, 0
;main.c,23 :: 		ADC_Init();
	CALL        _ADC_Init+0, 0
;main.c,24 :: 		LCD_Init();
	CALL        _Lcd_Init+0, 0
;main.c,25 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,26 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,29 :: 		OS_Task_Create(0, Task_LED);
	CLRF        FARG__OS_Task_Create_priority+0 
	MOVLW       _Task_LED+0
	MOVWF       FARG__OS_Task_Create_TaskAddr+0 
	MOVLW       hi_addr(_Task_LED+0)
	MOVWF       FARG__OS_Task_Create_TaskAddr+1 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+2 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+3 
	CALL        __OS_Task_Create+0, 0
;main.c,30 :: 		OS_Task_Create(0, Task_ADC);
	CLRF        FARG__OS_Task_Create_priority+0 
	MOVLW       _Task_ADC+0
	MOVWF       FARG__OS_Task_Create_TaskAddr+0 
	MOVLW       hi_addr(_Task_ADC+0)
	MOVWF       FARG__OS_Task_Create_TaskAddr+1 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+2 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+3 
	CALL        __OS_Task_Create+0, 0
;main.c,31 :: 		OS_Task_Create(0, Task_LCD);
	CLRF        FARG__OS_Task_Create_priority+0 
	MOVLW       _Task_LCD+0
	MOVWF       FARG__OS_Task_Create_TaskAddr+0 
	MOVLW       hi_addr(_Task_LCD+0)
	MOVWF       FARG__OS_Task_Create_TaskAddr+1 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+2 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+3 
	CALL        __OS_Task_Create+0, 0
;main.c,33 :: 		OS_EI();
	BSF         GIE_bit+0, BitPos(GIE_bit+0) 
	BTFSS       IPEN_bit+0, BitPos(IPEN_bit+0) 
	GOTO        L_main7
	BSF         GIEL_bit+0, BitPos(GIEL_bit+0) 
L_main7:
;main.c,35 :: 		OS_Run();
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
	GOTO        L__main55
	MOVLW       __OS_Tasks+18
	SUBWF       __OS_CurTask+0, 0 
L__main55:
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
	GOTO        L__main49
	BTFSC       __OS_State+0, 7 
	GOTO        L__main49
	GOTO        L_main19
L__main49:
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
L__main48:
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
	GOTO        L__main56
	MOVF        __OS_LastTask+0, 0 
	XORWF       __OS_CurTask+0, 0 
L__main56:
	BTFSC       STATUS+0, 2 
	GOTO        L__main47
	GOTO        L_main11
L__main47:
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
L__main46:
	GOTO        ___main__OS_SCHED_RUN
L_main34:
L_main30:
___main_SCHED_END:
	GOTO        L_main8
;main.c,37 :: 		}
L_end_main:
	GOTO        $+0
; end of _main

_Task_LCD:

;main.c,39 :: 		void Task_LCD(void){
;main.c,44 :: 		for(;;){
L_Task_LCD35:
;main.c,45 :: 		if(OS_Msg_Check(msg_adc)){
	BTFSS       _msg_adc+0, 0 
	GOTO        L_Task_LCD38
;main.c,46 :: 		OS_Msg_Accept(msg_adc, msg);
	MOVF        _msg_adc+1, 0 
	MOVWF       Task_LCD_msg_L0+0 
	MOVF        _msg_adc+2, 0 
	MOVWF       Task_LCD_msg_L0+1 
	CLRF        _msg_adc+0 
;main.c,47 :: 		Lcd_Out(1,1,msg);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVF        Task_LCD_msg_L0+0, 0 
	MOVWF       FARG_Lcd_Out_text+0 
	MOVF        Task_LCD_msg_L0+1, 0 
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,48 :: 		}
L_Task_LCD38:
;main.c,49 :: 		OS_Delay(20);
	MOVLW       20
	MOVWF       FARG__OS_InitDelay_Delay+0 
	MOVLW       0
	MOVWF       FARG__OS_InitDelay_Delay+1 
	MOVWF       FARG__OS_InitDelay_Delay+2 
	MOVWF       FARG__OS_InitDelay_Delay+3 
	CALL        __OS_InitDelay+0, 0
	CALL        __OS_ReturnSave+0, 0
	NOP
;main.c,50 :: 		}
	GOTO        L_Task_LCD35
;main.c,51 :: 		}
L_end_Task_LCD:
	RETURN      0
; end of _Task_LCD

_Task_ADC:

;main.c,53 :: 		void Task_ADC(void){
;main.c,58 :: 		OS_Msg_Create(msg_adc);
	CLRF        _msg_adc+0 
	MOVLW       0
	MOVWF       _msg_adc+1 
	MOVLW       0
	MOVWF       _msg_adc+2 
;main.c,59 :: 		for(;;){
L_Task_ADC39:
;main.c,60 :: 		leitura_adc = ADC_Read(14);
	MOVLW       14
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
;main.c,61 :: 		WordToStr(leitura_adc, str);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       Task_ADC_str_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(Task_ADC_str_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;main.c,63 :: 		OS_Msg_Send(msg_adc, str);
	BTFSS       _msg_adc+0, 0 
	GOTO        L_Task_ADC42
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	MOVLW       1
	ANDWF       _msg_adc+0, 0 
	MOVWF       FARG__OS_CheckEvent+0 
	MOVF        FARG__OS_CheckEvent+0, 1 
	MOVLW       1
	BTFSS       STATUS+0, 2 
	MOVLW       0
	MOVWF       FARG__OS_CheckEvent+0 
	MOVF        FARG__OS_CheckEvent+0, 0 
	XORLW       0
	MOVLW       0
	BTFSS       STATUS+0, 2 
	MOVLW       1
	MOVWF       FARG__OS_CheckEvent+0 
	CALL        __OS_CheckEvent+0, 0
L_Task_ADC42:
	MOVLW       1
	MOVWF       _msg_adc+0 
	MOVLW       Task_ADC_str_L0+0
	MOVWF       _msg_adc+1 
	MOVLW       hi_addr(Task_ADC_str_L0+0)
	MOVWF       _msg_adc+2 
;main.c,65 :: 		OS_Cond_Wait(!OS_Msg_Check(msg_adc));
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	MOVLW       1
	ANDWF       _msg_adc+0, 0 
	MOVWF       FARG__OS_CheckEvent+0 
	MOVF        FARG__OS_CheckEvent+0, 1 
	MOVLW       1
	BTFSS       STATUS+0, 2 
	MOVLW       0
	MOVWF       FARG__OS_CheckEvent+0 
	MOVF        FARG__OS_CheckEvent+0, 0 
	XORLW       0
	MOVLW       0
	BTFSS       STATUS+0, 2 
	MOVLW       1
	MOVWF       FARG__OS_CheckEvent+0 
	CALL        __OS_CheckEvent+0, 0
;main.c,67 :: 		OS_Delay(50);
	MOVLW       50
	MOVWF       FARG__OS_InitDelay_Delay+0 
	MOVLW       0
	MOVWF       FARG__OS_InitDelay_Delay+1 
	MOVWF       FARG__OS_InitDelay_Delay+2 
	MOVWF       FARG__OS_InitDelay_Delay+3 
	CALL        __OS_InitDelay+0, 0
	CALL        __OS_ReturnSave+0, 0
	NOP
;main.c,68 :: 		}
	GOTO        L_Task_ADC39
;main.c,69 :: 		}
L_end_Task_ADC:
	RETURN      0
; end of _Task_ADC

_Task_LED:

;main.c,71 :: 		void Task_LED(void){
;main.c,72 :: 		for(;;)
L_Task_LED43:
;main.c,74 :: 		LATD.RD0 = ~LATD.RD0;
	BTG         LATD+0, 0 
;main.c,75 :: 		OS_Delay(300);
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
;main.c,76 :: 		}
	GOTO        L_Task_LED43
;main.c,77 :: 		}
L_end_Task_LED:
	RETURN      0
; end of _Task_LED
