#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
int main(void) 
{   
    //ENTRADAS 
	DDRB &= ~(1<<0);
	
    PORTB |= (1<<0);
    
	// SAÍDAS
	DDRD |= (1<<3); // Sv_Vd
	DDRD |= (1<<4); // Sv_Am
	DDRD |= (1<<5); // Sv_Vm
	DDRD |= (1<<6); // Pd_Vd
	DDRD |= (1<<7); // Pd_Vm
	
	PORTD &= ~(1<<3); // Sv_Vd
	PORTD &= ~(1<<4); // Sv_Am
	PORTD &= ~(1<<5); // Sv_Vm
	PORTD &= ~(1<<6); // Pd_Vd
	PORTD &= ~(1<<7); // Pd_Vm
	
	int estado = 0;
	int tempo = 0;
	while (1)
    {
		/*if (!( PINB & (1<<0)))
		{
			PORTD |= (1<<3);
			PORTD |= (1<<4);
			PORTD |= (1<<5);
			PORTD |= (1<<6);
			PORTD |= (1<<7);*/
		
			
		if (estado == 0)
		{
			PORTD &= ~(1<<3); // Sv_Vd
			PORTD &= ~(1<<4); // Sv_Am
			PORTD |= (1<<5); // Sv_Vm
			PORTD &= ~(1<<7); // Pd_Vm
			PORTD |= (1<<6); // Pd_Vd
			tempo = 15000;
			estado = 1;
		}
		if (estado ==1)
		{
			--tempo;
			_delay_ms(1);
			if (tempo == 5000)
			{
			PORTD |= (1<<7); // Pd_Vm
			PORTD &= ~(1<<6); // Pd_Vd
			}
			if (tempo == 4000)
			{
			PORTD &= ~(1<<7); // Pd_Vm
			}
			if (tempo == 3000)
			{
			PORTD |= (1<<7); // Pd_Vm
			}
			if (tempo == 2000)
			{
			PORTD &= ~(1<<7); // Pd_Vm
			}
			if (tempo == 1000)
			{
			PORTD |= (1<<7); // Pd_Vm
			}
			if (tempo == 0)
			{
				estado = 2;
			}
		}
		if (estado == 2)
		{
			PORTD &= ~(1<<5); // Sv_Vm
			PORTD |= (1<<3); // Sv_Vd
			PORTD &= ~(1<<6); // Pd_Vd
			PORTD |= (1<<7); // Pd_Vm
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
			PORTD &= ~(1<<3); // Sv_Vd
			PORTD |= (1<<4); // Sv_Am
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



		
		/*	if (!( PINB & (1<<0)))
			{
				estado = 1;
			}
		}
		if (estado ==1)
		{
			PORTD |= (1<<5);
			PORTD |= (1<<6);
			tempo = 5000;
			estado = 2;
		}
		if (estado == 2)
		{
			--tempo;
			_delay_ms(1);
			if (tempo == 0)
			{
				estado = 3;
			}
		}
		if (estado == 3)
		{
			PORTD &= ~(1<<6);
			PORTD |= (1<<7);
			estado = 4;
		}
		if (estado == 4)
		{
			if (!( PINB & (1<<1)))
			{
				estado = 0;
			}
		}
		if ((!( PINB & (1<<1)))&& (estado ==2))
		{
			estado = 0;
		}*/
		
    }
}