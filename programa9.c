/**
 * @file button_led_toggle.c
 * @brief Control a LED using two buttons with counters and debouncing.
 *
 * This program is designed for a PIC16F628A microcontroller.
 * Two push buttons are connected to pins RB0 and RB1 (with pull-up resistors),
 * and a LED is connected to RB7.
 *
 * Behavior:
 *  - Each time the button on RB0 is pressed 4 times, the LED turns ON.
 *  - Once the LED is ON, pressing the button on RB1 3 times turns it OFF.
 *  - The counters reset appropriately to ensure correct sequence operation.
 *  - Software debouncing (20 ms delay) is applied to both buttons.
 *
 * @hardware
 *  - MCU: PIC16F628A
 *  - RB0: Button to turn ON the LED (4 presses)
 *  - RB1: Button to turn OFF the LED (3 presses)
 *  - RB7: LED output
 *
 * @author
 * Daniel Beltrán
 *
 * @version 1.0
 * @date 2025-10-23
 */

#include <16f628A.h>
#fuses XT, NOWDT, NOLVP
#use delay(clock=4M)

#use standard_io(B)

void main()
{
   int cont1 = 0;  // Counter for RB0 button presses
   int cont2 = 0;  // Counter for RB1 button presses

   while(1)
   {
      // === Button RB0: Turn LED ON after 4 presses ===
      if(!input_state(pin_b0)) // Detect button press (active low)
      {
         delay_ms(20); // Software debounce
         if(input_state(pin_b0)) // Confirm button release
         {
            cont1++;    // Increment counter for RB0
            cont2 = 0;  // Reset RB1 counter
         }
      }

      if(cont1 == 4)
      {
         output_high(pin_b7); // Turn ON LED
         cont1 = 0;           // Reset counter
      }

      // === Button RB1: Turn LED OFF after 3 presses ===
      if(!input_state(pin_b1)) // Detect button press (active low)
      {
         delay_ms(20); // Software debounce
         if(input_state(pin_b1)) // Confirm button release
         {
            cont2++;    // Increment counter for RB1
            cont1 = 0;  // Reset RB0 counter
         }
      }

      if(cont2 == 3)
      {
         output_low(pin_b7); // Turn OFF LED
         cont2 = 0;          // Reset counter
      }
   }
}



