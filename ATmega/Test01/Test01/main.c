/*
 * Test01.c
 *
 * Created: 2024-03-20 오전 11:42:05
 * Author : SYSTEM-00
 */ 
#define F_CPU 16000000L // board에 대한 clk 정보 

#include <avr/io.h>
#include <avr/delay.h>
#include <util/delay.h>

const int _delay_T =500;

void TogglePinA(int n, uint32_t dl) // n : n번째 비트, dl : delay in m-sec
{
	char b = 1 << n;
	PORTA |= b; // PortA(출력 레지스터)의 n번째 비트를 HIGH로 출력
	_delay_ms(500);
	PORTA &= ~b; // PortA(출력 레지스터)의 n번째 비트를 LOW로 출력
	_delay_ms(500);

}
int main(void)
{
	/* Replace with your application code */
	/* DDRA |= 0x01; // PortA의 0번째 비트를 출력용으로 사용, 나머지는 입력
	DDRA |= 0x02; // PortA의 1번째 비트를 출력용으로 사용, 나머지는 입력
	DDRA |= 0x04; // PortA의 2번째 비트를 출력용으로 사용, 나머지는 입력
    */	
	
	DDRA |= 0x07; // PortA의 0,1,2번째 비트를 출력용으로 사용 (0x00, 0x01, 0x04)
	DDRB &= ~0x01; // PortB의 0번째 비트를 입력용으로 사용, 나머지는 그대로 유지
    int mode = 0; // mode1 : Red	mode2: Green	mode3 : Blue
    while (1) 
	{
		/*
		/ if(PINB & 0x01 ==1) // SW가 안눌렸을 때 : true
		if (!(PINB & 0x01 == 1))  // SW 눌렸을 때 : true
		{
		TogglePinA(0,_delay_T); // PortA의 0번째 비트를 점멸
 	    TogglePinA(1,_delay_T); // PortA의 1번째 비트를 점멸
 		TogglePinA(2,_delay_T); // PortA의 2번째 비트를 점멸
		}
		} 
		*/
		if (!(PINB & 0x01 == 1))  // SW 눌렸을 때 : true
		{ 	
			mode++;
				if (mode >=3) mode=0;
		}
		switch (mode)
		{
			case 0 : TogglePinA(0,_delay_T); // PortA의 0번째 비트를 점멸
			break;
			case 1 : TogglePinA(1,_delay_T); // PortA의 1번째 비트를 점멸
			break;
			case 2 : TogglePinA(2,_delay_T); // PortA의 2번째 비트를 점멸
			break;
			default : mode=0;
			} 
				/* if (mode==1)
				{
					TogglePinA(0,_delay_T); // PortA의 0번째 비트를 점멸
				}
				else if (mode==2)
				{
			 	    TogglePinA(1,_delay_T); // PortA의 1번째 비트를 점멸
				}
				else if (mode==3)
				{
			 		TogglePinA(2,_delay_T); // PortA의 2번째 비트를 점멸
				} 
	*/
		/* PORTA |= 0x01; // PortA의 0번째 비트를 HIGH로 출력
		_delay_ms(500);
		PORTA &= ~0x01; // PortA의 0번째 비트를 LOW로 출력
		_delay_ms(500);
		PORTA |= 0x02; // PortA의 1번째 비트를 HIGH로 출력
		_delay_ms(500);
		PORTA &= ~0x02; // PortA의 1번째 비트를 LOW로 출력
		_delay_ms(500);
		PORTA |= 0x04; // PortA의 2번째 비트를 HIGH로 출력
		_delay_ms(500);
		PORTA &= ~0x04; // PortA의 2번째 비트를 LOW로 출력
		
		PORTA |= 0x04 1로 출력
		PORTA &= ~0x04 0으로 출력
        */
				}
}


