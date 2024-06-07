/*
 * Test06-ADC.c
 *
 * Created: 2024-05-31 오후 4:36:00
 * Author : user
 */ 

#include "myHeader.h" // 가급전 분리된 파일 내에 상수 넣지말기
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define __delay_t 500
unsigned long cnt = 0, tcnt = 0;

void initADC(int ch)
{
	ADMUX |= (1 << REFS0);	// AVCC를 기준 전압 0100 0000
	ADCSRA |= 0x07;			// Pre-scaler 분주비 설정
	ADCSRA |= (1 << ADEN);	// ADC 활성화
	ADCSRA |= (1 << ADFR);	// free-running Mode 설정
	
	ADMUX |= ((ADMUX & 0xE0) | ch);	// 채널 선택 ch : channel
	ADCSRA |= (1 << ADSC);					// 변환 시작
}

int main(void)
{
   DDRD = 0xFF; // 세그먼트 제어 핀 8개를 출력으로 설정
   DDRC = 0x0F; // 자릿수 선택 핀 4개를 출력으로 설정
   SegPort(&PORTD, &PORTC);
   SegType(1);
   
   initADC(1); // 1: ch number
    while (1) 
    {
		while(!(ADCSRA & (1 << ADIF)));
		cnt = ADC;
		SegDisp(cnt);
    }
	return 0;
}

