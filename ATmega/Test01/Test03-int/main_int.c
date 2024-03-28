/*
 * Test03-int.c
 *
 * Created: 2024-03-27 오후 12:25:48
 * Author : SYSTEM-00
 */ 
// < > system header 
#define F_CPU 16000000L
#define __delay_t 500
#define OPMOOD_MAX 3
#define STATE_MAX 3
#define SUR_MAX 3
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t digit[] ={0x3F, 0x06, 0x5B,0x4F,0x66,0x6D, 0x7D,0x27, 0x7F,0x67, 0x77, 0x7C, 0x58, 0x5E, 0x79,0x71,0x40,0x00};
char arr[5]; // // 세그먼트 이미지 정보를 담을 안전 영역
volatile int opmode=0, state=0, sur=0;

void LED_ON()
{
	PORTA |= 0x07; // PortA의 0, 1, 2,번째 비트를 HIGH로 출력
	_delay_ms(3);
}
void LED_OFF()
{
	PORTA &=~0x07;
	_delay_ms(3);
}

void seg(int sel, uint8_t c)
{   PORTC |= 0x0F;
	PORTC &= ~(1<< (3-sel));
	PORTD = c;
	//_delay_ms(2);
}

void FND_4(char *inf) // segment Image 배열
{ int i;
	for (i=0; i<4; i++)
	{
		seg(i,*(inf+i));
		_delay_ms(3);
	}
}

char* Disp(unsigned long num) // 10진수 정수 ==> 16진수 문자열 변환 : 56506 ==> 0xDCBA  / 65535 ==> 0xFFFF
{					//						==> 4digit 16진수 segment 출력
	int n1 = num % 16; // A :
	int n2 = (num/16)%16; // B(11)
	int n3 = (num/256)%16; // C(12)
	int n4 = (num/4096); //D(13)
	if(!(num/4096))
	{
		n4 = 17;
		if (!(num/256))
		{
			n3=17;
			if(!(num/16))
			{
				n2=17;
			}
		}
	}
	arr[0]= digit[n1];
	arr[1]= digit[n2];
	arr[2]= digit[n3];
	arr[3]= digit[n4];
	
	FND_4(arr);
	return arr;
}

int main(void)
{
    /* Replace with your application code */
	// 7-segment 사용 : 4 Module - C type
	// Pin assign : PCx - Segment img, PDx -module sel
	// Interrupt 사용 : INT4 ~ INT6 (Ext Int)
	//	  Pin assign :		PE4~PE6
	DDRD = 0xFF; // 세그먼트 제어 핀 8개를 출력으로 설정
	DDRC = 0x0F; // 자릿수 선택 핀 4개를 출력으로 설정
    DDRA = 0x07;
	// 인터럽트 설정
	EIMSK = 0x70; // 0111 0000b
	EICRB = 0x2A; // 0010 1010b
	SREG |= 0x80; // status Register - 인터럽트 허용
	sei();		  // set interrupt - 인터럽트 시작
	
	volatile unsigned long t=0;
	while (1) 
    {  
		switch(opmode) 
		{
			
			case 0 : t=0; //reset & wait
					break; 
			case 1 : t++; // counter start
				if (t==100)
				{
					LED_ON();
					_delay_ms(500);
				}
				else LED_OFF();
		
			case 2 : break; // count stop
			default : break;
		}

		switch (state)
		{
		case 0 :  
		case 1 :  if (t>0) t--; break;
		
		case 2 : break;
		default : break;	
		}

		switch (sur)
		{
			case 0 : break;
			default : break;
		}
		 
		 Disp(t);
    }
}

ISR(INT4_vect) // INT4 인터럽트 처리 루틴 : SW1
{
	opmode++;
	if(opmode>=OPMOOD_MAX) opmode=0;
}
ISR(INT5_vect)  // INT5 인터럽트 처리 루틴 : SW2
{
	state++;
	if(state>=STATE_MAX) state=0;
}
ISR(INT6_vect)  // INT6 인터럽트 처리 루틴 : SW3
{
	sur++;
	if(sur>=SUR_MAX) sur=0;
}



