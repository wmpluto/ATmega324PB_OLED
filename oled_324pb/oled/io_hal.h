#ifndef _IO_HAL_H
#define _IO_HAL_H

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>

#define OLED_CS_Clr()  PORTB &= ~_BV(4)
#define OLED_CS_Set()  PORTB |= _BV(4)

#define OLED_RST_Clr() PORTA &= ~_BV(3)
#define OLED_RST_Set() PORTA |= _BV(3)

#define OLED_DC_Clr() PORTA &= ~_BV(2)
#define OLED_DC_Set() PORTA |= _BV(2)

inline void SPI_Send(uint8_t dat){
	SPDR0 = dat;//dummy write to kick off SCLk
	loop_until_bit_is_set(SPSR0, SPIF);	 		 
}

inline void Io_Init(void) {
    /* SPI Init */
	PORTB |=  _BV(4); DDRB |= _BV(4); // PB4: SS
	
	PORTB &= ~_BV(7); DDRB |= _BV(7); // PB7: SCK
	
	PORTB &= ~_BV(5); DDRB |= _BV(5); // PB5: MOSI
	
	DDRB |= _BV(6); // PB6: MISO
	
	// SPI Master device, LSB first, Mode 3, 8MHz/16 = 500kHz
	SPCR0 = ((1<<SPE) | (1<<MSTR) | (1<<SPR0));
	// No interrupts or double speed...
	SPSR0  = (0<<SPI2X);
		
    /* Control IO Init */
	PORTA |= _BV(2);
	DDRA |= _BV(2); // PA2: DC
	PORTA |= _BV(3);
	DDRA |= _BV(3); // PA3: RST
		
}
#endif