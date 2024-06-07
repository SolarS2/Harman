/*
 * Test04-Timer.c
 *
 * Created: 2024-03-28 오전 11:31:41
 * Author : SYSTEM-00
 */ 

#include "myHeader.h" // 가급전 분리된 파일 내에 상수 넣지말기
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define OPMOOD_MAX 3
#define STATE_MAX 5
#define SUR_MAX 2

#define __delay_t 500
unsigned long cnt = 0, tcnt = 0; 
volatile int opmode=0, state=0, sur=0;
unsigned long t=0;


void LED_ON()
{
	PORTA |= 0x07; // PortA의 0, 1, 2,번째 비트를 HIGH로 출력
	_delay_ms(5);
	PORTA =~0x07;
	_delay_ms(5);
}
int main(void)
{
    /* Replace with your application code */
    DDRD = 0xFF; // 세그먼트 제어 핀 8개를 출력으로 설정
    DDRC = 0x0F; // 자릿수 선택 핀 4개를 출력으로 설정
	DDRA = 0x07;
	SegPort(&PORTD, &PORTC);
	//shift_time();
	TIMSK |= 0x01; // 0000 0001b - Timer 0 TCNT overflow interrupt
	//TIMSK |= 0x04; // 0000 0100b - Timer 1 TCNT overflow interrupt
	//TIMSK |= 0x40; // 0100 0000b - Timer 2 TCNT overflow interrupt
	EIMSK = 0x70; // 0111 0000b Timer 3TCNT overFlow interrupt
	TCCR0 = 0x04; // Timer0 분주비 (Pre-Scaler) 64
	//TCCR1B = 0x04;  // Timer1 분주비 (Pre-Scaler) 64
	//TCCR2 = 0x04;  // Timer2 분주비 (Pre-Scaler) 64
	EICRB = 0x2A; // 0010 1010b

	
	SREG |= 0x80;
	sei(); // interrupt 시작

	while (1) 
    {   
		switch(opmode)
		{   
			case 0 :  cnt=0; break;
			case 1 :   break; // 대기 상태 or 비동작 상태
			default :  break;
		}
		switch (state)
		{   
			case 0 : cnt=0; break;
			case 1 :  cnt++; break; // counter start
			case 2 : break;  // count stop
			case 3 : cnt--; break; // counter restart
			case 4 : cnt=0; // reset & wait 
			default : break;
		}

		/*switch (sur)
		{ 
			case 0 : break;
			case 1 : break;
			default : break;
		} */
		       Disp(cnt);
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

ISR(TIMER0_OVF_vect)
{
	 tcnt++;
	if (tcnt>=1000)
	{
		cnt ++; tcnt = 0;
	}
}


/*ISR(TIMER1_OVF_vect)
{
	tcnt++;
	//if (tcnt>=1000)
	{
		cnt ++; tcnt = 0;
	}
} */


/*ISR(TIMER2_OVF_vect)
{
	tcnt++;
	if( tcnt>=100) //8bit timer 사용시
	{
		cnt++; tcnt = 0;
	}
} */

