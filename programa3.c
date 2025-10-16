/********************************************************************************
 * Project:     PIC I/O Control – Port B Output Pattern
 * File:        main.c
 * Description: Upon microcontroller startup, PORTB is configured as output and 
 *              the binary pattern 0b01100101 is continuously sent to the port. 
 *              This sets specific logic levels on each RB pin simultaneously.
 * 
 * Binary pattern:  0b01100101
 * Pin states:      RB7=0, RB6=1, RB5=1, RB4=0, RB3=0, RB2=1, RB1=0, RB0=1
 * 
 * Target MCU:      PIC16F628A
 * Clock:           4 MHz (XT Crystal)
 * Compiler:        MPLAB XC8
 * 
 * Author:          Daniel Beltrán
 * Date:            2025-10-14
 ********************************************************************************/

#include <16F628A.h>           // Include the specific MCU header file
#fuses XT, NOWDT, NOLVP        // XT oscillator, Watchdog Timer disabled, Low Voltage Programming disabled
#use delay(clock=4M)           // Define system clock frequency (4 MHz)

#use standard_io(B)            // Use standard I/O mode for PORTB

void main(void)
{
    // Infinite loop to maintain the defined output pattern on PORTB
    while (TRUE)
    {
        output_b(0b01100101);  // Output binary pattern to all PORTB pins
    }
}

