﻿/*
 * CFile1.c
 *
 * Created: 2024-03-28 오후 12:42:54
 *  Author: SYSTEM-00
 */ 
#include "myHeader.h"
// #define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

uint8_t digit[] ={0x3F, 0x06, 0x5B,0x4F,0x66,0x6D, 0x7D,0x27, 0x7F,0x67, 0x77, 0x7C, 0x58, 0x5E, 0x79,0x71,0x40,0x00};
char arr[5]; // // 세그먼트 이미지 정보를 담을 안전 영역
char* PA = &PORTD, *PB = &PORTC;

void SegPort(char* p1, char* p2)
{
	PA = p1; PB = p2;
}

void seg(int sel, uint8_t c)
{   *PB |= 0x0F;
	*PB &= ~(1<< (3-sel)); 
	*PA = c; //숫자 데이터 출력
	_delay_ms(1); // 0.01초 간격으로 전환
}
int sm =4;
void FND_4(char *inf) // segment Image 배열
{
	for (int i=0; i<sm; i++)
	{
		seg(i,*(inf+i));
		_delay_ms(5);
	}
}

char* Disp(unsigned long num) // 10진수 정수 ==> 16진수 문자열 변환 : 56506 ==> 0xDCBA  / 65535 ==> 0xFFFF
{					// 10진수 ==> 16진수 segment Image 배열
	int n1 = num % 16; // A :  
	int n2 = (num/16)%16; // B(11)
	int n3 = (num/256)%16; // C(12)
	int n4 = (num/4096); //D(13)
	/*if(!(num/4096))
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
	}*/
	arr[0]= digit[n1];
	arr[1]= digit[n2];
	arr[2]= digit[n3];
	arr[3]= digit[n4];
	sm = (num >4095) ? 4 : (num >255) ? 3 :(num >15) ? 2 : 1;
  FND_4(arr);
	
}
