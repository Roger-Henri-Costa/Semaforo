#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define VAI_CARRO 0x88
#define VAI_PED 0x60
#define ATENCAO_CARRO 0x90
#define PISCA_PED_VM 0xA0
#define PISCA_PED 0x20


int main(void) 
{   
    //ENTRADAS 
	DDRB &= ~0x01;
	
    PORTB |= 0x01;
    
	// SAÍDAS
	DDRD |= 0xF8;
	
	PORTD &= ~0xF8;
	
	int estado = 0;
	int tempo = 0;
	while (1)
    {
		if (estado == 0)
		{
			PORTD = VAI_PED;
			tempo = 15000;
			estado = 1;
		}
		if (estado ==1)
		{
			--tempo;
			_delay_ms(1);
			if (tempo == 5000)
			{
			PORTD = PISCA_PED_VM;
			}
			if (tempo == 4000)
			{
			PORTD = PISCA_PED;
			}
			if (tempo == 3000)
			{
			PORTD = PISCA_PED_VM;
			}
			if (tempo == 2000)
			{
			PORTD = PISCA_PED;
			}
			if (tempo == 1000)
			{
			PORTD = PISCA_PED_VM;
			}
			if (tempo == 0)
			{
				estado = 2;
			}
		}
		if (estado == 2)
		{
			PORTD = VAI_CARRO;
			tempo = 42000;
			estado = 3;
		}
		if (estado ==3)
		{
			--tempo;
			_delay_ms(1);
			if (tempo == 0)
			{
				estado = 4;
			}
		}
		if (estado == 4)
		{
			PORTD = ATENCAO_CARRO;
			tempo = 3000;
			estado = 5;
		}
		if (estado == 5)
		{
			--tempo;
			_delay_ms(1);
			if (tempo == 0)
			{
				estado = 0;
			}
		}
		if ((!( PINB & (1<<0)))&& (estado ==3))
		{
			if (tempo > 10000)
			{
				estado = 4;
			}
		}
    }
}