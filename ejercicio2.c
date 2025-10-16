/********************************************************************************
 * Project:     PIC I/O Control – Multiple Pin States
 * File:        main.c
 * Description: Upon microcontroller startup, pins RB2, RB6, and RA1 are 
 *              configured as outputs. RB6 and RA1 are set to a logic high level, 
 *              while RB2 is set to a logic low level continuously.
 * 
 * Target MCU:  PIC16F628A
 * Clock:       4 MHz (XT Crystal)
 * Compiler:    MPLAB XC8
 * 
 * Author:      Daniel Beltrán
 * Date:        2025-10-14
 ********************************************************************************/

#include <16F628A.h>          // Include the specific MCU header file
#fuses XT, NOWDT, NOLVP       // XT oscillator, Watchdog Timer disabled, Low Voltage Programming disabled
#use delay(clock=4M)          // Define system clock frequency (4 MHz)

#use standard_io(B)           // Use standard I/O mode for PORTB
#use standard_io(A)           // Use standard I/O mode for PORTA

void main(void)
{
    // Infinite loop to maintain defined output states
    while (TRUE)
    {
        output_high(PIN_B6);  // Set RB6 output to logic high
        output_high(PIN_A1);  // Set RA1 output to logic high
        output_low(PIN_B2);   // Set RB2 output to logic low
    }
}

