#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "avr/delay.h"
#include "DIO.h"
#include "Macros.h"
#include "Std_Types.h"



#define UART_BAUDRATE 9600

void USART_Init (void);					           // Function to initialize the USART
void USART_sendByte (u8 data);			           // Function to send data byte
u8 USART_receiveByte (void);			           // Function to receive data byte


#endif /* MCAL_ADC_ADC_H_ */
