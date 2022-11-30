# Anteckningar 2022-11-30
Implementering av AD-omvandling för PWM-generering på mikrodator ATmega328. I bifogat program styrs ljusstyrkan 
på en lysdiod ansluten till pin 8 (PORTB0) via en potentiometer ansluten till analog pin A0 (PORTC0). 

Filen "header.h" innehåller diverse definitioner och deklarationer för implementering av det inbyggda systemet.

Filen "adc.c" innehåller funktioner för AD-omvandling samt beräkning av värden för PWM-generering.

I filen "main.c" initieras I/O-portar samt AD-omvandlaren vid start.
Sedan läsas potentiometern av för att kontrollera ljusstyrkan på lysdioden via PWM-generering.

Filen "2-bit ADC.asc" utgör en 2-bitars AD-omvandlare skapad och simulerad i LTspice.
