/*
 * LCD.c
 *
 * Created: 20/02/2017 15:44:29
 * Author : Anggara Wijaya
 */ 

//#define F_CPU 8000000UL

#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "lcd.h"

int i=0;
char buff_i[6];

int main(void)
{
	DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB4)|(1<<PB5)|(1<<PB6)|(1<<PB7); //DATA port 4 bit
	lcd_init(LCD_DISP_ON);					//inisialisasi
	lcd_clrscr();							//bersihkan layar
	lcd_gotoxy(0,0);
	lcd_puts("===== TEST =====");			//tulis baris 1 dan geser ke bawah
	lcd_gotoxy(0,1);
	lcd_puts("Liquid Crystal");				//tulis baris 2
	
    while (1) 
    {
		itoa(i,buff_i,10);
		lcd_clrscr();
		lcd_gotoxy(0,0);
		lcd_puts("===== TEST =====");			//tulis baris 1 dan geser ke bawah
		lcd_gotoxy(0,1);
		lcd_puts(buff_i);			//tulis baris 2
		i++;
		_delay_ms(100);
    }
}

