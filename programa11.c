/**
 * @file led_blink_switch_control.c
 * @brief LED blinking with variable period controlled by a switch.
 *
 * This program is designed for the **PIC16F628A** microcontroller.
 * It controls the blink rate of an LED connected to **RB4** based on
 * the state of a switch connected to **RA0**.
 *
 * Behavior:
 *  - If the switch (RA0) is **closed** (logic low), the LED blinks
 *    with a period of **1 second** (1000 ms).
 *  - If the switch is **open** (logic high), the LED blinks
 *    with a period of **500 ms**.
 *  - The program runs continuously in an infinite loop.
 *
 * @hardware
 *  - **MCU:** PIC16F628A  
 *  - **RA0:** Switch input (active low)  
 *  - **RB4:** LED output  
 *
 * @timing
 *  - Clock frequency: 4 MHz  
 *  - Blink period: 1 s (switch closed) / 0.5 s (switch open)
 *
 * @compiler
 *  - Compatible with **CCS C Compiler** or **MPLAB XC8**
 *
 * @note The switch uses a pull-up resistor configuration.
 *
 * @author
 * Daniel Beltrán
 * @version 1.0
 * @date 2025-10-23
 */

#include <16f628A.h>
#fuses XT, NOWDT, NOLVP
#use delay(clock=4M)

#use standard_io(B)
#use standard_io(A)

void main()
{
   while(1)
   {
      // Check switch state on RA0
      if(!input_state(pin_a0))
      {
         // Switch closed ? Blink every 1 second
         output_toggle(pin_b4);
         delay_ms(1000);
      }
      else
      {
         // Switch open ? Blink every 500 ms
         output_toggle(pin_b4);
         delay_ms(500);
      }
   }
}

