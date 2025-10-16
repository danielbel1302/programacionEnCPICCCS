/********************************************************************************
 * Project:     PIC I/O Control – Push Button with Pull-up
 * File:        main.c
 * Description: A push button with a pull-up resistor is connected to RB0. 
 *              When the button is pressed (logic low), the LED connected to RB2 
 *              turns ON. When the button is released (logic high), the LED 
 *              turns OFF.
 * 
 * Target MCU:      PIC16F628A
 * Clock:           4 MHz (XT Crystal)
 * Compiler:        MPLAB XC8
 * 
 * Author:          Daniel Beltrán
 * Date:            2025-10-14
 ********************************************************************************/

#include <16F628A.h>            // Include the specific MCU header file
#fuses XT, NOWDT, NOLVP         // XT oscillator, Watchdog Timer disabled, Low Voltage Programming disabled
#use delay(clock=4M)           // Define system clock frequency (4 MHz)

#use standard_io(B)            // Use standard I/O mode for PORTB

void main(void)
{
    // Infinite loop to continuously monitor the button state
    while (TRUE)
    {
        // If button is pressed (RB0 goes LOW due to pull-up)
        if (!input_state(PIN_B0))
        {
            output_high(PIN_B2);  // Turn ON LED connected to RB2
        }
        else
        {
            output_low(PIN_B2);   // Turn OFF LED connected to RB2
        }
    }
}

