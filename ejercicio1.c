/********************************************************************************
 * Project:     PIC I/O Control – RB3 Pin High
 * File:        main.c
 * Description: Upon microcontroller startup, pin RB3 is configured as an output 
 *              and set to a logic high level continuously.
 * 
 * Target MCU:  PIC16F628A
 * Clock:       4 MHz (XT Crystal)
 * Compiler:    MPLAB XC8
 * 
 * Author:      Cesar Daniel Beltran
 * Date:        2025-10-14
 ********************************************************************************/

#include <16F628A.h>          // Include the specific MCU header file
#fuses XT, NOWDT, NOLVP       // XT oscillator, Watchdog Timer disabled, Low Voltage Programming disabled
#use delay(clock=4M)          // Define system clock frequency (4 MHz)

#use standard_io(B)           // Use standard I/O mode for PORTB

void main(void)
{
    // Infinite loop to keep the pin RB3 set to logic high
    while (TRUE)
    {
        output_high(PIN_B3);  // Set RB3 output to logic high
    }
}
