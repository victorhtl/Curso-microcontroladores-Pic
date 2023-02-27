void __interrupt(high_priority) INT0_interrupt(void){ 
    
    // INT0
    if(INTCONbits.INT0IF){
        PORTDbits.RD7 = 1;
        __delay_ms(5000);
        PORTDbits.RD7 = 0;
        INTCONbits.INT0IF = 0;  
    }
    
    // INT1
    if(INTCON3bits.INT1IF){
        lcdClean();
        lcdComando(1, 'I');
        __delay_ms(1000);
        lcdComando(1, 'N');
        __delay_ms(1000);
        lcdComando(1, 'T');
        __delay_ms(1000);
        lcdComando(1, '1');
        __delay_ms(1000);
        lcdClean();
        INTCON3bits.INT1IF = 0;
    }
}