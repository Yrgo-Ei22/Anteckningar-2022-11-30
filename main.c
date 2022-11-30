/********************************************************************************
* main.c: Implementering av ett system inneh�llande PWM-generering f�r styrning
*         av en lysdiod ansluten till pin 8 (PORTB0) via avl�sning av analoga 
*         insignaler fr�n en potentiometer ansluten till analog pin A0 (PORTC0).
********************************************************************************/
#include "header.h"

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar samt AD-omvandlare.
*
*        1. Vi s�tter lysdioden till utport via ettst�llning av motsvarande bit
*           i datariktningsregistret DDRB (Data Direction Register B).
*
*        2. Vi initierar AD-omvandlarens analoga kretsar via en testomvandling.
*           Eftersom vi inte �r intresserade av returv�rdet tar vi inte emot
*           returv�rdet och typomvandlar returtypen till void.
********************************************************************************/
void setup(void)
{
   set(DDRB, LED1);
   (void)adc_read(POT1);
   return;
}

/********************************************************************************
* main: Initierar I/O-portar samt AD-omvandlaren vid start. Lysdioden styrs
*       sedan kontinuerligt med PWM via avl�sning av potentiometern.
*       F�r PWM-generering anv�nds en periodtid p� 1000 mikrosekunder
********************************************************************************/
int main(void)
{
   uint16_t pwm_on_us;
   uint16_t pwm_off_us;

   setup();

   while (1)
   {
      adc_get_pwm_values(POT1, 1000, &pwm_on_us, &pwm_off_us); 

      set(PORTB, LED1);      
      delay_us(&pwm_on_us);  
      clr(PORTB, LED1);      
      delay_us(&pwm_off_us); 
   }

   return 0;
}

