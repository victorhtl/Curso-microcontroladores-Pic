/*
 ************************************************************************************************
 *
 *  OSA cooperative RTOS for microcontrollers PIC, AVR and STM8
 *
 *  OSA is distributed under BSD license (see license.txt)
 *
 *  URL:            http://wiki.pic24.ru/doku.php/en/osa/ref/intro
 *
 *----------------------------------------------------------------------------------------------
 *
 *  File:           osa_include.c
 *
 *  Programmer:     Timofeev Victor
 *                  osa@pic24.ru, testerplus@mail.ru
 *
 *  Description:    Include the proc. specific file.
 *                  This file directly included in osa.c
 *
 *  History:        19.09.2010 -    File updated
 *
 ************************************************************************************************
 */


//------------------------------------------------------------------------------
#if defined(__OSA_PIC18_HTPICC__)               // HT-PICC18
//------------------------------------------------------------------------------

    #include <port\pic18\osa_pic18_htpicc.c>

//------------------------------------------------------------------------------
#elif defined(__OSA_PIC18_MPLABC__)             // MPLAB C18
//------------------------------------------------------------------------------

    #include <port\pic18\osa_pic18_mplabc.c>          

//------------------------------------------------------------------------------
#elif defined(__OSA_PIC18_MPLABC_EXT__)         // MPLAB C18 for extended mode 
//------------------------------------------------------------------------------

    #include <port\pic18\osa_pic18_mplabc_ext.c>       

//------------------------------------------------------------------------------
#elif defined(__OSA_PIC24_MPLABC__)             // MPLAB C30
//------------------------------------------------------------------------------

    #include <port\pic24\osa_pic24_mplabc.c>          

//------------------------------------------------------------------------------
#elif defined(__OSA_PIC16_CCS__)                // CCS-PICC (for PIC16 only)
//------------------------------------------------------------------------------

    #include <port\pic16\osa_pic16_ccs.c>          

//------------------------------------------------------------------------------
#elif defined(__OSA_PIC18_CCS__)                // CCS-PICC (for PIC18 only)
//------------------------------------------------------------------------------

    #include <port\pic18\osa_pic18_ccs.c>          

//------------------------------------------------------------------------------
#elif defined(__OSA_PIC12_HTPICC__)             // HT_PICC for 12-bit PICs
//------------------------------------------------------------------------------

    #include <port\pic12\osa_pic12_htpicc.c>         

//------------------------------------------------------------------------------
#elif defined(__OSA_PIC16_HTPICC__)             // HT_PICC
//------------------------------------------------------------------------------

    #include <port\pic16\osa_pic16_htpicc.c>         

//------------------------------------------------------------------------------
#elif defined(__OSA_PIC16E_HTPICC_PRO__)        // HT_PICC_PRO for pic16f1xxx
//------------------------------------------------------------------------------

    #include <port\pic16\osa_pic16e_htpicc_pro.c>     

//------------------------------------------------------------------------------
#elif defined(__OSA_PIC16_MIKROC__)             // mikroC for PIC16
//------------------------------------------------------------------------------

    #include <port\pic16\osa_pic16_mikroc.c>       

//------------------------------------------------------------------------------
#elif defined(__OSA_PIC18_MIKROC__)             // mikroC for PIC18
//------------------------------------------------------------------------------

    #include "pic18\osa_pic18_mikroc.c"       

//------------------------------------------------------------------------------
#elif defined(__OSA_AVR_WINAVR__)               // WinAVR for Atmel AVR
//------------------------------------------------------------------------------

    #include <port\avr\osa_avr_winavr.c>        

//------------------------------------------------------------------------------
#elif defined(__OSA_AVR_IAR__)                  // IAR for Atmel AVR
//------------------------------------------------------------------------------

    #include <port\avr\osa_avr_iar.c>        

//------------------------------------------------------------------------------
#elif defined(__OSA_AVR_CODEVISION__)           // CodeVision for Atmel AVR
//------------------------------------------------------------------------------

    #include <port\avr\osa_avr_codevision.c>

//------------------------------------------------------------------------------
#elif defined(__OSA_STM8_IAR__)                 // IAR for ST STM8
//------------------------------------------------------------------------------

    #include <port\stm8\osa_stm8_iar.c>      

//------------------------------------------------------------------------------
#elif defined(__OSA_STM8_COSMIC__)              // Cosmic for ST STM8
//------------------------------------------------------------------------------

    #include <port\stm8\osa_stm8_cosmic.c>      

//------------------------------------------------------------------------------
#elif defined(__OSA_STM8_RAISONANCE__)          // Raisonance for ST STM8
//------------------------------------------------------------------------------

    #include <port\stm8\osa_stm8_raisonance.c>

//------------------------------------------------------------------------------
#else
//------------------------------------------------------------------------------

    #error "OSA error #1: Unknown compiler!"
            /* See manual section "Appendix/Error codes" for more information*/

//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------

//******************************************************************************
//  END OF FILE osa_include.c
//******************************************************************************

