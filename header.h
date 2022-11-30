/********************************************************************************
* header.h: Inneh�ller definitioner och deklarationer f�r implementering av
*           det inbyggda systemet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Klockfrekvens (beh�vs f�r f�rdr�jningsrutiner): */
#define F_CPU 16000000UL /* 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>     /* Inneh�ller information om I/O-register s�som PORTB. */
#include <util/delay.h> /* Inneh�ller f�rdr�jningsrutiner s�som _delay_us. */ 

/* Makrodefinitioner: */
#define LED1 PORTB0 /* Lysdiod 1 p� pin 8 (PORTB0). */
#define POT1 PORTC0 /* Potentiometer 1 p� analog pin A0 (PORTC0). */

/********************************************************************************
* set: Ettst�ller bit i angivet register utan att p�verka �vriga bitar.
*
*      - reg: Registret som ska skrivas till.
*      - bit: Biten som ska ettst�llas.
********************************************************************************/
#define set(reg, bit) reg |= (1 << bit)

/********************************************************************************
* clr: Nollst�ller bit i angivet register utan att p�verka �vriga bitar.
*
*      - reg: Registret som ska skrivas till.
*      - bit: Biten som ska nollst�llas.
********************************************************************************/
#define clr(reg, bit) reg &= ~(1 << bit)

/********************************************************************************
* read: L�ser av angiven pin och returnerar ifall denna �r h�g eller l�g.
*
*       - reg: Registret som ska l�sas av.
*       - bit: Den bit som ska kontrolleras.
********************************************************************************/
#define read(reg, bit) (reg & (1 << bit))

/********************************************************************************
* delay_us: Genererar f�rdr�jning m�tt i mikrosekunder.
*
*           - delay_time_us: Pekare till f�rdr�jningstiden i mikrosekunder.
********************************************************************************/
#define delay_us(delay_time_us) ({ \
   for (uint16_t i = 0; i < *delay_time_us; ++i) { \
      _delay_us(1); \
   } \
})

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar samt AD-omvandlare.
********************************************************************************/
void setup(void);

/********************************************************************************
* adc_read: L�ser av analog insignal fr�n angiven pin och returnerar motsvarande
*           digitala v�rde mellan 0 - 1023.
*
*           - pin: Analog pin A0 - A5 som ska l�sas av.
********************************************************************************/
uint16_t adc_read(const uint8_t pin);

/********************************************************************************
* adc_get_pwm_values: L�ser av angiven analog pin och ber�knar sedan on- och
*                     off-tid f�r PWM-generering via angiven periodtid.
*                     Ber�knade v�rden sparas p� angivna adresser och indikerar
*                     tiden som lysdioden ska vara t�nd respektive sl�ckt.
*
*                     - pin        : Den analoga pin A0 - A5 som ska l�sas av.
*                     - period_us  : Periodtid f�r PWM i mikrosekunder.
*                     - on_time_us : Pekare till variabel d�r on-tiden ska
*                                    lagras i mikrosekunder.
*                     - off_time_us: Pekare till variabel d�r off-tiden ska
*                                    lagras i mikrosekunder.
********************************************************************************/
void adc_get_pwm_values(const uint8_t pin,
                        const uint16_t period_us,
                        uint16_t* on_time_us,
                        uint16_t* off_time_us);

#endif /* HEADER_H_ */