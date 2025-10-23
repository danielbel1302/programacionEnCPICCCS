/**
 * @file led_blink_400ms.c
 * @brief Simple LED blinking program with a 400 ms period.
 *
 * This program is designed for the **PIC16F628A** microcontroller.
 * It toggles an LED connected to pin **RB4** continuously, creating
 * an ON/OFF blinking effect with a total period of 400 milliseconds.
 *
 * Behavior:
 *  - The LED turns ON for 200 ms and OFF for 200 ms (toggle every 400 ms).
 *  - The program runs indefinitely in an infinite loop.
 *
 * @hardware
 *  - **MCU:** PIC16F628A  
 *  - **RB4:** LED output pin  
 *
 * @timing
 *  - Clock frequency: 4 MHz  
 *  - LED toggle interval: 400 ms (period)
 *
 * @compiler
 *  - Compatible with **CCS C Compiler** or **MPLAB XC8**
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

void main()
{
   while(1)
   {
      output_toggle(pin_b4);  // Toggle LED state (ON ? OFF)
      delay_ms(400);          // Wait 400 ms before next toggle
   }
}

