
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
;config.h,25 :: 		TRISC.TRISC2 = 1;
	BSF         TRISC+0, 2 
;config.h,26 :: 		ANSELC.ANSC2 = 1;
	BSF         ANSELC+0, 2 
;config.h,28 :: 		TRISC.TRISC3 = 1;
	BSF         TRISC+0, 3 
;config.h,29 :: 		ANSELC.ANSC3 = 1;
	BSF         ANSELC+0, 3 
;config.h,31 :: 		TRISD = 0;        //PORTD configurado como Sa?da
	CLRF        TRISD+0 
;config.h,32 :: 		PORTD = 0;        //LEDs OFF
	CLRF        PORTD+0 
;config.h,33 :: 		}
L_end_Init_MCU:
	RETURN      0
; end of _Init_MCU

_TickTimerIE:

;config.h,36 :: 		void TickTimerIE(void){
;config.h,37 :: 		T0CON = T0CON_CONST;
	MOVLW       68
	MOVWF       T0CON+0 
;config.h,38 :: 		TMR0L = TMR0_CONST;
	MOVLW       194
	MOVWF       TMR0L+0 
;config.h,39 :: 		INTCON.GIEH = 1;
	BSF         INTCON+0, 7 
;config.h,40 :: 		INTCON.GIEL = 1;
	BSF         INTCON+0, 6 
;config.h,41 :: 		RCON.IPEN = 1;
	BSF         RCON+0, 7 
;config.h,42 :: 		TMR0IE_bit = 1;
	BSF         TMR0IE_bit+0, BitPos(TMR0IE_bit+0) 
;config.h,43 :: 		TMR0IP_bit = 1;
	BSF         TMR0IP_bit+0, BitPos(TMR0IP_bit+0) 
;config.h,44 :: 		T0CON.TMR0ON = 1;
	BSF         T0CON+0, 7 
;config.h,45 :: 		}
L_end_TickTimerIE:
	RETURN      0
; end of _TickTimerIE

_INTERRUPT_HIGH:

;main.c,9 :: 		void INTERRUPT_HIGH() iv 0x0008 ics ICS_AUTO {
;main.c,10 :: 		if (TMR0IF_bit){
	BTFSS       TMR0IF_bit+0, BitPos(TMR0IF_bit+0) 
	GOTO        L_INTERRUPT_HIGH0
;main.c,11 :: 		TMR0L = TMR0_CONST;
	MOVLW       194
	MOVWF       TMR0L+0 
;main.c,12 :: 		TMR0IF_bit = 0;
	BCF         TMR0IF_bit+0, BitPos(TMR0IF_bit+0) 
;main.c,14 :: 		OS_Timer();
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
;main.c,15 :: 		}
L_INTERRUPT_HIGH0:
;main.c,16 :: 		}
L_end_INTERRUPT_HIGH:
L__INTERRUPT_HIGH60:
	RETFIE      1
; end of _INTERRUPT_HIGH

_main:

;main.c,18 :: 		void main() {
;main.c,19 :: 		OSCCON = 0b01100011;
	MOVLW       99
	MOVWF       OSCCON+0 
;main.c,21 :: 		OS_Init();
	CALL        _OS_Init+0, 0
;main.c,22 :: 		Init_MCU();
	CALL        _Init_MCU+0, 0
;main.c,23 :: 		TickTimerIE();
	CALL        _TickTimerIE+0, 0
;main.c,24 :: 		ADC_Init();
	CALL        _ADC_Init+0, 0
;main.c,25 :: 		LCD_Init();
	CALL        _Lcd_Init+0, 0
;main.c,26 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,27 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,30 :: 		OS_Task_Create(0, Task_LED);
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
;main.c,31 :: 		OS_Task_Create(0, Task_ADC1)
	CLRF        FARG__OS_Task_Create_priority+0 
	MOVLW       _Task_ADC1+0
	MOVWF       FARG__OS_Task_Create_TaskAddr+0 
	MOVLW       hi_addr(_Task_ADC1+0)
	MOVWF       FARG__OS_Task_Create_TaskAddr+1 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+2 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+3 
	CALL        __OS_Task_Create+0, 0
;main.c,32 :: 		OS_Task_Create(0, Task_ADC2);;
	CLRF        FARG__OS_Task_Create_priority+0 
	MOVLW       _Task_ADC2+0
	MOVWF       FARG__OS_Task_Create_TaskAddr+0 
	MOVLW       hi_addr(_Task_ADC2+0)
	MOVWF       FARG__OS_Task_Create_TaskAddr+1 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+2 
	MOVLW       0
	MOVWF       FARG__OS_Task_Create_TaskAddr+3 
	CALL        __OS_Task_Create+0, 0
;main.c,33 :: 		OS_Task_Create(0, Task_LCD);
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
;main.c,35 :: 		OS_EI();
	BSF         GIE_bit+0, BitPos(GIE_bit+0) 
	BTFSS       IPEN_bit+0, BitPos(IPEN_bit+0) 
	GOTO        L_main9
	BSF         GIEL_bit+0, BitPos(GIEL_bit+0) 
L_main9:
;main.c,37 :: 		OS_Run();
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
	GOTO        L__main62
	MOVLW       __OS_Tasks+27
	SUBWF       __OS_CurTask+0, 0 
L__main62:
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
	GOTO        L__main56
	BTFSC       __OS_State+0, 7 
	GOTO        L__main56
	GOTO        L_main21
L__main56:
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
L__main55:
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
	GOTO        L__main63
	MOVF        __OS_LastTask+0, 0 
	XORWF       __OS_CurTask+0, 0 
L__main63:
	BTFSC       STATUS+0, 2 
	GOTO        L__main54
	GOTO        L_main13
L__main54:
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
L__main53:
	GOTO        ___main__OS_SCHED_RUN
L_main36:
L_main32:
___main_SCHED_END:
	GOTO        L_main10
;main.c,39 :: 		}
L_end_main:
	GOTO        $+0
; end of _main

_Task_LCD:

;main.c,41 :: 		void Task_LCD(void){
;main.c,44 :: 		for(;;){
L_Task_LCD37:
;main.c,45 :: 		if(OS_Msg_Check(msg_adc1)){
	BTFSS       _msg_adc1+0, 0 
	GOTO        L_Task_LCD40
;main.c,46 :: 		OS_Msg_Accept(msg_adc1, msg);
	MOVF        _msg_adc1+1, 0 
	MOVWF       Task_LCD_msg_L0+0 
	MOVF        _msg_adc1+2, 0 
	MOVWF       Task_LCD_msg_L0+1 
	CLRF        _msg_adc1+0 
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
L_Task_LCD40:
;main.c,49 :: 		if(OS_Msg_Check(msg_adc2)){
	BTFSS       _msg_adc2+0, 0 
	GOTO        L_Task_LCD41
;main.c,50 :: 		OS_Msg_Accept(msg_adc2, msg);
	MOVF        _msg_adc2+1, 0 
	MOVWF       Task_LCD_msg_L0+0 
	MOVF        _msg_adc2+2, 0 
	MOVWF       Task_LCD_msg_L0+1 
	CLRF        _msg_adc2+0 
;main.c,51 :: 		Lcd_Out(2,1,msg);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVF        Task_LCD_msg_L0+0, 0 
	MOVWF       FARG_Lcd_Out_text+0 
	MOVF        Task_LCD_msg_L0+1, 0 
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,52 :: 		}
L_Task_LCD41:
;main.c,53 :: 		OS_Delay(20);
	MOVLW       20
	MOVWF       FARG__OS_InitDelay_Delay+0 
	MOVLW       0
	MOVWF       FARG__OS_InitDelay_Delay+1 
	MOVWF       FARG__OS_InitDelay_Delay+2 
	MOVWF       FARG__OS_InitDelay_Delay+3 
	CALL        __OS_InitDelay+0, 0
	CALL        __OS_ReturnSave+0, 0
	NOP
;main.c,54 :: 		}
	GOTO        L_Task_LCD37
;main.c,55 :: 		}
L_end_Task_LCD:
	RETURN      0
; end of _Task_LCD

_Task_ADC1:

;main.c,57 :: 		void Task_ADC1(void){
;main.c,62 :: 		OS_Msg_Create(msg_adc1);
	CLRF        _msg_adc1+0 
	MOVLW       0
	MOVWF       _msg_adc1+1 
	MOVLW       0
	MOVWF       _msg_adc1+2 
;main.c,64 :: 		for(;;){
L_Task_ADC142:
;main.c,65 :: 		leitura_adc = ADC_Read(14);
	MOVLW       14
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
;main.c,66 :: 		WordToStr(leitura_adc, str);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       Task_ADC1_str_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(Task_ADC1_str_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;main.c,68 :: 		OS_Msg_Send(msg_adc1, str);
	BTFSS       _msg_adc1+0, 0 
	GOTO        L_Task_ADC145
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	MOVLW       1
	ANDWF       _msg_adc1+0, 0 
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
L_Task_ADC145:
	MOVLW       1
	MOVWF       _msg_adc1+0 
	MOVLW       Task_ADC1_str_L0+0
	MOVWF       _msg_adc1+1 
	MOVLW       hi_addr(Task_ADC1_str_L0+0)
	MOVWF       _msg_adc1+2 
;main.c,70 :: 		OS_Cond_Wait(!OS_Msg_Check(msg_adc1));
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	MOVLW       1
	ANDWF       _msg_adc1+0, 0 
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
;main.c,72 :: 		OS_Delay(50);
	MOVLW       50
	MOVWF       FARG__OS_InitDelay_Delay+0 
	MOVLW       0
	MOVWF       FARG__OS_InitDelay_Delay+1 
	MOVWF       FARG__OS_InitDelay_Delay+2 
	MOVWF       FARG__OS_InitDelay_Delay+3 
	CALL        __OS_InitDelay+0, 0
	CALL        __OS_ReturnSave+0, 0
	NOP
;main.c,73 :: 		}
	GOTO        L_Task_ADC142
;main.c,74 :: 		}
L_end_Task_ADC1:
	RETURN      0
; end of _Task_ADC1

_Task_ADC2:

;main.c,76 :: 		void Task_ADC2(void){
;main.c,81 :: 		OS_Msg_Create(msg_adc2);
	CLRF        _msg_adc2+0 
	MOVLW       0
	MOVWF       _msg_adc2+1 
	MOVLW       0
	MOVWF       _msg_adc2+2 
;main.c,83 :: 		for(;;){
L_Task_ADC246:
;main.c,84 :: 		leitura_adc = ADC_Read(15);
	MOVLW       15
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
;main.c,85 :: 		WordToStr(leitura_adc, str);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       Task_ADC2_str_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(Task_ADC2_str_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;main.c,87 :: 		OS_Msg_Send(msg_adc2, str);
	BTFSS       _msg_adc2+0, 0 
	GOTO        L_Task_ADC249
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	MOVLW       1
	ANDWF       _msg_adc2+0, 0 
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
L_Task_ADC249:
	MOVLW       1
	MOVWF       _msg_adc2+0 
	MOVLW       Task_ADC2_str_L0+0
	MOVWF       _msg_adc2+1 
	MOVLW       hi_addr(Task_ADC2_str_L0+0)
	MOVWF       _msg_adc2+2 
;main.c,89 :: 		OS_Cond_Wait(!OS_Msg_Check(msg_adc2));
	CALL        __OS_EnterWaitMode+0, 0
	NOP
	MOVLW       1
	ANDWF       _msg_adc2+0, 0 
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
;main.c,91 :: 		OS_Delay(50);
	MOVLW       50
	MOVWF       FARG__OS_InitDelay_Delay+0 
	MOVLW       0
	MOVWF       FARG__OS_InitDelay_Delay+1 
	MOVWF       FARG__OS_InitDelay_Delay+2 
	MOVWF       FARG__OS_InitDelay_Delay+3 
	CALL        __OS_InitDelay+0, 0
	CALL        __OS_ReturnSave+0, 0
	NOP
;main.c,92 :: 		}
	GOTO        L_Task_ADC246
;main.c,93 :: 		}
L_end_Task_ADC2:
	RETURN      0
; end of _Task_ADC2

_Task_LED:

;main.c,95 :: 		void Task_LED(void){
;main.c,96 :: 		for(;;)
L_Task_LED50:
;main.c,98 :: 		LATD.RD0 = ~LATD.RD0;
	BTG         LATD+0, 0 
;main.c,99 :: 		OS_Delay(300);
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
;main.c,100 :: 		}
	GOTO        L_Task_LED50
;main.c,101 :: 		}
L_end_Task_LED:
	RETURN      0
; end of _Task_LED
