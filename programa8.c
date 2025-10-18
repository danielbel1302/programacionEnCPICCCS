/**
 * @file toggle_led_every_three.c
 * @brief Toggle LED state every three button presses with software debouncing.
 *
 * This program is designed for the PIC16F628A microcontroller.
 * A push button is connected to RA2 and an LED is connected to RB1.
 * The program counts the number of button presses and toggles the LED
 * every three presses. A simple software debounce is implemented to ensure
 * reliable button press detection.
 *
 * Hardware Setup:
 * ---------------
 * - RA2 ? Push button (active LOW, external pull-up or internal configuration)
 * - RB1 ? LED (active HIGH)
 *
 * Program Logic:
 * --------------
 * 1. Initialize a counter to 0.
 * 2. Detect button press (LOW) and wait 10 ms to debounce.
 * 3. Confirm button release (HIGH) to count as a valid press.
 * 4. When the counter reaches 3:
 *      - Toggle the LED state.
 *      - Reset the counter to 0.
 *
 * Author: Daniel Beltrán
 * Date: 2025-10-17
 */

#include <16f628A.h>
#fuses XT, NOWDT, NOLVP          // External oscillator, Watchdog Timer disabled, Low-Voltage Programming disabled
#use delay(clock=4M)            // 4 MHz clock frequency

#use standard_io(B)
#use standard_io(A)

void main(void)
{
    int cont = 0;  // Counter for valid button presses

    while (1)
    {
        // Check for button press (active LOW)
        if (!input_state(pin_a2))
        {
            delay_ms(10);  // Debounce delay

            // Confirm button release to register a valid press
            if (input_state(pin_a2))
            {
                cont++;
            }
        }

        // Every 3 presses, toggle the LED and reset the counter
        if (cont == 3)
        {
            output_toggle(pin_b1);
            cont = 0;
        }
    }
}

