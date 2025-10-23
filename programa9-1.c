/**
 * @file button_switch_led_control.c
 * @brief LED control using a push button and a switch with conditional counting.
 *
 * This program is designed for the **PIC16F628A** microcontroller.
 * It controls a LED connected to **RB0** based on:
 *  - A push button on **RA0**
 *  - A switch on **RB6**
 *
 * Behavior:
 *  - The switch on RB6 must be **closed** for the button presses to be counted.
 *  - When the button (RA0) is pressed **3 times**, the LED turns **ON**.
 *  - When the button is pressed **5 more times** (total of 8 presses), the LED turns **OFF**.
 *  - After turning off, the counter resets to 0.
 *  - Software debouncing (20 ms) is implemented to ensure reliable button readings.
 *
 * @hardware
 *  - **MCU:** PIC16F628A  
 *  - **RA0:** Push button (active low, with pull-up resistor)  
 *  - **RB6:** Switch (active low, must be closed to enable counting)  
 *  - **RB0:** LED output  
 *
 * @note Counting only occurs when the switch is in the closed position.
 * @version 1.0
 * @date 2025-10-23
 * @author
 * Daniel Beltrán
 */

#include <16f628A.h>
#fuses XT, NOWDT, NOLVP
#use delay(clock=4M)

#use standard_io(B)
#use standard_io(A)

void main()
{
   int cont = 0;  // Counter for valid button presses

   while(1)
   {
      // Only count button presses when the switch (RB6) is closed
      if(!input_state(pin_b6))
      {
         // Detect button press on RA0 (active low)
         if(!input_state(pin_a0))
         {
            delay_ms(20); // Software debounce
            if(input_state(pin_a0)) // Confirm release
            {
               cont++; // Increment counter
            }
         }
      }

      // After 8 total presses ? Turn LED OFF and reset counter
      if(cont > 7)
      {
         output_low(pin_b0);
         cont = 0;
      }
      // After 3 presses ? Turn LED ON
      else if(cont > 2)
      {
         output_high(pin_b0);
      }
   }
}

