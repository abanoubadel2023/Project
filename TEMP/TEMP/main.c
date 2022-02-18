#include <avr/io.h>
#include <avr/interrupt.h>

#include "LCD.h"
#include "DIO.h"
#include "ADC.h"
#include "UART.h"
#include "Std_Types.h"
#include "Macros.h"



int main ()
{
	
	u16 adc_value;
	u8 Temperature;
	u16 ADC_Reading;
	u16 mv_Value;
	u16 LDR_Value;
	ADC_Init();
	USART_Init();
	LCD_Init();
	
	SET_BIT(SREG,7);	                           //Enable I-Bit

	while (1)
	{

		

		adc_value = ADC_readChannel(1);		        // read adc value at PA0
		Temperature = adc_value / 2.01;   	        // finding the temperature
		Go_To_Row_Col(0,1);
		Display_Str("The Temp is:  ");   			//Display temperature
		Go_To_Row_Col(1,5);
		Integer_TO_String(Temperature);
		Display_Str(" C     ");

		if(Temperature > 28)
		{
			USART_sendByte('H');	                // Alarm On
		}
		else if(Temperature > 21)
		{
			USART_sendByte('F');	                // Fan On
		}
		else
		{
			USART_sendByte('X');
		}

		// LDR Code
		
		ADC_Reading = ADC_readChannel(0);
		mv_Value=(ADC_Reading * 5000)/256;
		LDR_Value = mv_Value * 3.8;

		if(LDR_Value < 400)
		{
			USART_sendByte('L');	             // Led On
		}
		else
		{
			USART_sendByte('X');
		}
	}
	return 0;
}



