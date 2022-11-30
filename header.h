/********************************************************************************
* header.h: Innehåller definitioner och deklarationer för implementering av
*           det inbyggda systemet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Klockfrekvens (behövs för fördröjningsrutiner): */
#define F_CPU 16000000UL /* 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>     /* Innehåller information om I/O-register såsom PORTB. */
#include <util/delay.h> /* Innehåller fördröjningsrutiner såsom _delay_us. */ 

/* Makrodefinitioner: */
#define LED1 PORTB0 /* Lysdiod 1 på pin 8 (PORTB0). */
#define POT1 PORTC0 /* Potentiometer 1 på analog pin A0 (PORTC0). */

/********************************************************************************
* set: Ettställer bit i angivet register utan att påverka övriga bitar.
*
*      - reg: Registret som ska skrivas till.
*      - bit: Biten som ska ettställas.
********************************************************************************/
#define set(reg, bit) reg |= (1 << bit)

/********************************************************************************
* clr: Nollställer bit i angivet register utan att påverka övriga bitar.
*
*      - reg: Registret som ska skrivas till.
*      - bit: Biten som ska nollställas.
********************************************************************************/
#define clr(reg, bit) reg &= ~(1 << bit)

/********************************************************************************
* read: Läser av angiven pin och returnerar ifall denna är hög eller låg.
*
*       - reg: Registret som ska läsas av.
*       - bit: Den bit som ska kontrolleras.
********************************************************************************/
#define read(reg, bit) (reg & (1 << bit))

/********************************************************************************
* delay_us: Genererar fördröjning mätt i mikrosekunder.
*
*           - delay_time_us: Pekare till fördröjningstiden i mikrosekunder.
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
* adc_read: Läser av analog insignal från angiven pin och returnerar motsvarande
*           digitala värde mellan 0 - 1023.
*
*           - pin: Analog pin A0 - A5 som ska läsas av.
********************************************************************************/
uint16_t adc_read(const uint8_t pin);

/********************************************************************************
* adc_get_pwm_values: Läser av angiven analog pin och beräknar sedan on- och
*                     off-tid för PWM-generering via angiven periodtid.
*                     Beräknade värden sparas på angivna adresser och indikerar
*                     tiden som lysdioden ska vara tänd respektive släckt.
*
*                     - pin        : Den analoga pin A0 - A5 som ska läsas av.
*                     - period_us  : Periodtid för PWM i mikrosekunder.
*                     - on_time_us : Pekare till variabel där on-tiden ska
*                                    lagras i mikrosekunder.
*                     - off_time_us: Pekare till variabel där off-tiden ska
*                                    lagras i mikrosekunder.
********************************************************************************/
void adc_get_pwm_values(const uint8_t pin,
                        const uint16_t period_us,
                        uint16_t* on_time_us,
                        uint16_t* off_time_us);

#endif /* HEADER_H_ */