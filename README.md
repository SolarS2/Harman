## 오늘 배운 내용 - 2024 03.22 
## 7-segment

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{ uint8_t numbers[] ={0x3F, 0x06, 0x5B,0x4F,0x66,0x6D, 0x7D,0x27, 0x7F,0x67, 0x77, 0x7C, 0x58, 0x5E, 0x79,0x71};
	// uint8_t nubers[] = {0x77, 0x7C, 0x58, 0x5E, 0x79,0x71,0x67, 0x76, 0x06,0x1E}; // 영어 알파벳
    int i, j;
	int mode = 0;
	DDRD = 0xFF; // 세그먼트 제어 핀 8개를 출력으로 설정
	DDRC = 0x0F; // 자릿수 선택 핀 4개를 출력으로 설정
 
 while (1) 
 {
    for (i=0; i<4; i++)
		{
			PORTC |= 0x0F;
			PORTC &=~(1<<(3-i));
   for (j=0; j<16; j++)
			{
			PORTD = numbers[j];
			_delay_ms(100);
			}
		}
	}
 return 0;
}
