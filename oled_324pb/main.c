/*
 * oled_324pb.c
 *
 * Created: 2019/11/4 15:33:08
 * Author : Pluto
 */ 

#include <avr/io.h>
#include "io_hal.h"
#include "oled.h"

int main(void)
{
	Io_Init();
	OLED_Init();			//≥ı ºªØOLED
	OLED_Clear();
	OLED_ShowString(0,0,"abcdefghijklmnop");
	OLED_ShowString(0,2,"qrstuvwxyz ABCDE");
	OLED_ShowString(0,4,"FGHIJKLMNOPQRSTU");
	OLED_ShowString(0,6,"VWXYZ 0123456789");	
    /* Replace with your application code */
    while (1) 
    {
    }
}

