/********************************************************************************
 * Project:     PIC I/O Control – Dual Push Button and LED Logic
 * File:        main.c
 * Description: Two push buttons with pull-up resistors are connected to RB1 and 
 *              RA2. When RB1 is pressed (active low), the LED on RA0 turns ON. 
 *              When the button is released, the LED turns OFF.
 * 
 *              When RA2 is pressed (active low), the LED on RB7 turns OFF. 
 *              When the button is released, the LED turns ON again.
 * 
 * Target MCU:      PIC16F628A
 * Clock:           4 MHz (XT Crystal)
 * Compiler:        MPLAB XC8
 * 
 * Author:          Daniel Beltrán
 * Date:            2025-10-14
 ********************************************************************************/

#include <16F628A.h>             // Include the specific MCU header file
#fuses XT, NOWDT, NOLVP          // XT oscillator, Watchdog Timer disabled, Low Voltage Programming disabled
#use delay(clock=4M)            // Define system clock frequency (4 MHz)

#use standard_io(B)             // Use standard I/O mode for PORTB
#use standard_io(A)             // Use standard I/O mode for PORTA

void main(void)
{
    // Initialize RB7 LED to ON state
    output_high(PIN_B7);

    // Infinite loop to continuously monitor both push buttons
    while (TRUE)
    {
        // Button on RB1 controls LED on RA0 (active low)
        if (!input_state(PIN_B1))
        {
            output_high(PIN_A0);  // Turn ON LED on RA0
        }
        else
        {
            output_low(PIN_A0);   // Turn OFF LED on RA0
        }

        // Button on RA2 controls LED on RB7 (active low)
        if (!input_state(PIN_A2))
        {
            output_low(PIN_B7);   // Turn OFF LED on RB7
        }
        else
        {
            output_high(PIN_B7);  // Turn ON LED on RB7
        }
    }
}

