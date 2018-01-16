/*****************************************************************************
  FileName:        main.c
  Processor:       PIC24HJ128GP502
  Compiler:        XC16 ver 1.30
  IDE :            MPLABX-IDE
  Created by:      http://strefapic.blogspot.com
 ******************************************************************************/
/*wyswietlacz DOGM204-A (4x20) firmy Electronic Assembly*/
#include "xc.h" /* wykrywa rodzaj procka i includuje odpowiedni plik naglowkowy "p24HJ128GP502.h"*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> /*dyrektywy uint8_t itp*/

#include "ustaw_zegar.h" /*tutaj m.in ustawione FCY*/
#include <libpic30.h> // biblioteka dajaca dostep do delay-i.
#include "dogm204.h"

char napis[] = "Kocham Monik""\x01"; /* "\x01" to zapis kodu ASCII dla zdefiniowanej
literki e z ogonkiem. Dla wlasnych znaków mamy zarezerwowane kody ASCII od 0 do 7,
przyczym aby uzywac podanego sposobu wstawiania w?asnych znaków w stringa, nie mozemy 
uzywac kodu ASCI 0, czyli zamiast 8 znaków korzystamy z 7 (od 1 do 7)*/
int main(void) {
 
    ustaw_zegar();/*odpalamy zegar na ok 40MHz*/
    	
	PMD1bits.AD1MD=1;       //wylaczamy ADC
    AD1PCFGL = 0x1E3F;      //wylaczenie linii analogowych(wszystkie linie cyfrowe)
                    			
	WlaczLCD();             //inicjalizacja wyswietlacza LCD
	WpiszSwojeZnaki();      //wpisz do CGRAM-u definicje znaku e z ogonkiem
    UstawKursorLCD(1,4);
    WyswietlLCD(napis);    //wyswietl napis z tablicy napis1[]
    
    while(1)
      {
          /*Glowna Petla Programu*/
   
      }
	
    return 0;
}
