/*Al iniciar el microcontrolador, la pata RB3 del mismo se configura como 
salida y muestra un "1 lógico".*/

#include <16f628A.h>
#fuses XT,NOWDT,NOLVP
#use delay(clock=4M)

#use standard_io(B)

void main()
{
   while(1)
   {
      output_high(pin_b3);
   }
}
