/**
 * @file toggle_led_button.c
 * @brief Toggle LED state using a push button with internal pull-up resistor.
 *
 * This program is written for the PIC16F628A microcontroller.
 * A push button is connected to RB3 with an internal pull-up resistor enabled,
 * and an LED is connected to RB1. Each time the button is pressed, the LED
 * changes its state: if it was ON, it turns OFF; if it was OFF, it turns ON.
 *
 * Hardware Setup:
 * ---------------
 * - RB3 ? Push button (active LOW, internal pull-up enabled)
 * - RB1 ? LED (active HIGH)
 *
 * Program Logic:
 * --------------
 * 1. Enable internal pull-ups on PORTB.
 * 2. Continuously check the state of RB3.
 * 3. When the button is pressed (LOW), a short debounce delay is applied.
 * 4. On button release (transition to HIGH), the LED state toggles.
 *
 * Author: Daniel Beltrán
 * Date: 2025-10-16
 */

#include <16f628A.h>
#fuses XT, NOWDT, NOLVP          // External oscillator, Watchdog Timer disabled, Low-Voltage Programming disabled
#use delay(clock=4M)            // 4 MHz clock frequency

#use standard_io(B)

void main(void)
{
    // Enable internal pull-up resistors on PORTB
    port_b_pullups(true);

    while (1)
    {
        // Check if the button is pressed (active LOW)
        if (!input(pin_b3))
        {
            delay_ms(10);  // Debounce delay

            // When the button is released, toggle LED state
            if (input(pin_b3))
            {
                output_toggle(pin_b1);
            }
        }
    }
}

