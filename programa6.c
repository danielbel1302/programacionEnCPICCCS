/**
 * @file switch_button_led.c
 * @brief LED control using a switch and a push button with pull-up resistors.
 *
 * This program is designed for the PIC16F628A microcontroller. 
 * A push button is connected to RB1 and a switch is connected to RA1, both with pull-up resistors.
 * An LED is connected to RA3. 
 *
 * - If the switch (RA1) is open, the LED remains OFF at all times.
 * - If the switch is closed, the LED is controlled by the push button:
 *     - When the button (RB1) is pressed, the LED turns ON.
 *     - When the button is released, the LED turns OFF.
 *
 * Hardware Setup:
 * ---------------
 * - RB1 ? Push button (active LOW with pull-up)
 * - RA1 ? Switch (active LOW with pull-up)
 * - RA3 ? LED (active HIGH)
 *
 * Author: Daniel Beltrán
 * Date: 2025-10-16
 */

#include <16f628A.h>
#fuses XT, NOWDT, NOLVP          // External oscillator, Watchdog Timer disabled, Low-Voltage Programming disabled
#use delay(clock=4M)            // 4 MHz clock frequency

#use standard_io(B) 
#use standard_io(A)

void main(void)
{
    while (1)
    {
        // Check if the switch is closed (active LOW)
        if (!input_state(pin_a1))
        {
            // If the button is pressed, turn ON the LED
            if (!input_state(pin_b1))
            {
                output_high(pin_a3);
            }
            // If the button is released, turn OFF the LED
            else
            {
                output_low(pin_a3);
            }
        }
        // If the switch is open, the LED remains OFF (no action needed)
    }
}

