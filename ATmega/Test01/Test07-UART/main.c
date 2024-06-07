/*
 * Test07-UART.c
 *
 * Created: 2024-06-07 오전 10:36:10
 * Author : user
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <avr/delay.h>
#define F_CPU 16000000L

void initUART0() // 9600N81
{
	UBRR0H = 0;		// UBRR0 --> UART0		
	UBRR0L = 207;	// Baud rate : 9600;
	
	UCSR0A |= (1 << U2X0); // 0000 0010b 2배속 설정
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);		// Rx/Tx Enable
	UCSR0C |= 0x06;			// Data bit : 8 x11x		0000 0110b NB1
							// stop bit : 1 0xxx
}

void uPutc (char c) // 1 char transmit
{
	/* while(1)
	{
		if(UCSR0A & (1 << UDRE0) == 1) break;	// wait until data empty bit test
	}
	UDR0 = c; // send */  // beginer
	
	while(!(UCSR0A & (1 << UDRE0)));	// wait until data empty bit test
	UDR0 = c; // send
}

void uPuts(char *str)
{
	while (*str) uPutc(*str++);
	
	/* while(1)
	{
		if(*str == 0) break;
		uPutc(*str); // *str : value 
		str++;		// str ++ : pointer 연산
	}*/
}
unsigned char buf[1024];

void bprintf()
{
	uPuts(buf);
}
int main(void)
{
    /* Replace with your application code */
    initUART0();
	// char a = '0';
	int i = 0;
	uPuts("안녕하세요....^^..\r\n");
	while (1) 
    {
		// uPutc(a++);
		sprintf(buf, "ATmega128 터미널 출력 테스트...#%d\r\n", i++); bprintf();
		_delay_ms(1000);
		// if(a > '9') a = '0';
    }
}

